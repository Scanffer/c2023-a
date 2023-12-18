#include "../Header/hash.h"

unsigned long long ZobristKey[3][16][16];
std::map<unsigned long long, int> ZobristValue;
unsigned long long BoardKey = 0;

map<unsigned long long, int> PointScoreMap;
unsigned long long PointKey[16][3];

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

void LoadPointScoreMap() {
    FILE *fp;
    fp = fopen("hash", "r");
    char text[20] = {0};
    int mark;
    for (int i = 0; i <= 15; i++) {
        for (int j = 0; j <= 2; j++) {
            unsigned long long num = 1 + e() % ULONG_LONG_MAX;
            PointKey[i][j] = num;
        }
    }
    for (int i = 1; i <= 576; i++) {
        fscanf(fp, "%s %d\n", text, &mark);
        mark = (int) pow(10, mark);
        unsigned long long key = 0;
        for (int j = 0;; j++) {
            if (text[j] == 0)break;
            key ^= PointKey[j][text[j] - '0'];
        }
        PointScoreMap[key] = mark;
    }
}