//
// Created by 오민호 on 2017. 5. 31..
//

#include <cstdio>
#include <cstring>
int T = 0;

int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        int n,m;
        int dp[30][30];
        memset(dp, 0 , sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int j = 1 ; j <= m ; ++j)
            dp[1][j] = j;
        for(int j = 2 ; j <= n ; ++j)
            for(int k = j ; k <= m ; ++k)
                dp[j][k] = (j == k) ? 1 : dp[j - 1][k - 1] + dp[j][k - 1];
        printf("%d\n",dp[n][m]);
    }
}