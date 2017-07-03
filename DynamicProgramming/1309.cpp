//
// Created by 오민호 on 2017. 7. 4..
//

#include <iostream>

const int MOD = 9901;

int main() {
    int n;
    std::cin >> n;
    int dp[3];
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 2 ; i <= n ; ++i) {
        dp[i % 3] = dp[(i - 2) % 3] + 2 * dp[(i - 1) % 3];
        dp[i % 3] %= MOD;
    }
    std::cout << dp[n % 3];
}