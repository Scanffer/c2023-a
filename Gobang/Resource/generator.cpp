#include "../Header/generator.h"
int PointScoreCount(Point a, int color) {
    int result = 0;
    int x_to[5] = {0, -1, 0, 1, 1};
    int y_to[5] = {0, -1, -1, -1, 0};
    int x = a.x, y = a.y;
    int head, tail;
    for (int i = 1; i <= 4; i++) {
        int IsHeadBlocked = 0, IsTailBlocked = 0;
        for (int j = 1;; j++) {
            int nx = x + j * x_to[i], ny = y + j * y_to[i];
            if (nx * ny <= 0 || nx > 15 || ny > 15 || board[ny][nx] == 3 - color) {
                IsHeadBlocked = 1;
                head = j - 1;
                break;
            }
            if (board[ny][nx] == 0) {
                head = j - 1;
                break;
            }
        }
        for (int j = 1;; j++) {
            int nx = x - j * x_to[i], ny = y - j * y_to[i];
            if (nx * ny <= 0 || nx > 15 || ny > 15 || board[ny][nx] == 3 - color) {
                IsTailBlocked = 1;
                tail = j - 1;
                break;
            }
            if (board[ny][nx] == 0) {
                tail = j - 1;
                break;
            }
        }
        if (head + tail + 1 == 5) {
            result += 100000;
            continue;
        }
        if (IsHeadBlocked + IsTailBlocked < 2) {
            result += pow(10, head + tail + 1 - IsHeadBlocked - IsTailBlocked);
        }
    }
    return result;
}

int x_way[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int y_way[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};

pair<Point *, int> PlaceGenerate(int color) {
    if (NumOfSeated == 0) {
        int cnt = 1;
        auto p = (Point *) malloc(20 * sizeof(Point));
        p[1] = {8, 8};
        return {p, cnt};
    }
    int IsChosen[17][17] = {0}, IsInList[17][17] = {0};
    Point Kind[6][3][100] = {0}; //第一维 1五 2活四 3双三 4活三 5其他 第二维 1白色 2黑色
    int KindCnt[6][3] = {0}; //同上
    int PointScore[3] = {0};
    auto p = (Point *) malloc(200 * sizeof(Point));
    int cnt = 0;
    for (int i = 1; i <= NumOfSeated; i++) {
        int x = SeatedList[i].x, y = SeatedList[i].y;
        for (int j = 1; j <= 8; j++) {  //八个方向
            int nx = x + x_way[j], ny = y + y_way[j];
            if (board[ny][nx] || IsChosen[ny][nx])continue;
            if (ny * nx <= 0 || nx > 15 || ny > 15)continue;
            IsChosen[ny][nx] = 1;
            PointScore[1] = PointScoreCount({nx, ny}, 1);
            PointScore[2] = PointScoreCount({nx, ny}, 2);
            for (int k = 1; k <= 2; k++) {
                if (PointScore[k] >= 100000) {
                    Kind[1][k][++KindCnt[1][k]] = {nx, ny};
                } else if (PointScore[k] >= 10000) {
                    Kind[2][k][++KindCnt[2][k]] = {nx, ny};
                } else if (PointScore[k] >= 2000) {
                    Kind[3][k][++KindCnt[3][k]] = {nx, ny};
                } else if (PointScore[k] >= 1000) {
                    Kind[4][k][++KindCnt[4][k]] = {nx, ny};
                } else {
                    Kind[5][k][++KindCnt[5][k]] = {nx, ny};
                }
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        int j = color;
        for (int k = 1; k <= KindCnt[i][j]; k++) {
            int x = Kind[i][j][k].x, y = Kind[i][j][k].y;
            if (!IsInList[y][x]) {
                p[++cnt] = Kind[i][j][k];
                IsInList[y][x] = 1;
            }

        }
        j = 3 - color;
        for (int k = 1; k <= KindCnt[i][j]; k++) {
            int x = Kind[i][j][k].x, y = Kind[i][j][k].y;
            if (!IsInList[y][x]) {
                p[++cnt] = Kind[i][j][k];
                IsInList[y][x] = 1;
            }
        }
    }
    return pair{p, cnt};
}