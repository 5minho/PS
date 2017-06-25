//
// Created by 오민호 on 2017. 6. 25..
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int MAX_N = 501;
const int INF = 987654321;

std::vector<std::pair<int, int>> adj[MAX_N];
std::vector<int> upper;

int TC;
int N,M,W;
int S,E,T;

void bellmanFord(int src) {
    upper.assign(N + 1, INF);
    upper[src] = 0;
    bool updated;
    for(int iter = 0 ; iter < N ; ++iter) {
        updated = false;
        for(int here = 1 ; here <= N ; ++here)
            for(int i = 0 ; i < adj[here].size(); ++i) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        if(!updated) break;
    }
    if(updated) upper.clear();
}


int main() {
    std::cin >> TC;
    while(TC--) {
        std::cin >> N >> M >> W;
        for(int i = 0 ; i < M ; ++i) {
            std::cin >> S >> E >> T;
            adj[S].push_back(std::make_pair(E, T));
            adj[E].push_back(std::make_pair(S, T));
        }

        for(int i = 0 ; i < W ; ++i) {
            std::cin >> S >> E >> T;
            adj[S].push_back(std::make_pair(E, T * -1));
        }

        bellmanFord(1);
        if(upper.size() == 0) std::cout << "YES\n";
        else std::cout << "NO\n";

        for(int i = 0 ; i <= N ; ++i)
            adj[i].clear();
    }
    return 0;
}