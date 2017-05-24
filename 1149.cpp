//
// Created by 오민호 on 2017. 5. 24..
//

#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAX = 1001;
const int INF = 987654321;
int n = 0;

int cost[MAX][3];
int cache[MAX][MAX];

// i번째 집을 color로 칠할 때 비용
int paint(int idx, int color) {
    int& ret = cache[idx][color];
    if(ret != -1) return ret;
    if(idx == 1) return cost[1][color];

    ret = INF;
    for(int nextColor = 0 ; nextColor < 3 ; ++nextColor) {
        if(nextColor == color) continue;
        ret = std::min(ret, paint(idx - 1, nextColor) + cost[idx][color]);
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);

    memset(cache, -1, sizeof(cache));
    int ans = INF;
    for(int color = 0 ; color < 3 ; ++color)
        ans = std::min(ans, paint(n, color));
    printf("%d\n",ans);
}