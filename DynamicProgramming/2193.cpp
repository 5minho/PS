//
// Created by 오민호 on 2017. 5. 31..
//

#include <cstdio>
#include <cstring>

const int MOD = 10007;
unsigned long long cache[91];

unsigned long long f(int n) {
    if(n == 1 || n == 2) return 1;
    unsigned long long& ret = cache[n];
    if(ret != -1) return ret;
    ret =  f(n - 1) + f(n - 2);
    return ret;
}

int main() {
    int n;
    memset(cache, -1, sizeof(cache));
    scanf("%d",&n);
    printf("%lld",f(n));
}