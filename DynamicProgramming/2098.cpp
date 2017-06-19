//
// Created by 오민호 on 2017. 6. 1..
//

#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX = 16;
const int INF = 987654321;
int dist[MAX][MAX];
int cache[MAX][1 << MAX];
int N = 0;
int shortestPath(int here, int visited) {
    if(visited == (1 << N) - 1) return dist[here][0];
    int& ret = cache[here][visited];
    if(ret != -1) return ret;
    ret = INF;
    for(int next = 0 ; next < N ; ++next) {
        if(visited & (1 << next) || !dist[here][next]) continue;
        ret = std::min(ret, dist[here][next] + shortestPath(next, visited + (1 << next)));
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            scanf("%d",&dist[i][j]);
    memset(cache, -1, sizeof(cache));
    printf("%d\n", shortestPath(0, 1 << 0));
}