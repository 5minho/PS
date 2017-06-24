//
// Created by 오민호 on 2017. 6. 25..
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

const int VERT_MAX = 801;
const int INF = 987654321;

std::vector<std::pair<int, int>> adj[VERT_MAX];
std::vector<int> distance;
int N, E;
int p1, p2;

void dijkstra(int src) {
    distance.assign(N + 1, INF);

    std::vector<bool> visited(N + 1, false);
    distance[src] = 0;

    while(true) {
        int closest = INF, here;
        for(int i = 1 ; i <= N ; ++i)
            if(distance[i] < closest && !visited[i]) {
                closest = distance[i];
                here = i;
            }
        if (closest == INF) break;
        visited[here] = true;
        for(int i = 0 ; i < adj[here].size() ; ++i) {
            int there = adj[here][i].first;
            if(visited[there]) continue;
            int nextDistance = distance[here] + adj[here][i].second;
            distance[there] = std::min(distance[there], nextDistance);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> E;
    for(int i = 0 ; i < E ; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        adj[a].push_back(std::make_pair(b, c));
        adj[b].push_back(std::make_pair(a, c));
    }

    std::cin >> p1 >> p2;
    dijkstra(1);
    if(distance[p1] == INF || distance[p2] == INF || distance[N] == INF) {
        std::cout << -1 << "\n";
        return 0;
    }
    int oneToP1 = distance[p1];
    int oneToP2 = distance[p2];
    dijkstra(p1);
    int p1ToN = distance[N];
    int p1ToP2 = distance[p2];
    dijkstra(p2);
    int p2ToN = distance[N];

    int path1 = oneToP1 + p1ToP2 + p2ToN;
    int path2 = oneToP2 + p1ToP2 + p1ToN;
    std::cout << std::min(path1, path2) << "\n";
    return 0;
}