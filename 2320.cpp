//
// Created by 오민호 on 2017. 3. 31..
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

vector<vector<int> > adj;
string graph[26][26];

int N = 0;

void makeGraph(const vector<string>& words) {
    for(int i = 0 ; i < 26 ; ++i)
        for(int j = 0 ; j < 26 ; ++j)
            graph[i][j] = "";

    adj = vector<vector<int> > (26, vector<int>(26,0));

    for(int i = 0 ; i < words.size() ; ++i) {
        int point = words[i].size();
        int a = words[i][0] - 'A';
        int b = words[i][point - 1] - 'A';
        if(graph[a][b].size() >= point) continue;
        graph[a][b] = words[i];
        adj[a][b] = point;
    }
}

int dfs(int here) {
    int point = 0;
    for(int there = 0 ; there < adj[here].size() ; ++there) {
        if(adj[here][there] > 0) {
            point = adj[here][there];
            adj[here][there] = 0;
        }
    }
    return point;
}

int main() {
    cin >> N;
    vector<string> words(N);
    for(int i = 0 ; i < N ; ++i)
        cin >> words[i];
    makeGraph(words);
    int curPoint = 0;

    for(int i = 0 ; i < adj.size() ; ++i) {
        for (int j = 0; j < adj.size(); ++j) {
            cout << adj[i][j];
        }
        cout << endl;
    }
    for(int i = 0 ; i < adj.size() ; ++i) {
        curPoint = std::max(dfs(i), curPoint);
    }

    cout << curPoint << endl;
}