#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int stairsNum = 301;
int cache[stairsNum][2];

int getMaxScore(vector<int>& stairs, int x, int c) {
    if(c == 0 || x < 0) return 0;
    int& ret = cache[x][c];
    if(ret != -1) return ret;
    if(x == 0) return stairs[x];
    ret = max(getMaxScore(stairs, x - 2, 2), getMaxScore(stairs, x - 1, c - 1)) + stairs[x];
    return cache[x][c] = ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    int n = 0;
    scanf("%d",&n);
    vector<int> stairs(n);
    for(int i = 0 ; i < n ; ++i) 
        scanf("%d",&stairs[i]);
    printf("%d\n",getMaxScore(stairs, n - 1, 2));
}
