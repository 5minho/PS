//
// Created by 오민호 on 2017. 5. 25..
//

#include <cstdio>
#include <cstring>
int n,k;
int coins[100];
int value[10001];

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d", &coins[i]);
    value[0] = 1;
    for(int i = 0 ; i < n ; ++i) {
       for(int j = coins[i] ; j <= k ; ++j) {
           //0...i번째 동전으로 j원을 만드는 방법 = 0...i - 1번째 동전으로 만들 수 있는 방법 수 + i번째 동전을 추가해서 만들 수 있는 방법 수
           value[j] = value[j] + value[j - coins[i]];
       }
    }
    printf("%d\n",value[k]);
}