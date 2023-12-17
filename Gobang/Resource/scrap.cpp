#include "../Header/scrap.h"

int Win() {
    return abs(score[0]) >= 80000;
}

void PlacePoint(Point a) {//放下棋子
    int x = a.x, y = a.y, color = a.color.r ? 1 : 2;
    SeatedList[++NumOfSeated] = a;
    board[y][x] = color;
    NumOfRowSeated[y]++, NumOfColumnSeated[x]++;
    NumOfLeftSeated[x + y - 1]++, NumOfRightSeated[16 - x + y - 1]++;
    BoardKey ^= ZobristKey[0][y][x], BoardKey ^= ZobristKey[color][y][x];
}

void TakePoint(Point a) {//拿起棋子
    int x = a.x, y = a.y, color = a.color.r ? 1 : 2;
    NumOfSeated--;
    board[y][x] = 0;
    NumOfRowSeated[y]--, NumOfColumnSeated[x]--;
    NumOfLeftSeated[x + y - 1]--, NumOfRightSeated[16 - x + y - 1]--;
    BoardKey ^= ZobristKey[color][y][x], BoardKey ^= ZobristKey[0][y][x];
}