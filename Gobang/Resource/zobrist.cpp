#include "../Header/zobrist.h"

unsigned long long ZobristKey[3][16][16];
std::map<unsigned long long, int> ZobristValue;

void SetZobrist() {
    std::default_random_engine e;
    e.seed(e());
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            for (int k = 0; k <= 2; k++) {
                unsigned long long num = 1 + e() % ULONG_LONG_MAX;
                ZobristKey[k][i][j] = num;
            }
        }
    }
    unsigned long long key = 0;
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            key ^= ZobristKey[0][i][j];
        }
    }
    ZobristValue[key] = 0;
}

unsigned long long GetBoardKey() {
    unsigned long long key = 0;
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            key ^= ZobristKey[board[i][j]][i][j];
        }
    }
    return key;
}