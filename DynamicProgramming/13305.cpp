//
// Created by 오민호 on 2017. 10. 15..
//

#include <iostream>

const int maxCity = 100001;

int N;
int length[maxCity];
int cityCost[maxCity];

int main() {
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for(int i = 0 ; i < N - 1; ++i)
        std::cin >> length[i];
    for(int i = 0 ; i < N ; ++i)
        std::cin >> cityCost[i];

    int minCost = cityCost[0];
    long long sum = 0;

    for(int i = 0 ; i < N - 1 ; ++i) {
        minCost = std::min(minCost, cityCost[i]);
        sum += 1LL * minCost * length[i];
    }

    std::cout << sum;
    return 0;
}