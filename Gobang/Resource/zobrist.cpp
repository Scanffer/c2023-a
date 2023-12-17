#include "../Header/zobrist.h"

unsigned long long ZobristKey[3][16][16];
std::map<unsigned long long, int> ZobristValue;
unsigned long long BoardKey = 0;

void SetZobrist() {
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            for (int k = 0; k <= 2; k++) {
                unsigned long long num = 1 + e() % ULONG_LONG_MAX;
                ZobristKey[k][i][j] = num;
            }
        }
    }
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            BoardKey ^= ZobristKey[0][i][j];
        }
    }
    ZobristValue[BoardKey] = 0;
}
