//
// Created by 오민호 on 2017. 3. 24..
//

////////그래프를 만들어서 해보자!!!////////

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int MAX = 500;

using namespace std;

struct Tile {
    int left;
    int right;
    // 첫번째 타일 -> 홀수라인 : 1, 짝수라인 : 2
    // 마지막 타일 -> 홀수라인 : 3, 짝수라인 : 4
    int pos;
    int num;
};

int N = 0;
Tile tiles[MAX * MAX];

int main() {
    scanf("%d", &N);
    int i = 0;
    int dest = 0;
    int size = N * N - N / 2;
    for(int line = 1 ; line <= N ; ++line) {
        int NorN_1 = line % 2 ? N : N-1;
        int curIdx = i;
        for(; i < NorN_1 + curIdx; ++i) {
            scanf("%d %d", &tiles[i].left, &tiles[i].right);
            tiles[i].num = i;
        }
        tiles[curIdx].pos = line % 2 ? 1 : 2;
        tiles[i - 1].pos = line % 2 ? 3 : 4;
    }

    queue<Tile*> q;
    int distance[size];
    memset(distance, 1, sizeof(distance));
    distance[0] = 0;
    int parent[size];
    memset(parent, -1, sizeof(parent));
    parent[0] = 0;

    q.push(&tiles[0]);
    while(!q.empty()) {
        // 타일의 위치 파악
        Tile* tile = q.front();
        //printf("[%d,%d]",tile->left,tile->right);
        // 큐에서 빼고
        q.pop();
        int pos = tile->pos;
        dest = max(tile->num, dest);
        // 위치에 따라서 다르게 검사
        Tile* tmp = NULL;
        switch (pos) {
            case 0:
                //N - 1 번째 후 타일 검사
                tmp = tile + (N - 1);
                if(tmp != NULL && tile->left == tmp->right) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                //N 번째 후 타일 검사
                tmp = tile + N;
                if(tmp != NULL && tile->right == tmp->left) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                //바로 옆에 있는 타일 검사
                tmp = tile + 1;
                if(tile->right == tmp->left) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                break;
            case 1:
                //N 번째 후 타일 검사
                tmp = tile + N;
                if(tmp != NULL && tile->right == tmp->left) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                //바로 옆에 있는 타일 검사
                tmp = tile + 1;
                if(tile->right == tmp->left) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                break;
            case 2:
                //N - 1 번째 후 타일 검사
                tmp = tile + (N - 1);
                if(tmp != NULL && tile->left == tmp->right) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                //N 번째 후 타일 검사
                tmp = tile + N;
                if(tmp != NULL && tile->right == tmp->left) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                //바로 옆에 있는 타일 검사
                tmp = tile + 1;
                if(tile->right == tmp->left){
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
            case 3:
                //N - 1 번째 후 타일 검사
                tmp = tile + (N - 1);
                if(tmp != NULL && tile->left == tmp->right) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                break;
            case 4:
                //N - 1 번째 후 타일 검사
                tmp = tile + (N - 1);
                if(tmp != NULL && tile->left == tmp->right) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                //N 번째 후 타일 검사
                tmp = tile + N;
                if(tmp != NULL && tile->right == tmp->left) {
                    q.push(tmp);
                    distance[tmp->num] = distance[tile->num] + 1;
                    parent[tmp->num] = tile->num;
                }
                break;
        }
    }

    printf("%d\n",distance[dest] + 1);
    vector<int> path(1, dest);
    while(parent[dest] != dest) {
        dest = parent[dest];
        path.push_back(dest);
    }
    reverse(path.begin(), path.end());

    for(int j = 0 ; j < path.size(); ++j) {
        printf("%d ",path[j] + 1);
    }
}