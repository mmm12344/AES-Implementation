#include "KeyExpansion.cpp"


int main(){
    unsigned char key[16] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    std::vector<unsigned char*> temp = ExpandKey(key);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 16; j++)
            std::cout << (int) temp[i][j] << ' ';
        std::cout << std::endl;
    }
    return 1;
}