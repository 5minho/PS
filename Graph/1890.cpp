//
// Created by 오민호 on 2017. 5. 20..
//

#include <cstdio>
#include <cstring>

const int MAX = 100;

typedef unsigned long long ull;

int map[MAX][MAX];
int N = 0;
ull cache[MAX][MAX];

ull dfs(int y,int x) {
    if(y < 0 || y >= N || x < 0 || x >= N) return 0;
    if(map[y][x] == 0) {
        if(y == N - 1 && x == N -1) return 1;
        else return 0;
    }

    ull& ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 1ll;
    ret = dfs(y + map[y][x], x) + dfs(y, x + map[y][x]) ;
    return ret;
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            scanf("%d",&map[i][j]);
    memset(cache,-1,sizeof(cache));
    printf("%llu\n",dfs(0, 0));
}