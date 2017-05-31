//
// Created by 오민호 on 2017. 5. 31..
//

#include <cstdio>



int main() {
    unsigned long long dp[91] = {0, 1, 1, 2};
    int n;
    scanf("%d",&n);
    for(int i = 3 ; i <= n ; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    printf("%lld",dp[n]);
}