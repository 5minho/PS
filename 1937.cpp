//
//  main.cpp
//  TestXcodeProjs
//
//  Created by 오민호 on 2017. 3. 8..
//  Copight © 2017년 오민호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 500;
int n = 0;
//맵
int map[MAX][MAX];
//(y,x)에서 출발하면 살수 있는 최종 생존일 수 저장
int cache[MAX][MAX];
//방향 배열
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
//(y, x)에서 출발하면 얼마나 살수 있는가!!
int getSurvivalDays(int y, int x) {
    int& ret = cache[y][x];
    //이미 지나간 경로이면 그 경로에 대한 생존일 수 반환;
    if(ret != -1) return ret;
    ret = 1;
    for(int next = 0 ; next < 4; ++next) {
        int nextY = dy[next] + y;
        int nextX = dx[next] + x;
        //경로 이탈 이거나 다음 경로의 대나무양이 현재보다 적다면
        if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || map[nextY][nextX] < map[y][x] ) continue;
        ret = max(ret, getSurvivalDays(nextY, nextX) + 1);
    }
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> map[i][j];
    int maxSurvivalDays = 0;
    for(int i = 0; i < n ; ++i)
        for(int j = 0; j < n ; ++j)
            maxSurvivalDays = max(maxSurvivalDays, getSurvivalDays(i, j));
    cout << maxSurvivalDays << endl;
}
