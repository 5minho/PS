//
// Created by 오민호 on 2017. 4. 18..
//

#include <cstdio>
#include <vector>
#include <algorithm>

const int MAX = 8;

int N = 0, M = 0;

struct pos{
    int y, x;
    pos(int y, int x) :y(y), x(x) {}
};

int map[MAX][MAX];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int spreadVirus(int y, int x) {
    int ret = 1;
    map[y][x] = 2;
    for(int next = 0 ; next < 4 ; ++next) {
        int nextY = y + dy[next]; int nextX = x + dx[next];
        if(map[nextY][nextX] == 0 && nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
            ret += spreadVirus(nextY, nextX);
            map[y][x] = 0;
        }
    }
    return ret;
}

int main() {
    scanf("%d %d",&N,&M);
    int maxSafeArea = 0;

    std::vector<pos> safeAreaArray;
    std::vector<pos> virusAreaArray;

    for(int i = 0 ; i < N ; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) safeAreaArray.push_back(pos(i, j));
            if (map[i][j] == 2) virusAreaArray.push_back(pos(i, j));
        }
    }

    for(int i = 0 ; i < safeAreaArray.size() - 2 ; ++i) {
        for (int j = i + 1; j < safeAreaArray.size() - 1; ++j) {
            for (int k = j + 1; k < safeAreaArray.size(); ++k) {
                map[safeAreaArray[i].y][safeAreaArray[i].x] = 1;
                map[safeAreaArray[j].y][safeAreaArray[j].x] = 1;
                map[safeAreaArray[k].y][safeAreaArray[k].x] = 1;

                for (int l = 0; l < virusAreaArray.size(); ++l) {
                    int virusSpreaded = 0;
                    for(int next = 0 ; next < 4 ; ++next) {
                        int nextY = virusAreaArray[l].y + dy[next];
                        int nextX = virusAreaArray[l].x + dx[next];
                        if(map[nextY][nextX] == 0 && nextY >= 0 && nextY < N && nextX >= 0 && nextX < M)
                            virusSpreaded += spreadVirus(virusAreaArray[l].y, virusAreaArray[l].x);
                    }
                    printf("%d\n", virusSpreaded);
                }

//                for (int i = 0; i < N; ++i) {
//                    for (int j = 0; j < M; ++j)
//                        printf("%d ", map[i][j]);
//                    printf("\n");
//                }

                map[safeAreaArray[k].y][safeAreaArray[k].x] = 0;
                map[safeAreaArray[j].y][safeAreaArray[j].x] = 0;
                map[safeAreaArray[i].y][safeAreaArray[i].x] = 0;
            }
        }
    }

    printf("%d\n", maxSafeArea);
}
