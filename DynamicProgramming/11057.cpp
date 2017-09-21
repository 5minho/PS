//
// Created by 오민호 on 2017. 9. 21..
//

#include <iostream>
#include <vector>

const int MOD = 10007;

int main() {

    int N;
    std::cin >> N;
    std::vector<std::vector<int>> cache(N + 2, std::vector<int>(11));

    for(int i = 0 ; i < 10 ; ++i)
        cache[1][i] = 1, cache[2][0] += cache[1][i];

    for(int i = 2 ; i <= N ; ++i) {
        cache[i + 1][0] += cache[i][0] % MOD;

        for(int j = 1 ; j < 10 ; ++j) {

            cache[i][j] = (cache[i][j - 1] + MOD - cache[i - 1][j - 1]) % MOD;
            cache[i + 1][0] += cache[i][j] % MOD;
        }

    }

    std::cout << cache[N + 1][0] % MOD << "\n";

}