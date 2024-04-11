#include <vector>
#include "constants.h"
#include <iostream>

void RotateWord(unsigned char* key){
    for(int i = 0; i < 3; i++){
        std::swap(key[i+1], key[i]);
    }
}

void SubWord(unsigned char* key){
    for(int i = 0; i < 4; i++){
        key[i] = sBox[key[i]];
    }
}

void RoundConstant(unsigned char* key, int roundNum){
    key[0] ^= rcon[roundNum];
}

void AddRoundKey(unsigned char* lastKey, unsigned char* currentKey, unsigned char* word){
    for(int i = 0; i < 4; i++){
        currentKey[i] = lastKey[i] ^ word[i];
    }
    for(int i = 4; i < 16; i++){
        currentKey[i] = currentKey[i-4] ^ lastKey[i];
    }
}

std::vector<unsigned char*> ExpandKey(unsigned char* key){

    std::vector<unsigned char*> result;
    result.resize(11);
    for(int i = 0; i < 11; i++){
        result[i] = new unsigned char[16];
    }
    for(int i = 0; i < 16; i++){
        result[0][i] = key[i];
    }
    for(int i = 0; i < 10; i++){
        unsigned char word[4] = {result[i][12], result[i][13], result[i][14], result[i][15]};
        RotateWord(word);
        SubWord(word);
        RoundConstant(word, i+1);
        AddRoundKey(result[i], result[i+1], word);
    }
    return result;
}