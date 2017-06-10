//
// Created by 오민호 on 2017. 5. 31..
//

#include <cstdio>
#include <cstring>

int dp[11];
int t = 0;

int plusOneTwoTree(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    int& ret = dp[n];
    if(ret != 0) return ret;
    ret = plusOneTwoTree(n - 1) + plusOneTwoTree(n - 2) + plusOneTwoTree(n - 3);
    return ret;
}

int main() {
    scanf("%d",&t);
    for(int i = 0 ; i < t ; ++i) {
        int N;
        scanf("%d", &N);
        memset(dp, 0, sizeof(dp));
        printf("%d\n",plusOneTwoTree(N));
    }
}