//
// Created by 오민호 on 2017. 6. 13..
//

#include <iostream>

const int MAX = 1001;
int p[MAX];

int main() {
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    for(int i = 1 ; i <= N ; ++i)
        std::cin >> p[i];
    int ans = 0;
    for(int i = 1 ; i <= N ; ++i)
        for(int j = 1 ; j <= i/2 ; ++j) {
            p[i] = std::max(p[i], p[i - j] + p[j]);
        }
    std::cout << p[N];
}