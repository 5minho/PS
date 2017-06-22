//
// Created by 오민호 on 2017. 6. 23..
//

#include <iostream>
#include <vector>

const int MAX = 50;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int T;
int M,N,K;
std::vector<std::vector<int> > map;

bool boundaryCheck(int y, int x) {
    return y > -1 && y < N && x > -1 && x < M;
}

void dfs(int y, int x) {
    map[y][x] = 0;
    for(int i = 0 ; i < 4 ; ++i) {
        int nextY = y + dy[i], nextX = x + dx[i];
        if (boundaryCheck(nextY, nextX) && map[nextY][nextX])
            dfs(nextY, nextX);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> T;

    while(T--) {
        std::cin >> M >> N >> K;
        map.assign(N, std::vector<int>(M, 0));
        int X,Y;
        for(int i = 0 ; i < K ; ++i) {
            std::cin >> X >> Y;
            map[Y][X] = 1;
        }

        int ans = 0;
        for(int i = 0 ; i < N ; ++i)
            for(int j = 0 ; j < M ; ++j)
                if(map[i][j]) dfs(i, j), ans++;

        std::cout << ans << "\n";
    }

    return 0;
}