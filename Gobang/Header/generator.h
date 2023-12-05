#ifndef GOBANG_GENERATOR_H
#define GOBANG_GENERATOR_H

#include<iostream>
#include"variable.h"
#include<cmath>
using namespace std;

int PointScoreCount(Point a, int color);

pair<Point *, int> PlaceGenerate(int color);

#endif //GOBANG_GENERATOR_H
