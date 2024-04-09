#include "AES.h"
#include "constants.h"


std::vector<std::vector<char>> HexArrayToMatrix(char* hexArray, int size){
    std::vector<std::vector<char>> matrix;
    size = size/2;
    matrix.resize(size);

    for(int i = 0; i < size; i++){
        matrix[i].resize(size);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 32; j+=2){
            matrix[i][j] = hexArray[(i+1)*j] + hexArray[(i+1)*j+1];
        }
    }
    return matrix;
}

int HexMatrixToArray(std::vector<std::vector<char>> hexMatrix, char* hexArray){
    int size = hexMatrix.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            hexArray[(i+1) * j] = hexMatrix[i][j]; 
        }
    }
}

int FlipMatrix(std::vector<std::vector<char>> hexMatrix){
    
    int size = hexMatrix.size();
    for(int i = 0; i < size; i++){
        for(int j = i; i < size; i++){
            std::swap(hexMatrix[i][j], hexMatrix[j][i]);
        }
    }

}


int AESEncyptHextoHex(char* key, char* hexValue, int size, char* encryptedHex){
    std::vector<std::vector<char>> hexMatrix = HexArrayToMatrix(hexValue, size);
    FlipMatrix(hexMatrix);



}



