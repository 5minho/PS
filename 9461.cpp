//
// Created by 오민호 on 2017. 5. 30..
//

#include <cstdio>
#include <cstring>

const int MAX = 101;

int T;
int main() {
    scanf("%d", &T);
    for(int i = 0 ; i < T ; ++i) {
        int N;
        scanf("%d",&N);
        unsigned long long dp[MAX] = {0, 1, 1, 1, 2, 2, };
        for(int j = 6 ; j <= N ; ++j)
            dp[j] = dp[j - 1] + dp[j - 5];
        printf("%lld\n",dp[N]);
    }
}