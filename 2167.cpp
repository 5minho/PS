//
// Created by 오민호 on 2017. 6. 8..
//

#include <cstdio>
const int MAX = 301;
int dp[MAX][MAX];
int N,M;
int K;
int main() {
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N ; ++i)
        for(int j = 1 ; j <= M ; ++j) {
            int tmp;
            scanf("%d", &tmp);
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + tmp;
        }
    scanf("%d",&K);
    while(K--) {
        int i, j, x, y;
        scanf("%d%d%d%d",&i,&j,&x,&y);
        printf("%d\n",dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1]);
    }
}