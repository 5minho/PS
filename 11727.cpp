//
// Created by 오민호 on 2017. 6. 10..
//

#include <iostream>

const int MOD = 10007;
const int MAX = 1001;
int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int dp[MAX] = {0, 1, 3};
    for(int i = 3 ; i <= n ; ++i)
        dp[i] = dp[i - 2] + dp[i - 2] + dp[i - 1] , dp[i] %= MOD;
    std::cout << dp[n] % MOD;
}