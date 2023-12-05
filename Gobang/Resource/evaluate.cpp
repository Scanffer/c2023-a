#include "../Header/evaluate.h"

void evaluate() {
    unsigned long long key = GetBoardKey();
    if (ZobristValue.find(key) != ZobristValue.end()) {
        score[0] = ZobristValue[key];
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
    ZobristValue[key] = score[0];
}

void LineEvaluate(int *k, int length, int color) {
    int Index = 0;
    for (int i = 1; i <= length + 1; i++) {
        if (k[i] == color && !Index) {//记录一下 一串同色棋子第一个的位置
            Index = i;
        }
        if (k[i] != color && Index) {//一串同色棋子结束 开始计分
            int ScoreCount = i - Index;
            if (ScoreCount == 5) {//连成五子就不用判断左右隔断问题了
                score[color] += 100000;
                Index = 0;
                continue;
            }
            int left = 0, right = 0;
            if (k[Index - 1] == (color ^ 3) || Index - 1 == 0) {    // 10^11=01 01^11=10
                left = 1;                          //看左侧是否有隔断
            }
            if (k[i] == (color ^ 3) || i == length + 1) {
                right = 1;              //此处是否隔断
            }
            if (left + right <= 1) {    //如果不是两侧都隔断
                ScoreCount -= (left + right);   //减去隔断的分
            } else {
                ScoreCount = 0;     //如果两侧都隔断，这串同色棋子就失去意义，不计分
            }
            score[color] += pow(10, ScoreCount);
            Index = 0;
        }
    }
}