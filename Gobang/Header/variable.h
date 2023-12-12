#ifndef GOBANG_VARIABLE_H
#define GOBANG_VARIABLE_H

#include<raylib.h>


extern Image Background;
extern Texture tBackground;
struct Point {
    int x;
    int y;
    Color color;  //棋子信息
};
extern bool IsGameStarted;  //游戏是否开始
extern Color PlayerColor, AiColor;   //双方棋子的颜色
extern int AiTurn, PlayerTurn;    //双方回合数的奇偶性
extern int Round;         //游戏回合数
extern int board[17][17];   //棋盘状况

extern Point SeatedList[250];//已经下的子
extern int NumOfSeated;  //已经下的子的个数
extern int score[3];     //score[1]白子分 score[2]黑子分 score[0] 电脑得分减去玩家得分
extern int NumOfRowSeated[16], NumOfColumnSeated[16];
extern int NumOfLeftSeated[30], NumOfRightSeated[30];  //分别记录有子的行、列、斜行
#endif //GOBANG_VARIABLE_H
