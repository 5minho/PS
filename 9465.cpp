//
// Created by 오민호 on 2017. 6. 14..
//

#include <iostream>
#include <cstring>

const int MAX = 100001;

int T;
int sticker[2][MAX];
inline int max (int a, int b, int c) {
    return a > b ? a > c ? a : c : b > c ? b : c;
}
int main() {
    std::iostream::sync_with_stdio(false);
    std::cin >> T;
    int n;
    while(T--) {
        memset(sticker, 0, sizeof(sticker));
        std::cin >> n;
        for(int i = 0 ; i < 2 ; ++i)
            for(int j = 1 ; j <= n ; ++j)
                std::cin >> sticker[i][j];
        for(int i = 2 ; i <= n ; ++i) {
            sticker[0][i] += max(sticker[0][i - 2], sticker[1][i - 2], sticker[1][i - 1]);
            sticker[1][i] += max(sticker[0][i - 2], sticker[1][i - 2], sticker[0][i - 1]);
        }
        std::cout << std::max(sticker[0][n], sticker[1][n]) << "\n";
    }
}
