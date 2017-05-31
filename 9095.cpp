//
// Created by 오민호 on 2017. 5. 31..
//

#include <cstdio>
#include <cstring>

int dp[11];
int t = 0;

int main() {
    scanf("%d",&t);
    for(int i = 0 ; i < t ; ++i) {
        int N;
        scanf("%d", &N);
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int j = 4 ; j <= N ; ++j)
            dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
        printf("%d\n",dp[N]);
    }
}