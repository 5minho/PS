#include <stdio.h>
#include <algorithm>
#include <string.h>

const int MAX = 1000001;
const int INF = 987654321;

int cache[MAX];

int makeOne(int x) {
    if(cache[x] != -1) return cache[x];
    int& ret = cache[x];

    if(x <= 1) return ret = 0;
    ret = INF;
    if(x % 3 == 0) ret = makeOne(x / 3) + 1;
    if(x % 2 == 0) ret  = std::min(ret, makeOne(x / 2) + 1);
    ret = std::min(ret, makeOne(x - 1) + 1);

    return cache[x] = ret;
}


int main() {
    memset(cache, -1 ,sizeof(cache));
    int x = 0;
    scanf("%d",&x);
    printf("%d\n",makeOne(x));
    return 0;
}

