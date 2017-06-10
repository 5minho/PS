//
// Created by 오민호 on 2017. 4. 11..
//

#include <iostream>
#include <queue>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001; // 최대 역의 수
const int MAX_K = 1000; // 최대 서로 연결하는 역의 개수
const int MAX_M = 1000; // 최대 하이퍼튜브 수


int N = 0; // 역 개수
int K = 0; // 하이퍼 튜브가 서로 연결하는 역의 수
int M = 0; // 하이퍼 튜브 수


array<vector<int> , MAX_N + MAX_M> graph;

void bfs(int start, vector<int>& distance){
    distance = vector<int>(MAX_N + MAX_M, -1);
    queue<int> q;
    distance[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(int i = 0 ; i < graph[here].size() ; ++i) {
            int there = graph[here][i];
            if(distance[there] == -1) {
                q.push(there);
                distance[there] = distance[here] + 1;
            }
        }
    }
}


int main() {
    cin >> N >> K >> M;
    //인접리스트 표현으로 그래프 정의
    for (int i = 0; i < M; ++i)
        for (int j = 0, c; j < K; ++j)
            cin >> c, graph[MAX_N + i].push_back(c), graph[c].push_back(MAX_N + i);

    vector<int> distance;
    bfs(1, distance);
    if(distance[N] > 0)
        cout << distance[N] / 2 + 1 << endl;
    else
        cout << -1 << endl;

}