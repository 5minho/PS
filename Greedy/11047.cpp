//
// Created by 오민호 on 2017. 9. 19..
//

#include <iostream>
#include <vector>

int main() {

    int N, K;
    std::cin >> N >> K;

    std::vector<int> coins(N);

    for(int i = N - 1 ; i >= 0 ; --i)
        std::cin >> coins[i];

    int ans = 0;

    for (auto coin : coins) {

        ans += (K / coin);
        K %= coin;

    }

    std::cout << ans << "\n";
    return 0;
}