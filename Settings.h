//This just exists to organize inputs for the Enigma constructor
struct Settings{
    //These determine which rotors you use, and where they are slotted into the machine
    uint8_t leftRotor = 2; //1=I, 2=II,...
    uint8_t middleRotor = 4;
    uint8_t rightRotor = 5;
    //These determine the position of the ring relative to the entrance wheel
    uint8_t leftWindow = 1;//0-25 here is like A-Z on the real machines
    uint8_t middleWindow = 11;
    uint8_t rightWindow = 0;
    //These determine the position of the core relative to the ring and turnover notches
    uint8_t leftRingSetting = 1;//0-25 here is like 1-26 on the real machines
    uint8_t middleRingSetting = 20;
    uint8_t rightRingSetting = 11;
    //This determines which reflector is used
    uint8_t reflector = 1; //0=A,1=B,2=C
    //This string determines which letters are paired on the plugboard. 
    std::string plugs = "avbscgdlfuhzinkmowrx";//plugs[0] and plugs[1] are paired, as are 2 and 3, 4 and 5,,,
}settings;