#include "KeyExpansion.cpp"
#include <stdio.h>



void SubBytes(unsigned char* value){
    for(int i = 0; i < 16; i ++){
        value[i] = sBox[value[i]];
    }
}

void ShiftRows(unsigned char* value){
    for(int i = 1; i < 13; i += 4){
        std::swap(value[i], value[i+4]);
    }

    for(int i = 0; i < 2; i++){
        for(int j = 2; j < 14; j += 4){
            std::swap(value[j], value[j+4]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 3; j < 15; j += 4){
            std::swap(value[j], value[j+4]);
        }
    }
}

void MixColumns(unsigned char* value){
  
    for(int i = 0; i < 16; i+=4){
        unsigned char tmp[4];
        tmp[0] = mul2[ value[i] ] ^ mul3[ value[i + 1] ] ^  value[i + 2] ^ value[i + 3];
        tmp[1] = value[i] ^ mul2[ value[i + 1] ] ^ mul3[ value[i + 2] ] ^ value[i + 3];
        tmp[2] = value[i] ^ value[i + 1] ^  mul2[ value[i + 2] ] ^ mul3[ value[i + 3] ];
        tmp[3] = mul3[ value[i] ] ^ value[i + 1] ^  value[i + 2] ^ mul2[ value[i + 3] ];
        value[i] = tmp[0];
        value[i+1] = tmp[1];
        value[i+2] = tmp[2];
        value[i+3] = tmp[3];
    }

}


void AddRoundKey(unsigned char* value, unsigned char* key){
    for(int i = 0; i < 16; i++){
        value[i] ^= key[i];
    }
}

void AESEncyptHextoHex(unsigned char* key, unsigned char* hexValue, unsigned char* out){
    for(int i = 0; i < 16; i++){
        out[i] = hexValue[i];
    }
    std::vector<unsigned char*> expandedKeys = ExpandKey(key);
    AddRoundKey(out, expandedKeys[0]);
    for(int i = 1; i < 10; i ++){
        SubBytes(out);
        ShiftRows(out);
        MixColumns(out);
        AddRoundKey(out, expandedKeys[i]);
    }
    SubBytes(out);
    ShiftRows(out);
    AddRoundKey(out, expandedKeys[10]);
}



