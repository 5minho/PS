//
// Created by 오민호 on 2017. 5. 24..
//

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

const int MAX = 1001;
std::vector<std::vector<bool> > adj;
std::vector<bool> visit;

int N, M, S;

void makeGraph() {
    adj.assign(N + 1, std::vector<bool>(N + 1, false));
    for(int i = 0 ; i < M ; ++i) {
        int to, from;
        scanf("%d %d",&to, &from);
        adj[to][from] = adj[from][to] = true;
    }
}

//DFS
void dfs(int here) {
    std::stack<int> s;
    s.push(here);
    visit[here] = true;
   // if(x == required) return;
   // cout << x << " : " << endl;
    while(!s.empty()){
        int k = s.top();
        s.pop();
     //   if(k == required) break;
        std::cout<<k<<" ";
        for (int i = N; i >= 1 ; --i)
            if (adj[k][i] && !visit[i]) {
                s.push(i);
                visit[i] = true;
            }
    }
}

//BFS
void bfs(int here) {
    std::queue<int> queue;
    queue.push(here);
    visit[here] = true;

    while(!queue.empty()) {
        int current = queue.front();
        queue.pop();
        printf("%d ", current);
        for(int next = 1 ; next <= N; ++next) {
            if(!visit[next] && adj[current][next]) {
                queue.push(next);
                visit[next] = true;
            }
        }
    }
}

int main() {
    scanf("%d %d %d",&N, &M, &S);
    makeGraph();

    visit.assign(N + 1, false);
    dfs(S);
    printf("\n");
    visit.assign(N + 1, false);
    bfs(S);
}