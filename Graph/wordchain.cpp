//
// Created by 오민호 on 2017. 6. 28..
//

#include <iostream>
#include <vector>
#include <algorithm>

int n;

std::vector<std::vector<int>> adj;
std::vector<std::string> graph[26][26];
std::vector<int> inDegree;
std::vector<int> outDegree;

void makeGraph(std::vector<std::string>& words) {
    for(int i = 0 ; i < 26 ; ++i)
        for(int j = 0 ; j < 26 ; ++j)
            graph[i][j].clear();
    adj.assign(26, std::vector<int>(26, 0));
    inDegree.assign(26, 0);
    outDegree.assign(26, 0);

    for(auto word : words) {
        int s = word[0] - 'a';
        int e = word.back() - 'a';
        adj[s][e]++;
        graph[s][e].push_back(word);
        outDegree[s]++;
        inDegree[e]++;
    }
}

void getEulerCircuit(int here, std::vector<int>& circuit) {
    for(int there = 0 ; there < adj.size(); ++there) {
        while(adj[here][there] > 0) {
            adj[here][there]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}

std::vector<int> getEulerCircuitOrTrail() {
    std::vector<int> circuit;
    for(int i = 0 ; i < 26 ; ++i)
        if (inDegree[i] + 1 == outDegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    for(int i = 0 ; i < 26 ; ++i) {
        if(outDegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}

bool eulerCheck() {
    int plus1 = 0, minus1 = 0;
    for(int i = 0 ; i < 26 ; ++i) {
        int delta = inDegree[i] - outDegree[i];
        if(delta < -1 || delta > 1) return false;
        if(delta > 0) plus1++;
        if(delta < 0) minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    int C;
    std::cin >> C;

    while(C--) {
        std::cin >> n;
        std::vector<std::string> words(n);
        for(int i = 0 ; i < n ; ++i)
            std::cin >> words[i];
        makeGraph(words);

        if(!eulerCheck()) {
            std::cout << "IMPOSSIBLE" << "\n";
            break;
        }

        std::vector<int> circuit = getEulerCircuitOrTrail();
        std::reverse(circuit.begin(), circuit.end());

        for(int i = 1 ; i < circuit.size() ; ++i) {
            int s = circuit[i - 1], e = circuit[i];
            std::cout << graph[s][e].back() << " ";
            graph[s][e].pop_back();
        }
        std::cout << "\n";
    }
}