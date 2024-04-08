#pragma once
#include <string>
#include <vector>

int AESEncyptHextoHex(char* key, char* hexValue, char* encryptedHex);

int AESEncryptTexttoHex(char* key, char* textValue, char* encryptedHex);

int AESDecryptHexToHex(char* key, char* hexValue, char* decryptedHex);

int AESDecryptHexToText(char* key, char* hexValue, char* decryptedTex);