//
// Created by 오민호 on 2017. 6. 25..
//

#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        int c = 0;
        do {
            if (n & 1) std::cout << c << " ";
            c++;
        } while (n = n >> 1);
    }
}