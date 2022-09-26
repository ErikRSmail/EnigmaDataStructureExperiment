#include<iostream>
#include<string>
#include"Settings.h"
#include"Enigma.h"

int main(){
    Enigma enigma(&settings);
    std::string plaintext = "edpudnrgyszrcxnuytpomrmbofktbzrezkmlxlvefgueysiozveqmikubpmmylklttdeismdicagykuactcdomohwxmuuiaubstslrnbzszwnrfxwfyssxjzvijhidishprklkayupadtxqspinqmatlpifsvkdasctacdpbopvhjk";
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::string ciphertext = enigma.encrypt(plaintext);
    std::cout << "Ciphertext: " << ciphertext << std::endl;
}