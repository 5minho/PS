//
// Created by 오민호 on 2017. 6. 30..
//

#include <iostream>
#include <vector>
#include <queue>

const int INF = 987654321;

std::vector<std::vector<std::pair<int, int>>> adj;

int n, m;
int u, v, w;
int s, d;

int dijkstra(int start) {
    std::vector<int> distance(n + 1, INF);
    distance[start] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push(std::make_pair(0, start));

    while(!pq.empty()) {
        int weight = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(distance[here] < weight) continue;

        for(int i = 0 ; i < adj[here].size() ; ++i) {
            int there = adj[here][i].first;
            int weightSum = adj[here][i].second + weight;
            if(distance[there] > weightSum) {
                distance[there] = weightSum;
                pq.push(std::make_pair(-weightSum, there));
            }
        }
    }

    return distance[d];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0 ; i < m ; ++i) {
        std::cin >> u >> v >> w;
        adj[u].push_back(std::make_pair(v, w));
    }
    std::cin >> s >> d;
    std::cout << dijkstra(s) << "\n";
}