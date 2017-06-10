//
// Created by 오민호 on 2017. 5. 10..
//

#include <cstdio>
#include <algorithm>
#include <cstring>

const int MAX = 1001;
//const int NINF = 987654321 * -1;
int s[MAX];
int cache[MAX];
int n = 0;

//lis(start) = S[Start]에서 시작하는 부분증가수열 중 최대 합
int lis(int start) {
    if(start == n) return s[n];
    int& ret = cache[start];
    if(ret != -1) return ret;

    ret = s[start];

    for(int i = start + 1 ; i <= n ; ++i) {
        if(s[start] < s[i])
            ret = std::max(ret , s[start] + lis(i));
    }
    return ret;
}

int main() {
    int ans = -987654321;
    memset(cache , -1 , sizeof(cache));
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i) {
        scanf("%d",&s[i]);
    }

    for(int i = 1 ; i <= n ; ++i)
        ans = std::max(ans , lis(i));

    printf("%d\n",ans);
}