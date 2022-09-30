struct Rotor{
    std::string wiring;
    int notch1;
    int notch2;
    Rotor(std::string,bool);
    Rotor(std::string,int);
};
Rotor::Rotor(std::string wiringParam,bool naval){
    wiring=wiringParam;
    notch1=12;//M
    notch2=25;//Z
}
Rotor::Rotor(std::string wiringParam, int notchParam){
    wiring=wiringParam;
    notch1=notchParam;
    notch2=-1;//if we see -1 as a notch2 setting we know we have a non-navy rotor and should ignore this setting
}
Rotor I("EKMFLGDQVZNTOWYHXUSPAIBRCJ",16);
Rotor II("AJDKSIRUXBLHWTMCQGZNPYFVOE",4);
Rotor III("BDFHJLCPRTXVZNYEIWGAKMUSQO",21);
Rotor IV("ESOVPZJAYQUIRHXLNFTGKDCMWB",9);
Rotor V("VZBRGITYUPSDNHLXAWMJQOFECK",25);
//Rotor VI("JPGVOUMFYQBENHZRDKASXLICTW",true);
//Rotor VII("NZJHGRCXMYSWBOUFAIVLPEKQDT",true);
//Rotor VIII("FKQHTLXOCBJSPDZRAMEWNIUYGV",true);