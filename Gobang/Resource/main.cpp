#include <iostream>
#include "../Header/ui.h"
#include "../Header/search.h"
//2023.11.18 遗留 PlaceGenerate函数未优化完毕(需要避免一个点多次被选入)
//2023.11.19 完成至alpha-beta剪枝 PlaceGenerate初步优化
//2023.11.19 遗留 搜索过程中对Win函数的处理有问题
//2023.11.20 启发式搜索 优化至一半 Win函数处理问题解决
//2023.11.28 启发式搜索优化完毕 2.0结束
//2023.11.29 试图将项目结构改为多文件而失败
//2023.12.2  成功将项目改为多文件结构
int main() {
    srand((unsigned) time(nullptr));
    InitWindow(647, 682, "Gobang Game");
    SetTargetFPS(60);
    tBackground = LoadTextureFromImage(Background);
    MainPage();
    while (!WindowShouldClose()) {
        DrawBoard(); //画棋盘和棋子
        if ((Round & 1) == AiTurn) {
            MaxMin(4);
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
