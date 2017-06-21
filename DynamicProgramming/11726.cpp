//
// Created by 오민호 on 2017. 6. 21..
//

//
// Created by 오민호 on 2017. 5. 31..
//

#include <cstdio>

const int MOD = 10007;

int main() {
    int dp[1001] = {0, 1, 2, 3};
    int n;
    scanf("%d",&n);
    for(int i = 3 ; i <= n ; ++i)
        dp[i] = dp[i - 1] + dp[i - 2], dp[i] %= MOD;
    printf("%d",dp[n] % MOD);
}