#pragma once
#include <vector>

void RotateWord(unsigned char* key);


void SubWord(unsigned char* key);

void RoundConstant(unsigned char* key, int roundNum);



std::vector<unsigned char*> ExpandKey(unsigned char* key);