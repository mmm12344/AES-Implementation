#pragma once

int AESEncyptBinary(const char* key, const char* in, const char* out);

int AESEncryptText(const char* key, const char* in, const char* out);

int AESDecryptBinaryToBinary(const char* key, const char* in, const char* out);

int AESDecryptBinaryToText(const char* key, const char* in, const char* out);