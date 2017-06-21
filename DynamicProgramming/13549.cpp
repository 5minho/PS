//
// Created by 오민호 on 2017. 6. 21..
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>

const int MAX = 100000;
const int INF = 90000000;

int visit[MAX];

int main() {
    memset(visit, 0, sizeof(visit));
    int n = 0, k = 0;
    int x = 0, y = 0;
    scanf("%d %d",&n, &k);
    std::queue<std::pair<int, int> > q;
    q.push(std::make_pair(n, 0));
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        if(visit[x]) {
            q.pop();
            continue;
        }
        visit[x] = 1;
        if(x == k) break;
        q.pop();
        if(2 * x <= MAX) q.push(std::make_pair(2 * x, y));
        if(x >= 1) q.push(std::make_pair(x - 1, y + 1));
        if(x < MAX) q.push(std::make_pair(x + 1, y + 1 ));
    }
    printf("%d\n",y);
    return 0;
}

