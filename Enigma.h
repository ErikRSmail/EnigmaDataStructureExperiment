struct RightRotorWire;
struct MidRotorWire;
struct LeftRotorWire;
struct Plug;

struct RightRotorWire{
    MidRotorWire *midRotorContact;
    Plug *out;
};
struct MidRotorWire{
    RightRotorWire *rightRotorContact;
    LeftRotorWire *leftRotorContact;
};
struct LeftRotorWire{
    MidRotorWire *MidRotorContact;
    LeftRotorWire *reflectedContact;//unintuitive,but rather than write a ReflectorWire struct im just going to have the wires of the left rotor point at themselves. So no ReflectorWire.
};
struct Plug{
    char outChar;
    RightRotorWire *in;
};

class Enigma{
    Plug plugs[26];
    RightRotorWire rightWires[26];
    MidRotorWire midWires[26];
    LeftRotorWire leftWires[26];
    uint8_t rightNotch = 0;
    uint8_t middleNotch = 0;
    uint8_t rightOffset = 0;
    uint8_t middleOffset = 0;
    uint8_t leftOffset = 0;
    bool shouldDoubleStep = false;
    void updateRotors();
    public:
    Enigma(Settings *settings);
    std::string encrypt(std::string text);
};

std::string Enigma::encrypt(std::string text){
    //since text is a copy we just permute and eventually return it
    for (int i = 0; i < text.length(); i++){
        updateRotors();//must be called before each letter encryption process takes place
        //maps an ascii char a thru z ascii to an int 0 thru 25, then follows our pointer chain.
        //This might work? will just give segfaults til data structure is actually set up, so commented for now.
        //text[i]= plugs[text[i]-97].in->midRotorContact->leftRotorContact->reflectedContact->MidRotorContact->rightRotorContact->out->outChar;
    }
    return text;
}

Enigma::Enigma(Settings *settings){
    //rightNotch = ;
    //middleNotch = ;
    //leftNotch = ;
    rightOffset = settings->rightWindow - settings->rightRingSetting;
    middleOffset = settings->middleWindow - settings->middleRingSetting;
    leftOffset = settings->leftWindow - settings->leftRingSetting;

    for(int i=0; i<26; i++){//plug setting logic
        plugs[i].outChar=i+97;//fills plugs 0-25 with a-z
        for(int j=0; j<settings->plugBoard.size();j++){//loop through plugboard pairs
            if(settings->plugBoard[j] == (i+65)){//if we are on plug x and find X in plugBoard
                if(j/2==0){//if j even, then pair current plug with next char in plugBoard
                    plugs[i].in = &rightWires[&settings->plugBoard[j+1]-65];
                }
                if(j/2){//if j odd, then pair current plug with previous char in plugBoard
                    plugs[i].in = &rightWires[&settings->plugBoard[j-1]-65];
                }
            }
            else{//if we found no matching letter in the plugboard we just wire straight across
                plugs[i].in = &rightWires[i];
            }
        }
    }
    
}

void Enigma::updateRotors(){//will track notch/offsets for M3 rotors only
    rightOffset++;
    if(rightOffset==rightNotch + 1){
        middleOffset++;
        if (middleOffset==middleNotch){
            shouldDoubleStep=true;
        }
        if(middleOffset==middleNotch + 1){
            leftOffset++;
        }
    }
    else if(shouldDoubleStep==true){
        middleOffset++;
        if(middleOffset==middleNotch + 1){
            leftOffset++;
        }
        shouldDoubleStep=false;
    }
    if(rightOffset>25){rightOffset = rightOffset - 26;}
    if(middleOffset>25){middleOffset = middleOffset - 26;}
    if(leftOffset>25){leftOffset = leftOffset - 26;}
}