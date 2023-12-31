#include "../Header/evaluate.h"

void evaluate() {
    if (ZobristValue.find(BoardKey) != ZobristValue.end()) {
        score[0] = ZobristValue[BoardKey];
        return;
    }
    score[0] = score[1] = score[2] = 0;
    int line[18];
    for (int i = 1; i <= 15; i++) { //行
        if (!NumOfRowSeated[i])continue;//该行无子即跳过
        for (int j = 1; j <= 15; j++) {
            line[j] = board[i][j];
        }
        LineEvaluate(line, 15, 1);
        LineEvaluate(line, 15, 2);
    }

    for (int i = 1; i <= 15; i++) {//列
        if (!NumOfColumnSeated[i])continue;
        for (int j = 1; j <= 15; j++) {
            line[j] = board[j][i];
        }
        LineEvaluate(line, 15, 1);
        LineEvaluate(line, 15, 2);
    }

    for (int i = 5; i <= 25; i++) {//斜左下行，由于前后四行的评估无意义，只评估5到25行 x+y-1=i
        if (!NumOfLeftSeated[i])continue;
        int length = 15 - abs(15 - i);    //这行的格子数量
        int x = i <= 15 ? i : 15, y = i + 1 - x;
        for (int j = 1; j <= length; j++) {
            line[j] = board[y + (j - 1)][x - (j - 1)];
        }
        LineEvaluate(line, length, 1);
        LineEvaluate(line, length, 2);
    }

    for (int i = 5; i <= 25; i++) { //斜右下行 其余同理 (16-x)+y-1=i
        if (!NumOfRightSeated[i])continue;
        int length = 15 - abs(15 - i);
        int x = i <= 15 ? 16 - i : 1, y = i + 1 - (16 - x);
        for (int j = 1; j <= length; j++) {
            line[j] = board[y + (j - 1)][x + (j - 1)];
        }
        LineEvaluate(line, length, 1);
        LineEvaluate(line, length, 2);
    }
    int AiSide = AiColor.r ? 1 : 2;
    score[0] = score[AiSide] - score[3 - AiSide];  //计算评分
    ZobristValue[BoardKey] = score[0];
}

void LineEvaluate(const int *k, int length, int color) {
    int index = 0;
    int line[18];
    for (int i = 1; i <= length; i++) {
        int head, tail, IsHeadBlocked, IsTailBlocked;
        if (k[i] == color && !index) {//记录 一串同色棋子第一个的位置
            index = i;
            head = -1, tail = -1, IsHeadBlocked = 0, IsTailBlocked = 0;
            if (index == 1) {
                head = 0, IsHeadBlocked = 1;
            }
            if (k[index - 1] == 3 - color) {
                head = index - 1;
            }
            if (k[index - 1] == 0) {
                head = index - 2;
                if (index - 2 == 0) {
                    IsHeadBlocked = 1;
                }
            }
        }
        if (k[i] == 3 - color && index) { //2
            tail = i;
            int cnt = 0;
            for (int j = head; j <= tail; j++) {
                line[cnt++] = k[j];
            }
            if (IsHeadBlocked) {
                line[0] = 3 - color;
            }
            unsigned long long key = 0;
            for (int j = 0; j < cnt; j++) {
                key ^= PointKey[j][line[j]];
            }
            score[color] += PointScoreMap[key];
            index = 0;
        }
        if (k[i] == 0 && index) {
            if (k[i + 1] == color)continue;
            tail = i + 1;
            if (i == length) {
                IsTailBlocked = 1;
            }
            int cnt = 0;
            for (int j = head; j <= tail; j++) {
                line[cnt++] = k[j];
            }
            if (IsHeadBlocked) {
                line[0] = 3 - color;
            }
            if (IsTailBlocked) {
                line[cnt - 1] = 3 - color;
            }
            unsigned long long key = 0;
            for (int j = 0; j < cnt; j++) {
                key ^= PointKey[j][line[j]];
            }
            if (PointScoreMap.find(key) != PointScoreMap.end()) {
                score[color] += PointScoreMap[key];
            }

            index = 0;
        }
    }
}