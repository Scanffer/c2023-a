#ifndef C2023_CHALLENGE_HASH_H
#define C2023_CHALLENGE_HASH_H

#include<random>
#include<ctime>
#include<iostream>
#include<map>
#include"variable.h"

extern unsigned long long ZobristKey[3][20][20];
extern std::map<unsigned long long, int> ZobristValue;
extern unsigned long long BoardKey;

extern std::map<unsigned long long, int> PointScoreMap;
extern unsigned long long PointKey[20][3];

void LoadPointScoreMap();

void SetZobrist();

#endif //C2023_CHALLENGE_HASH_H
