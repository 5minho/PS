//
// Created by 오민호 on 2017. 6. 12..
//

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int alphaTable[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    std::string input;
    std::cin >> input;
    int ret = 0;
    for (char c : input)
        ret += alphaTable[c - 'A'];
    std::cout << ret;
}