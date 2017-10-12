//
// Created by 오민호 on 2017. 10. 12..
//

#include <iostream>
#include <cstring>

const int MAX = 1001;
const int NEGINF = -987654321;

int cache[3][MAX];
int N;
int stores[MAX];

int drink(int milk, int store) {

    if (store >= N)
        return NEGINF;

    if (store == N - 1)
        return (milk == stores[store]);

    int& ret = cache[milk][store];
    if (ret != -1)
        return ret;

    int nextMilk = (milk + 1) % 3;
    ret = (milk == stores[store]) ? std::max(drink(nextMilk, store + 1) + 1, drink(milk, store + 1)) : std::max(drink(milk, store + 1), ret);
    return ret;

}

int main() {
    memset(cache, -1, sizeof(cache));

    std::cin >> N;

    for(int i = 0 ; i < N ; ++i)
        std::cin >> stores[i];

    std::cout << drink(0, 0) << "\n";
    return 0;
}
