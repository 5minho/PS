#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

const int MAX = 100001;
const int INF = 90000000;

int cache[MAX];
//int visit[MAX];

//x에서 k를 찾는데 걸리는 최소 시간
int find(int x, int k) {
    if(x < 0 || x >= MAX) return INF;
    //if(visit[x]) return cache[x];
    if(x == k) return 0;
    int& ret = cache[x]; 
    if(ret != -1) return ret;
    ret = INF;
    ret = std::min(ret, find(x - 1, k) + 1);
    ret = std::min(ret, find(2 * x, k) + 1);
    ret = std::min(ret, find(x + 1, k) + 1);
    //visit[x] = 1;
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    //memset(visit, 0, sizeof(visit)); 
    int n = 0,
        k = 0;
    scanf("%d %d",&n, &k);
    printf("%d\n",find(n, k));
    return 0;
}
