//
// Created by 오민호 on 2017. 6. 10..
//

#include <iostream>
int N;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin >> N;
    int ans = N;
    for(int i = 0 ; i < N ; ++i) {
        bool appear[26] = {false, };
        std::string s;
        std::cin >> s;
        char preChar;
        for (char c : s) {
            if(appear[c - 'a'] && preChar != c) {
                ans--;
                break;
            }
            appear[c - 'a'] = true;
            preChar = c;
        }
    }
    std::cout << ans;
}