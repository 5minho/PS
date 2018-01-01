//
// Created by 오민호 on 2018. 1. 1..
//

#include <iostream>

int main() {

    long long i,j;
    std::cin >> i >> j;
    if (i > j) { std::swap(i, j); }
    long long ans = (j - i + 1) * (i + j) / 2l;
    std::cout << ans;

}