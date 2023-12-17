#include "../Header/variable.h"

map<unsigned long long, int> PointScoreMap;
unsigned long long PointKey[16][3];
default_random_engine e;
Image Background = LoadImage(R"(C:\Users\scanffer\CLionProjects\Gobang_2\Gobang_board.png)");
Texture tBackground;   //图片加载进纹理
bool IsGameStarted = 0;  //游戏是否开始
Color PlayerColor, AiColor;   //双方棋子的颜色
int AiTurn, PlayerTurn;    //双方回合数的奇偶性
int Round = 1;         //游戏回合数
int board[17][17] = {0};   //棋盘状况
int limit = 10;

Point SeatedList[250];//已经下的子
int NumOfSeated = 0;  //已经下的子的个数
int score[3];     //score[1]白子分 score[2]黑子分 score[0] 电脑得分减去玩家得分
int NumOfRowSeated[16] = {0}, NumOfColumnSeated[16] = {0};
int NumOfLeftSeated[30] = {0}, NumOfRightSeated[30] = {0};  //分别记录有子的行、列、斜行