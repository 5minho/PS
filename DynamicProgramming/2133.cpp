//
// Created by 오민호 on 2017. 6. 21..
//

#include <iostream>
const int max = 31;

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int dp[max] = {1, 0, 3, 0};
    for(int i = 4 ; i <= n ; i += 2) {
        dp[i] += (3 * dp[i - 2]);
        for(int j = 4 ; j <= i ; j += 2)
            dp[i] += (2 * dp[j - 4]);
    }
    std::cout << dp[n];
}