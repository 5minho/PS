//
// Created by 오민호 on 2017. 5. 10..
//

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

const int MAX = 101;
const int INF = 987654321;

std::string map[MAX];
int visited[MAX][MAX];

int n,m;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0 ,1, 0, -1};

int main() {
    scanf("%d %d",&n,&m);
    memset(visited, 0, sizeof(visited));
    for(int i = 0 ; i < n ; ++i)
        std::cin >> map[i];

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            visited[i][j] = INF;

    std::queue<std::pair<int, int> > queue;
    queue.push(std::make_pair(0, 0));
    visited[0][0] = 1;

    while(!queue.empty()) {
        std::pair<int, int> curPoint = queue.front();
        queue.pop();

        if(curPoint.first == n - 1 && curPoint.second == m - 1) {
            printf("%d\n", visited[curPoint.first][curPoint.second]);
            return 0;
        }

        for(int i = 0 ; i < 4 ; ++i) {
            int ny = curPoint.first + dy[i];
            int nx = curPoint.second + dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx] == 49) {
                if(visited[ny][nx] > visited[curPoint.first][curPoint.second] + 1) {
                    queue.push(std::make_pair(ny, nx));
                    //printf("%d\n",visited[curPoint.y][curPoint.x], );
                    visited[ny][nx] = visited[curPoint.first][curPoint.second] + 1;
                }
            }
        }
    }

    printf("%d\n",-1);
}