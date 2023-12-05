#include "../Header/scrap.h"

int Win() {
    return abs(score[0]) >= 10000;
}

void PlacePoint(Point a) {//放下棋子
    int x = a.x, y = a.y;
    SeatedList[++NumOfSeated] = a;
    board[y][x] = a.color.r ? 1 : 2;
    NumOfRowSeated[y]++, NumOfColumnSeated[x]++;
    NumOfLeftSeated[x + y - 1]++, NumOfRightSeated[16 - x + y - 1]++;
}

void TakePoint(Point a) {//拿起棋子
    int x = a.x, y = a.y;
    NumOfSeated--;
    board[y][x] = 0;
    NumOfRowSeated[y]--, NumOfColumnSeated[x]--;
    NumOfLeftSeated[x + y - 1]--, NumOfRightSeated[16 - x + y - 1]--;
}