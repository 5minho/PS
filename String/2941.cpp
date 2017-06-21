//
// Created by 오민호 on 2017. 6. 21..
//

//
// Created by 오민호 on 2017. 6. 12..
//

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::string croatiaAlpha[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    std::string input;
    std::cin >> input;
    for (std::string s : croatiaAlpha) {
        size_t foundIdx = input.find(s);
        while (foundIdx != std::string::npos) {
            input.replace(foundIdx, s.size(), "*");
            foundIdx = input.find(s);
        }
    }
    std::cout << input.size();
}