#ifndef GOBANG_SEARCH_H
#define GOBANG_SEARCH_H

#include <iostream>
#include "search.h"
#include "evaluate.h"
#include"generator.h"
#include"scrap.h"

void MaxMin(int deep);

int Min(int deep, int alpha, int beta);

int Max(int deep, int alpha, int beta);

#endif //GOBANG_SEARCH_H
