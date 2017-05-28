//
// Created by 오민호 on 2017. 5. 28..
//

#include <cstdio>
#include <cstring>

const int MAX = 500;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int M,N;
int map[MAX][MAX];
int cache[MAX][MAX];

bool isBoundaryCheck(int y, int x) {
    return (y >= 0 || y < M || x >= 0 || x < N);
}

int goThere(int y, int x) {
    if(y == M - 1 && x == N - 1) return 1;
    int& ret = cache[y][x];

    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0 ; i < 4 ; ++i) {
        int nextY = y + dy[i]; int nextX = x + dx[i];
        if(isBoundaryCheck(nextY, nextX) && map[y][x] > map[nextY][nextX])
            ret += goThere(nextY, nextX);
    }

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d %d",&M,&N);
    for(int i = 0 ; i < M ; ++i)
        for(int j = 0 ; j < N ; ++j)
            scanf("%d", &map[i][j]);
    printf("%d\n",goThere(0, 0));
}