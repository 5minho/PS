nclude <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int MAX_V = 20000;
const int INF = 987654321;

vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int start) {
    vector<int> dist(MAX_V, INF);
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i = 0 ; i < adj[here].size() ; ++i) {
        int next = adj[here][i].first;
            int costSum = adj[here][i].second + cost;
                if(dist[next] > costSum) {
                     dist[next] = costSum;
                    pq.push(make_pair(-costSum, next));
                    }
                }
            }
    return dist;
}

int main() {
    int v, e, start;
    cin >> v >> e >> start;
    for(int i = 0; i < e ; ++i) {
        int to, from, weight;
        cin >> to >> from >> weight;
        adj[to-1].push_back(make_pair(from-1, weight));
    }

    vector<int> dist = dijkstra(start-1);
    for(int i = 0 ; i < v; ++i) {
        dist[i] == 987654321 ? cout << "INF" << endl : cout << dist[i] << endl;
    }
}
