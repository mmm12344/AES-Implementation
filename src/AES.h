#pragma once
#include <string>
#include <vector>

int AESEncyptHextoHex(char* key, char* hexValue, int size, char* encryptedHex);

int AESEncryptTexttoHex(char* key, char* textValue, int size, char* encryptedHex);

int AESDecryptHexToHex(char* key, char* hexValue, int size, char* decryptedHex);

int AESDecryptHexToText(char* key, char* hexValue, int size, char* decryptedTex);