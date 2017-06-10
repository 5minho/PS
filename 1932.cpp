//
// Created by 오민호 on 2017. 5. 25..
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
std::vector<std::vector<int> > triangle;

int n = 0;
int cache[500][500];

int goDown(int y, int x) {
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    if(y == n - 1) return triangle[y][x];
    ret = triangle[y][x];
    ret += std::max(goDown(y + 1, x + 1), goDown(y + 1, x));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d",&n);
    triangle.assign(n, std::vector<int>(n + 1));
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < i + 1 ; ++j)
            scanf("%d",&triangle[i][j]);
    }
    printf("%d\n", goDown(0, 0));
}