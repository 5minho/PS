//
// Created by 오민호 on 2017. 6. 12..
//

#include <iostream>
#include <algorithm>
#include <cstring>

const int MAX = 1001;
int boxes[MAX];
int n;
int cache[MAX];

int lis(int k) {
    if(k > n) return 0;
    int& ret = cache[k];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = k + 1 ; i <= n ; ++i) {
        if(boxes[k] < boxes[i])
            ret = std::max(ret, lis(i) + 1);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    memset(cache, -1 ,sizeof(cache));
    std::cin >> n;
    for (int i = 1 ; i <= n ; ++i)
        std::cin >> boxes[i];
    int ans = 0;
    for(int i = 1; i <= n ; ++i)
        ans = std::max(ans, lis(i));
    std::cout << ans;
}