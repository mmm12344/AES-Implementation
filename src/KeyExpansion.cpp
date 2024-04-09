#include "KeyExpansion.h"
#include "constants.h"

void RotateWord(std::vector<std::vector<char>> key){
    int size = key.size();
    for(int i = 0; i < size-1; i++){
        std::swap(key[i][size-1], key[i+1][size-1]);
    }
}

void SubWord(std::vector<std::vector<char>> key){
    int size = key.size();
    for(int i = 0; i < size; i++){
        key[i][size-1] = sBox[key[i][size-1]];
    }
}

void RoundConstant(std::vector<std::vector<char>> key, int roundNum){
    int size = key.size();
    key[0][size-1] = rcon[roundNum];
}

std::vector<std::vector<std::vector<char>>> ExpandKey(std::vector<std::vector<char>> key){
    std::vector<std::vector<std::vector<char>>> expandedKey;
    std::vector<std::vector<char>> tmpKey(key);
    for(int i = 0; i < 10; i++){
        RotateWord(tmpKey);
        SubWord(tmpKey);
        RoundConstant(tmpKey, i+1);
        expandedKey[i] = tmpKey;
    }
    return expandedKey;
}