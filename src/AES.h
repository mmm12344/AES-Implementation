#pragma once
#include <string>
#include <vector>
#include "KeyExpansion.h"

int AESEncyptHextoHex(unsigned char* key, unsigned char* hexValue, unsigned char* encryptedHex);

int AESEncryptTexttoHex(char* key, char* textValue,unsigned char* encryptedHex);

int AESDecryptHexToHex(unsigned char* key, unsigned char* hexValue, unsigned char* decryptedHex);

int AESDecryptHexToText(unsigned char* key, unsigned char* hexValue, char* decryptedTex);