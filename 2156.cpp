//
// Created by 오민호 on 2017. 5. 26..
//

#include <cstdio>
#include <algorithm>

const int MAX = 10000;
int glass[MAX];
int dp[MAX];
int n = 0;

int main() {
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d", &glass[i]);
    dp[0] = glass[0];
    dp[1] = glass[1] + glass[0];
    dp[2] = std::max(std::max(glass[1] + glass[2], dp[1]), dp[0] + glass[2]);
    for(int i = 3 ; i < n ; ++i)
        dp[i] = std::max(std::max(dp[i - 3] + glass[i - 1] + glass[i], dp[i - 1]), dp[i - 2] + glass[i]);
    printf("%d\n",dp[n - 1]);
    return 0;
}