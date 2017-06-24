//
// Created by 오민호 on 2017. 6. 24..
//

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    int seq[3] = {0, 1, };
    for(int i = 2 ; i <= n ; ++i)
        seq[i % 3] = seq[(i - 1) % 3] + seq[(i - 2) % 3];
    std::cout << seq[n % 3];
}