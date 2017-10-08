//
// Created by 오민호 on 2017. 7. 4..
//

#include <iostream>
#include <vector>
#include <cstring>

const int INF = 987654321;
const int nMAX = 123;
const int kMAX = 30000;

int n, k;

int cache[kMAX];
int coins[nMAX];

// value 만큼 만드는데 필요한 최소 동전 수
int minimumCoins(int value) {

    // 기저사례
    if (value < 0) return INF;

    int& ret = cache[value];

    if (ret != -1)
        return ret;

    ret = INF;

    for(int i = 0 ; i < n ; ++i)
        ret = std::min(ret, minimumCoins(value - coins[i]) + 1);

    return ret;
}


int main() {

    std::ios::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    std::cin >> n >> k;

    for (int i = 0 ; i < n ; ++i)
        std::cin >> coins[i], cache[coins[i]] = 1;

    int ans = INF;

    for(int i = 0 ; i < n ; ++i)
        ans = std::min(ans, minimumCoins(k - coins[i]) + 1);

    (ans == INF) ? std::cout << "-1" << "\n" : std::cout << ans << "\n";

    return 0;

}