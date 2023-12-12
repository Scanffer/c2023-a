#include "../Header/ui.h"

void MainPage() {
    while (!IsGameStarted && !WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Gobang Game!", 150, 250, 30, BLACK);
        DrawText("Press '1' to start with white\nPress '2' to start with black", 200, 300, 20, BLACK);
        DrawText("——by Scanffer", 400, 400, 15, BLACK);
        EndDrawing();
        if (IsKeyReleased(KEY_KP_1)) { //玩家白子 电脑黑子 电脑先走
            IsGameStarted = true;
            PlayerColor = WHITE, AiColor = BLACK;
            PlayerTurn = 0, AiTurn = 1;  // 表示双方对应轮数的奇偶性
        }
        if (IsKeyReleased(KEY_KP_2)) { //玩家黑子 电脑白子
            IsGameStarted = true;
            PlayerColor = BLACK, AiColor = WHITE;
            PlayerTurn = 1, AiTurn = 0;
        }
    }
}

void DrawBoard() {
    BeginDrawing();
    ClearBackground(GRAY);
    DrawTexture(tBackground, 0, 0, WHITE);
    for (int i = 1; i <= NumOfSeated; i++) {
        if (board[SeatedList[i].y][SeatedList[i].x]) {
            double x = 28.0 + (SeatedList[i].x - 1) * 42.2, y = 25.0 + (SeatedList[i].y - 1) * 42.2;
            DrawCircle(x, y, 14, SeatedList[i].color);   //画出已经下的子
        }
    }
    DrawCircle(28.0 + (SeatedList[NumOfSeated].x - 1) * 42.2, 25.0 + (SeatedList[NumOfSeated].y - 1) * 42.2, 3,
               SeatedList[NumOfSeated].color.r ? BLACK : WHITE);   //标记一下最后下的棋子
    EndDrawing();
}

bool IsMouseIn(int x, int y) { //判断鼠标是否在棋盘内
    if (x <= 17 || x >= 632)return false;
    if (y <= 17 || y >= 639)return false;
    return true;
}

Point MousePositionAdjust(int x, int y) {//确定和鼠标位置最近的格子
    x -= 28, y -= 25;
    Point position{};
    position.color = PlayerColor;
    position.x = 1 + x / 42 + (x % 42 > 42 / 2 ? 1 : 0);
    position.y = 1 + y / 42 + (y % 42 > 42 / 2 ? 1 : 0);
    return position;
}

void PlayerWork() {
    int x, y;
    Point AdjustedPoint{};
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {   //检测鼠标左键
        x = GetMouseX(), y = GetMouseY(); //获取鼠标坐标
        if (IsMouseIn(x, y)) {  //鼠标在棋盘内
            AdjustedPoint = MousePositionAdjust(x, y);
            x = AdjustedPoint.x, y = AdjustedPoint.y;
            AdjustedPoint.color = PlayerColor;
            if (board[y][x] == 0) {  //如果鼠标点击的位置是没有子的
                PlacePoint(AdjustedPoint);
                Round++;
            }
        }
    }
}