//
// Created by 오민호 on 2017. 5. 18..
//

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

const int MAX = 25;
const int dy[4] = {0,-1,0,1};
const int dx[4] = {-1,0,1,0};

//원본 배열
char map[MAX][MAX];
//아파트 단지 배열
int apartment[MAX][MAX];

int N = 0;
int complex = 0; // 단지 index

void dfs(int y, int x, int& c) {
    apartment[y][x] = complex;
    c++;
    map[y][x] = '0';
    for(int i = 0 ; i < 4 ; ++i) {
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(nextY >= 0 && nextY < N && nextX >= 0 && nextX < N && map[nextY][nextX] != '0') {
            dfs(nextY, nextX, c);
        }
    }
}

int main() {
    // n 입력
    scanf("%d",&N); getchar();
    std::vector<int> ret;

    for(int i = 0 ; i < N ; ++i) {
        for (int j = 0; j < N; ++j) {
            map[i][j] = getchar();
        }
        getchar();
    }

    for(int i = 0 ; i < N ; ++i)
        for (int j = 0; j < N; ++j) {
            if (map[i][j] != '0') { // 주어진 배열을 하나하나 확인 하면서 아파트가 있으면 dfs로 인덱싱을 한다.
                int c = 0;
                complex++;
                dfs(i, j, c);
                ret.push_back(c);
            }
        }


    std::sort(ret.begin(), ret.end());
    printf("%d\n",complex);
    for(int i = 0 ; i < ret.size() ; ++i)
        printf("%d\n",ret[i]);
}