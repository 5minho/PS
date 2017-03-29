//
// Created by 오민호 on 2017. 3. 27..
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <cstdlib>

#define ISLAND_MAX 100

using namespace std;

struct island {
    int land;
    int idx;
    int count;
};

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};



island map[ISLAND_MAX][ISLAND_MAX];
int N = 0;

void indexing(int y, int x, int idx) {
    if(y < 0 || y >= N || x < 0 || x >= N || map[y][x].land != 1 || map[y][x].idx != 0) return;
    map[y][x].idx = idx;
    for(int next = 0 ; next < 4 ; ++next) {
        int nextY = y + dy[next];
        int nextX = x + dx[next];
        indexing(nextY, nextX, idx);
    }
}

bool reclaim(int& count) {
    vector<island*> reclaimed;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            if(map[i][j].land == 0) continue;
            for(int next = 0 ; next < 4 ; ++next) {
                int nextY = i + dy[next];
                int nextX = j + dx[next];
                if(nextY < 0 || nextY >= N || nextX < 0 || nextX >= N ||
                        map[nextY][nextX].idx == map[i][j].idx || map[nextY][nextX].idx == -map[i][j].idx) continue;

                if(map[nextY][nextX].idx < 0 && abs(map[nextY][nextX].idx) != abs(map[i][j].idx)) {
                    count = map[i][j].count + map[nextY][nextX].count;
                    printf("(%d,%d)\n",i,j);
                    printf("%d\n",map[i][j].idx);
                    return false;
                }
                map[nextY][nextX].idx = -abs(map[i][j].idx);
                map[nextY][nextX].count = count;
                reclaimed.push_back(&map[nextY][nextX]);
            }
        }
    }
    for(int i = 0 ; i < reclaimed.size(); ++i)
        reclaimed[i]->land = 1;

//    for(int i = 0 ; i < N ; ++i) {
//        for(int j = 0 ; j < N ; ++j) {
//            printf("[%d]",map[i][j].idx);
//        }
//        printf("\n");
//    }
//
//    printf("\n");

    return true;
}

int main() {
    scanf("%d",&N);
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            scanf("%d", &map[i][j].land);


    int next_idx = 1;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            if (map[i][j].idx != 0 || map[i][j].land == 0) continue;
            indexing(i, j, next_idx++);
        }
    }

    if(N == 1 || next_idx - 1 == 1 || next_idx == 1) {
        printf("%d",0);
        return 0;
    }

    int count = 1;
    while(1) {
        if (!reclaim(count)) break;
        count++;
    }
    printf("%d\n",count);

    return 0;
}