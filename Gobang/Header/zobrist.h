#ifndef C2023_CHALLENGE_ZOBRIST_H
#define C2023_CHALLENGE_ZOBRIST_H

#include<random>
#include<ctime>
#include<iostream>
#include<map>
#include"../Header/variable.h"

extern unsigned long long ZobristKey[3][16][16];
extern std::map<unsigned long long, int> ZobristValue;

void SetZobrist();

unsigned long long GetBoardKey();

#endif //C2023_CHALLENGE_ZOBRIST_H
