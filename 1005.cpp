//
// Created by 오민호 on 2017. 5. 25..
//

#include <cstdio>
#include <array>
#include <vector>
#include <algorithm>

const int MAX = 1001;

std::array<std::array<bool, MAX>, MAX> adj;
std::array<int, MAX> buildTimes;
std::array<int, MAX> Darray;
std::array<bool, MAX> visit;
std::vector<int> order;

int T;
int N,K;
int X,Y,W;

void topologicalSort(int here) {
    visit[here] = true;
    for(int there = 1 ; there <= N ; ++there){
        if(adj[here][there] && !visit[there])
            topologicalSort(there);
    }
    order.push_back(here);
}

int main() {
    scanf("%d",&T);
    for(int t = 0 ; t < T ; ++t) {
        visit.fill(false);
        adj.fill(std::array<bool, MAX>() = {false, });
        order.clear();
        buildTimes.fill(0);
        Darray.fill(0);

        scanf("%d %d", &N, &K);
        for(int i = 1 ; i <= N ; ++i)
            scanf("%d",&Darray[i]);

        for(int i = 1 ; i <= K ; ++i) {
            scanf("%d %d",&X, &Y);
            adj[X][Y] = true;
        }
        scanf("%d",&W);

        for(int i = 1 ; i <= N ; ++i)
            if(!visit[i]) topologicalSort(i);

        std::reverse(order.begin(), order.end());
        buildTimes[order[0]] = Darray[order[0]];
        for(auto i : order) {
            for(int j = 1 ; j <= N ; ++j) {
                if(adj[j][i])
                    buildTimes[i] = std::max(buildTimes[i], Darray[i] + buildTimes[j]);
            }
            if(i == W) {
                printf("%d\n", buildTimes[i]);
                break;
            }
        }
    }
    return 0;
}