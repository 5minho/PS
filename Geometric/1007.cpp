//
// Created by 오민호 on 2017. 5. 5..
//

#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <cmath>

using namespace std;

typedef pair<int, int> point;
int T, N;
int sumX = 0, sumY = 0;
const long long INF = 9223372036854775807;
inline long long min (const long long& a, const long long& b) {
    return (a == INF) ? b : (a>b) ? b : a;
}


long long solve(int left, int index, long long x, long long y, vector<point>& points) {
    if(left == 0) {
        return (sumX - x - x) * (sumX - x - x) + (sumY - y - y) * (sumY - y - y);
    }
    long long ret = INF;
    for(;index < N; ++index) {
        ret = min(ret, solve(left - 1, index + 1 , x + points[index].first, y + points[index].second, points));
    }
    return ret;
}

int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        sumX = sumY = 0;
        vector<point> points;
        scanf("%d",&N);
        for(int j = 0 ; j < N ; ++j) {
            int x,y;
            scanf("%d %d",&x,&y);
            sumX += x;
            sumY += y;
            points.push_back(make_pair(x,y));
        }
        printf("%.6lf\n",sqrt((double)solve(N/2, 0, 0, 0, points)));
    }
    return 0;
}