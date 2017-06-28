//
// Created by 오민호 on 2017. 6. 29..
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

std::vector<std::vector<std::pair<int, double>>> adj;

int n, m;
int a, b;
double c;

double dijkstra(int start) {
    std::vector<double> dist(10001, 0.0);
    std::priority_queue<std::pair<double, int> > pq;
    dist[start] = 1.0;
    pq.push(std::make_pair(-1.0, start));

    while(!pq.empty()) {

        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0 ; i < adj[here].size() ; ++i) {
            int next = adj[here][i].first;
            double costMul = adj[here][i].second * cost;
            if(dist[next] == 0.0 || costMul < dist[next]) {
                dist[next] = costMul;
                pq.push(std::make_pair(costMul * -1, next));
            }
        }
    }
    return dist[n - 1];
}


int main() {
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while(t--) {
        std::cin >> n >> m;
        adj.clear();
        adj.resize(n + 1);
        for(int i = 0 ; i < m ; ++i) {
            std::cin >> a >> b >> c;
            adj[a].push_back(std::make_pair(b,c));
            adj[b].push_back(std::make_pair(a,c));
        }
        printf("%.10f\n", dijkstra(0));
    }

    return 0;
}