//
// Created by 오민호 on 2017. 9. 13..
//

#include <iostream>

int check(std::string s, int flag) {

    int ret = 0;

    for (int i = flag ; i < s.size() ; i+=2) {
        if (s[i] == 'F')
            ret++;
    }

    return ret;
}

int main() {

    std::ios::sync_with_stdio(false);

    std::string arr[8];

    for(int i = 0 ; i < 8 ; ++i) {
        std::cin >> arr[i];
    }

    int ans = 0;

    for(int i = 0 ; i < 8 ; ++i) {
        ans += check(arr[i], i % 2);
    }

    std::cout << ans;
    return 0;

}
