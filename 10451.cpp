//
// Created by 오민호 on 2017. 5. 20..
//

#include <cstdio>
#include <vector>
#include <cstring>

const int MAX = 1001;
int T = 0;
std::vector<std::vector<int> > graph;
bool visit[MAX];

void dfs(int here) {
    visit[here] = true;
    for(int i = 0 ; i < graph[here].size() ; ++i) {
        int there = graph[here][i];
        if(!visit[there]) dfs(there);
    }
}

int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T; ++i) {
        int N;
        scanf("%d",&N);

        graph.assign(N + 1, std::vector<int>());
        memset(visit, 0 , sizeof(visit));

        for(int from = 1 ; from <= N ; ++from) {
            int to;
            scanf("%d",&to);
            graph[from].push_back(to);
        }
        int ret = 0;
        for(int j = 1 ; j <= N ; ++j) {
            if(!visit[j]) {
                dfs(j);
                ret++;
            }
        }
        printf("%d\n", ret);
    }
}