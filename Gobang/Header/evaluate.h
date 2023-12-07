#ifndef GOBANG_EVALUATE_H
#define GOBANG_EVALUATE_H

#include<cmath>
#include "variable.h"
#include "zobrist.h"

void evaluate();

void LineEvaluate(int *k, int length, int color);

#endif //GOBANG_EVALUATE_H
