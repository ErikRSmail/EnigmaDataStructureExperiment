struct RightRotorWire;
struct MidRotorWire;
struct LeftRotorWire;
struct Plug;

struct RightRotorWire{
    RightRotorWire *down;
    MidRotorWire *left;
    Plug *right;
};
struct MidRotorWire{
    MidRotorWire *down;
    RightRotorWire *right;
    LeftRotorWire *left;
};
struct LeftRotorWire{
    LeftRotorWire *down;
    MidRotorWire *right;
    LeftRotorWire *left;//Janky,but rather than write a ReflectorWire struct im just going to have the wires of the left rotor point at themselves. So no ReflectorWire.
};
struct Plug{
    char outLetter;
    RightRotorWire *left;
};

class Enigma{
    Plug in[26];
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
    updateRotors();//must be called before the encryption process takes place
    //since text is a copy we just permute and eventually return it
    for (int i = 0; i < text.length(); i++){
        //maps an ascii char a thru z ascii to an int 0 thru 25. 
        uint8_t inPos = text[i]-97;
        //text[i] = in[inPos].left.left.left.left.right.right.right.outLetter;//
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
    //actually setting up this data structure is accomplished with magic.
}

void Enigma::updateRotors(){
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