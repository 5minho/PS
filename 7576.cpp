//
// Created by 오민호 on 2017. 5. 17..
//

#include <cstdio>
#include <queue>

const int MAX = 1000;
int n = 0, m = 0;
int map[MAX][MAX];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

struct tomato {
    int y,x,day;
    tomato(int _y, int _x, int _day):y(_y), x(_x), day(_day) {}
};

int main() {
    scanf("%d %d",&m, &n);

    std::queue<tomato> q;
    int zeroCount = 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j) {
            scanf("%d",&map[i][j]);
            if(map[i][j] == 1) {
                tomato t(i, j, 0);
                q.push(t);
            } else if(map[i][j] == 0) {
                ++zeroCount;
            }
        }

    if(q.empty()) {
        printf("0\n");
        return 0;
    }

    while(!q.empty()) {
        tomato t = q.front();
        q.pop();
        // 4방향 탐색
        for(int i = 0 ; i < 4 ; ++i) {
            int nextY = t.y + dy[i];
            int nextX = t.x + dx[i];
            int nextDay = t.day + 1;
            if(nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && map[nextY][nextX] == 0) {
                tomato tmp(nextY, nextX, nextDay);
                q.push(tmp);
                map[nextY][nextX] = 1;
                zeroCount--;
                if(!zeroCount) {
                    printf("%d\n",nextDay);
                    return 0;
                }
            }
        }
    }

    if(zeroCount) {
        printf("-1\n");
    } else {
        printf("0\n");
    }
    return 0;
}