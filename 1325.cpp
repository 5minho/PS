//
// Created by 오민호 on 2017. 5. 20..
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

const int MAX = 10001;
int N = 0, M = 0;

std::vector<std::vector<int> > graph;
std::vector<int> discovered;
std::vector<int> sccID;
std::stack<int> stack;
std::vector<int> sccCountArr;
std::vector<std::vector<int> > sccGraph;

int vertexCount = 0,
    sccCount = 1;

int scc(int here) {
    discovered[here] = vertexCount++;
    int ret = discovered[here];
    int there;
    stack.push(here);

    for(int i = 0 ; i < graph[here].size() ; ++i) {
        there = graph[here][i];
        if (discovered[there] == -1) {
            ret = std::min(ret, scc(there));
        } else if (sccID[there] == -1) {
            ret = std::min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        while (true) {
            int t = stack.top();
            stack.pop();
            sccID[t] = sccCount;
            sccCountArr[sccCount]++;
            if (t == here) break;
        }
        ++sccCount;
    }
    return ret;
}

void tajan() {
    discovered = sccID = std::vector<int>(N + 1, -1);
    sccCountArr.assign(N + 1, 0);
    for(int i = 1 ; i <= N ; ++i) {
        if(discovered[i] == -1)
            scc(i);
    }
}

int sccDfs(int here) {
    int ret = sccCountArr[here];
    discovered[here] = 1;
    for(int i = 0 ; i < sccGraph[here].size() ; ++i) {
        int there = sccGraph[here][i];
        if(discovered[there] == -1)
            ret += sccDfs(there);
    }
    return ret;
}

void makeGraphOfScc() {
    for(int i = 1 ; i <= N ; ++i) {
        for(int j = 0 ; j < graph[i].size() ; ++j) {
            if(sccID[i] == sccID[graph[i][j]]) continue;
            sccGraph[sccID[i]].push_back(sccID[graph[i][j]]);
        }
    }
}

int main() {
    scanf("%d %d",&N, &M);
    graph.resize(N + 1);
    sccGraph.resize(N + 1);

    for(int i = 0 ; i < M ; ++i) {
        int getTrust; // 신뢰 받는 피씨번호
        int trust; // 신뢰 하는 피씨번호
        scanf("%d %d",&trust, &getTrust);
        graph[getTrust].push_back(trust);
    }
    tajan();
    makeGraphOfScc();

    for(int i = 1 ; i < sccCount ; ++i) {
        std::sort(sccGraph[i].begin(), sccGraph[i].end());
        sccGraph[i].erase(std::unique(sccGraph[i].begin(), sccGraph[i].end()), sccGraph[i].end());
    }

    int ans = 0;
    std::vector<int> maxHackedPc(sccCount, 0);
    for(int i = 1 ; i < sccCount ; ++i) {
        discovered.assign(N + 1, -1);
        ans = std::max(maxHackedPc[i] = sccDfs(i), ans);
    }

    for(int i = 1 ; i <= N ; ++i) {
        if(maxHackedPc[sccID[i]] == ans)
            printf("%d ",i);
    }

    return 0;
}