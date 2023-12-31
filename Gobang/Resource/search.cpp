#include"../Header/search.h"

Point BestPoint[50];
int BestCnt = 0;

void MaxMin(int deep) {
    auto PointPair = PlaceGenerate(AiColor.r ? 1 : 2);
    Point *p = PointPair.first;
    int cnt = PointPair.second;
    cnt = cnt > limit ? limit : cnt;
    int best = INT_MIN;
    for (int i = 1; i <= cnt; i++) { //博弈树的搜索
        Point a = p[i];
        a.color = AiColor;
        PlacePoint(a);
        if (a.x > 15 || a.y < 0)printf("error\n");
        int k = Min(deep - 1, INT_MAX, best);
        TakePoint(a);
        if (best == k) {
            BestPoint[++BestCnt] = a;
        }
        if (k > best) {
            best = k;
            BestCnt = 1;
            BestPoint[1] = a;
        }
    }
    PlacePoint(BestPoint[1 + (e() % BestCnt)]);
    Round++;   //回合数加一
    free(p);
}


int Min(int deep, int alpha, int beta) {
    evaluate();  //对局势评估
    if (deep <= 0 || Win()) {
        return score[0];
    }
    auto PointPair = PlaceGenerate(AiColor.r ? 2 : 1);
    Point *p = PointPair.first;
    int cnt = PointPair.second;
    cnt = cnt > limit ? limit : cnt;
    int best = INT_MAX;
    for (int i = 1; i <= cnt; i++) {
        Point a = p[i];
        a.color = PlayerColor;
        PlacePoint(a);
        int k = Max(deep - 1, best < alpha ? best : alpha, beta);
        TakePoint(a);
        if (k <= best)best = k;
        if (k < beta)break; //剪枝
    }
    free(p);
    return best;
}

int Max(int deep, int alpha, int beta) {
    evaluate();
    if (deep <= 0 || Win()) {
        return score[0];
    }
    auto PointPair = PlaceGenerate(AiColor.r ? 1 : 2);
    Point *p = PointPair.first;
    int cnt = PointPair.second;
    cnt = cnt > limit ? limit : cnt;
    int best = INT_MIN;
    for (int i = 1; i <= cnt; i++) {
        Point a = p[i];
        a.color = AiColor;
        PlacePoint(a);
        int k = Min(deep - 1, alpha, best > beta ? best : beta);
        TakePoint(a);
        if (k >= best)best = k;
        if (k > alpha)break;
    }
    free(p);
    return best;
}
