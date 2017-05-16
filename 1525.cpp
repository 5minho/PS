//
// Created by 오민호 on 2017. 5. 13..
//

#include <cstdio>
#include <vector>
#include <map>
#include <queue>

class State;

typedef unsigned long long uint64;
typedef std::map<State, int> StateMap;

int get(uint64 mask, int index) {
    return (mask >> (index << 2)) & 15;
}

uint64 set(uint64 mask, int index, uint64 value) {
    return (mask & ~(15LL << (index << 2))) | (value << (index << 2));
}


int show(uint64 mask) {
    for(int i = 0 ; i < 3 ; ++i) {
        for(int j = 0 ; j < 3 ; ++j)
            printf("%d ",get(mask, i * 3 + j));
        printf("\n");
    }
    printf("\n");
}


int d[4] = {-3, 1, 3, -1};

class State {
public:
    State(uint64 _mask, int _zero): mask(_mask), zero(_zero) {};
    std::vector<State> getAdjacent() const {
        std::vector<State> adj;
        for(int i = 0 ; i < 4; ++i) {
            if(i == 1 && (zero == 2 || zero == 5 || zero == 8)) continue;
            if(i == 3 && (zero == 0 || zero == 3 || zero == 6)) continue;
            int zInx = zero + d[i];
            int tmp = 0;
            if((zInx) > -1 && (zInx) < 9 && (zInx % 3) < 3 ) {
                uint64 newMask = mask;
                tmp = get(newMask, zInx);
                newMask = set(newMask, zero, tmp);
                newMask = set(newMask, zInx, 0);

                adj.push_back(State(newMask, zInx));
            }
        }
        return adj;
    }
    bool operator< (const State& ref) const {
        return mask > ref.mask;
    }

    bool operator== (const State& ref) const {
        return (mask == ref.mask);
    }

private:
    uint64 mask;
    int zero;
};

int bfs(State start, State finish) {
    if(start == finish) return 0;
    StateMap c;
    std::queue<State> q;
    q.push(start);

    c[start] = 0;

    while(!q.empty()) {
        State here = q.front();
        q.pop();
        int cost = c[here];
        std::vector<State> adj = here.getAdjacent();

        for(int i = 0 ; i < adj.size() ; ++i) {
            if(c.count(adj[i]) == 0) {
                if(adj[i] == finish) return cost + 1;
                c[adj[i]] = cost + 1;
                q.push(adj[i]);
            }
        }

    }
    return -1;
}


int main() {
    uint64 start = 0;
    int zero = 0;
    uint64 finish = 0;
    for(int i = 0 ; i < 9 ; ++i) {
        uint64 value = 0;
        scanf("%lld",&value);
        start = set(start, i, value);
        if(value == 0) zero = i;
    }

    for(int i = 0 ; i < 8 ; ++i)
        finish = set(finish, i, i + 1);
    finish = set(finish, 8, 0);
    printf("%d\n",bfs(State(start, zero), State(finish, 8)));
}