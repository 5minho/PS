//
// Created by 오민호 on 2017. 5. 25..
//

#include <cstdio>
#include <string>
#include <cstring>
const int MOD = 1000 * 1000 * 1000;
int N;
int cache[10][101];
int stairNum(int last, int length) {
    if(last > 9 || last < 0) return 0;

    int& ret = cache[last][length];
    if(ret != -1) return ret;
    if(length == N) return 1;
    ret = stairNum(last + 1, length + 1) + stairNum(last - 1, length + 1);
    ret %= MOD;
    return ret;
}

int main() {
    memset(cache, -1 , sizeof(cache));
    scanf("%d",&N);
    int ans = 0;
    for(int i = 1 ; i < 10; ++i)
        ans += stairNum(i, 1), ans %= MOD;
    printf("%d\n", ans);
}