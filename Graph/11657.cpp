//
// Created by 오민호 on 2017. 7. 2..
//

#include <iostream>
#include <vector>
const int INF = 987654321;
std::vector<std::vector<std::pair<int, int>>> adj;

int N, M;
int A, B, C;

std::vector<int> bellmanFord(int src) {
    std::vector<int> upper(N + 1, INF);
    upper[src] = 0;
    bool updated;

    for(int iter = 0 ; iter < N ; ++iter) {
        updated = false;
        for(int here = 1 ; here < N + 1 ; ++here) {
            for(int i = 0 ; i < adj[here].size() ; ++i) {
                int there = adj[here][i].first;
                int costSum = adj[here][i].second + upper[here];
                if(upper[there] > costSum) {
                    upper[there] = costSum;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }

    if(updated) upper.clear();

    return upper;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    adj.resize(N + 1);
    for(int i = 0 ; i < M ; ++i) {
        std::cin >> A >> B >> C;
        adj[A].push_back(std::make_pair(B, C));
    }

    std::vector<int> distance = bellmanFord(1);
    if(distance.empty()) std::cout << -1;
    else {
        for (int i = 2 ; i <= N ; ++i)
            distance[i] != INF ? std::cout << distance[i] << "\n" : std::cout << -1 << "\n";
    }
    return 0;
}