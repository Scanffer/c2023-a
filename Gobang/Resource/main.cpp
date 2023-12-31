#include <iostream>
#include "../Header/ui.h"
#include "../Header/search.h"

#pragma GCC optimize(3)
//2023.11.18 遗留 PlaceGenerate函数未优化完毕(需要避免一个点多次被选入)
//2023.11.19 完成至alpha-beta剪枝 PlaceGenerate初步优化
//2023.11.19 遗留 搜索过程中对Win函数的处理有问题
//2023.11.20 启发式搜索 优化至一半 Win函数处理问题解决
//2023.11.28 启发式搜索优化完毕 2.0结束
//2023.11.29 试图将项目结构改为多文件而失败
//2023.12.2  成功将项目改为多文件结构
//2023.12.7  Zobrist模块加入 在O3优化的前提下，可....勉强进行6层搜索
//2023.12.12 release模式下可正常进行6层搜索  如若进一步在搜索过程中把搜索点个数限制在10个以内，可进行8层搜索
//2023.12.17 棋型hash打表完成，在总评估函数和单点评估方面加入了hash，项目结束开发（得期末复习了嘤嘤嘤）
int main() {
    e.seed(time(nullptr));
    SetZobrist();
    srand((unsigned) time(nullptr));
    LoadPointScoreMap();
    InitWindow(647, 682, "Gobang Game");
    SetTargetFPS(15);
    tBackground = LoadTextureFromImage(Background);
    MainPage();
    if (!IsGameStarted)return 0;
    while (!WindowShouldClose()) {
        DrawBoard(); //画棋盘和棋子
        if ((Round & 1) == AiTurn) {
            MaxMin(8);
            continue;
        }
        if ((Round & 1) == PlayerTurn) {
            PlayerWork();
            continue;
        }//双方走棋
    }
    CloseWindow();
    UnloadTexture(tBackground);
    UnloadImage(Background);
}
