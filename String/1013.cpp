//
// Created by 오민호 on 2017. 9. 7..
//

#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);

    int dfa[10][2];
    memset(dfa, -1, sizeof(dfa));

    dfa[0][0] = 1;
    dfa[0][1] = 2;

    dfa[1][1] = 3;

    dfa[2][0] = 4;

    dfa[3][0] = 1;
    dfa[3][1] = 2;

    dfa[4][0] = 5;

    dfa[5][0] = 5;
    dfa[5][1] = 6;

    dfa[6][0] = 1;
    dfa[6][1] = 7;

    dfa[7][0] = 8;
    dfa[7][1] = 7;

    dfa[8][0] = 5;
    dfa[8][1] = 3;

    int N;
    std::cin >> N;

    while(N--) {

        std::string code;
        std::cin >> code;

        int currentState = 0;

        for (auto c : code) {
            currentState = dfa[currentState][c - '0'];
            if (currentState == -1) break;
        }

        if (currentState == 3 || currentState == 6 || currentState == 7) {
            std::cout << "YES" << "\n";
            continue;
        }

        std::cout << "NO" << "\n";

    }
}