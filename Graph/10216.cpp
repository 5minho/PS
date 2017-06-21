//
// Created by 오민호 on 2017. 6. 21..
//

//
// Created by 오민호 on 2017. 5. 19..
//

#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

const int MAX = 3000;
int T = 0;

struct Camp {
    int x, y;
    int r;
};

std::vector<std::vector<int> > graph;
bool visit[MAX];

//(x1, y1) (x2, y2) 사이의 거리
int distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

//c1과 c2가 인접하면 true
bool isAdjacent(Camp& c1, Camp& c2) {
    return (c1.r + c2.r) * (c1.r + c2.r) >= distance(c1.x, c1.y, c2.x, c2.y);
}

void makeGraph(std::vector<Camp>& camps) {
    for(int i = 0 ; i < camps.size(); ++i)
        for(int j = i + 1 ; j < camps.size(); ++j) {
            if(isAdjacent(camps[i], camps[j]))
                graph[i].push_back(j), graph[j].push_back(i);
        }
}

int dfs(int here) {
    visit[here] = true;
    for(int i = 0 ; i < graph[here].size() ; ++i) {
        int there = graph[here][i];
        if(!visit[there])
            dfs(there);
    }
    return 1;
}

int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        int N;
        scanf("%d",&N);
        memset(visit,false,sizeof(visit));
        std::vector<Camp> camps(N);
        graph.assign(N,std::vector<int>());
        for(int j = 0 ; j < N ; ++j)
            scanf("%d %d %d",&camps[j].x,&camps[j].y,&camps[j].r);

        makeGraph(camps);

        int group = 0;
        for(int i = 0 ; i < N ; ++i)
            if(!visit[i])
                group += dfs(i);
        printf("%d\n", group);
    }
}