//
// Created by 오민호 on 2017. 5. 21..
//

#include <cstdio>
#include <cstring>

const int MAX = 100001;

int T = 0;

int visit[MAX];
int finished[MAX];
int graph[MAX];

int cycle = 0;

void dfs(int here) {
    visit[here] = 1;
    int there = graph[here];
    if(visit[there]) {
        if(!finished[there]) {
            for(int tmp = there ; tmp != here ; tmp = graph[tmp])
                cycle++;
            cycle++;
        }
    } else {
        dfs(there);
    }
    finished[here] = 1;
}

int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        cycle = 0;
        int n = 0;
        scanf("%d",&n);
        memset(visit, 0, sizeof(visit));
        memset(finished, 0, sizeof(finished));
        for(int j = 1 ; j <= n ; ++j)
            scanf("%d",&graph[j]);
        for(int j = 1 ; j <= n ; ++j)
            if(!visit[j]) dfs(j);
        printf("%d\n",n - cycle);
    }
}