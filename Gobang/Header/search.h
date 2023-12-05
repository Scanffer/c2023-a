#ifndef GOBANG_SEARCH_H
#define GOBANG_SEARCH_H

#include <iostream>
#include "../Header/search.h"
#include "../Header/evaluate.h"
#include"../Header/generator.h"
#include"../Header/scrap.h"

void MaxMin(int deep);

int Min(int deep, int alpha, int beta);

int Max(int deep, int alpha, int beta);

#endif //GOBANG_SEARCH_H
