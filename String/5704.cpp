//
// Created by 오민호 on 2018. 1. 1..
//

#include <iostream>
#include <vector>

bool isFanGram(std::vector<int>& alpha) {
    for (auto item : alpha)
        if (item == 0) {
            return false;
        }
    return true;
}

int main() {
    std::string str;

    while (std::getline(std::cin, str)) {
        if (str == "*") break;

        std::vector<int> alpha = std::vector<int>(26, 0);
        for (auto c : str) {
            if (c == ' ') continue;
            alpha[c - 'a']--;
        }


        if (isFanGram(alpha)) {std::cout << "Y" << "\n";}
        else {std::cout << "N" << "\n";}

    }

}

