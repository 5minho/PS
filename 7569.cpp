//
// Created by 오민호 on 2017. 5. 17..
//

#include <cstdio>
#include <queue>

const int MAX = 100;
int n = 0, m = 0, h = 0;
int box[MAX][MAX][MAX];
int dy[6] = {0, -1, 0, 1, 0, 0};
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct Tomato {
    int z,y,x; // 토마토 위치
    int day; // 익었을때 날짜
    Tomato(int _z, int _y, int _x, int _day):z(_z), y(_y), x(_x), day(_day) {}
};

int main() {
    scanf("%d %d %d",&m, &n, &h);

    std::queue<Tomato> q;
    int unripe = 0; // 익지 않은 토마토 개수

    for(int i = 0 ; i < h ; ++i)
        for(int j = 0 ; j < n ; ++j)
            for(int k = 0 ; k < m ; ++k) {
                scanf("%d",&box[i][j][k]);
                if(box[i][j][k] == 1) q.push(Tomato(i,j,k,0));
                if(box[i][j][k] == 0) ++unripe;
            }

    //모든 토마토가 익어있는 상태라면 0 출력하고 종료
    if(q.empty()) {
        printf("0\n");
        return 0;
    }

    while(!q.empty()) {
        Tomato t = q.front();
        q.pop();

        // 6방향 탐색
        for(int i = 0 ; i < 6 ; ++i) {
            int nextZ = t.z + dz[i];
            int nextY = t.y + dy[i];
            int nextX = t.x + dx[i];
            int nextDay = t.day + 1;

            if(nextZ >= 0 && nextZ < h && nextY >= 0 && nextY < n && nextX >= 0 && nextX < m // 다음 탐색 범위가 벗어나지 않고
               && box[nextZ][nextY][nextX] == 0) { // 토마토가 아직 안익었다면
                Tomato tmp(nextZ, nextY, nextX, nextDay);
                q.push(tmp);
                box[nextZ][nextY][nextX] = 1; // 토마토를 익히고
                unripe--; // 익은 토마토 개수 줄임
                if(!unripe) { // 모든 토마토가 다 익었다면 마지막 토마토가 익은 날을 출력 후 리턴
                    printf("%d\n",nextDay);
                    return 0;
                }
            }
        }
    }

    // 안익은 토마토가 남아있다면
    if(unripe) {
        printf("-1\n");
    } else {
        printf("0\n");
    }
    return 0;
}