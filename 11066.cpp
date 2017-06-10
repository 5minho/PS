//
// Created by 오민호 on 2017. 5. 29..
//

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

const int MAX = 501;
const int INF = 987654321;

int T = 0;
std::vector<int> files;
int cache[MAX][MAX];
int psum[MAX];

//파일 from 번 부터 to번 까지 합치는 최소비용 반환
int minCostCombineFile(int from, int to) {
    if(from == to) return 0;     //기저사례
    int& ret = cache[from][to];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = from ; i < to ; ++i)
        ret = std::min(ret, minCostCombineFile(from, i) + minCostCombineFile(i + 1, to) + psum[to] - psum[from - 1]);
    return ret;
}
int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        memset(cache, -1, sizeof(cache));
        memset(psum, 0, sizeof(psum));
        int k;
        scanf("%d",&k);
        files.resize(k + 1);
        for(int j = 1 ; j <= k ; ++j)
            scanf("%d", &files[j]), psum[j] = psum[j - 1] + files[j];
        printf("%d\n",minCostCombineFile(1, k));
    }
}