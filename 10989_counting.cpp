//
// Created by 오민호 on 2017. 6. 10..
//

#include <cstdio>
#include <algorithm>

int N;
int count[10001];
int main() {
    scanf("%d",&N);
    int maxN = 0;
    for(int i = 1 ; i <= N ; ++i) {
        int n;
        scanf("%d",&n);
        maxN = std::max(maxN, n);
        count[n]++;
    }
    for(int i = 1 ; i <= maxN ; ++i) {
        for(int j = 1 ; j <= count[i] ; ++j)
            printf("%d\n",i);
    }
}