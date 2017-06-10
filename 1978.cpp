//
// Created by 오민호 on 2017. 5. 10..
//

#include <cstdio>
#include <cmath>

int n = 0;
bool isPrime(int n) {
    if(n == 1) return false;
    if(n == 2) return true;
    if(!(n % 2)) return false;
    int sqrtn = int(sqrt(n));
    for(int i = 3 ; i <= sqrtn ; i += 2)
        if(!(n % i)) return false;
    return true;
}

int main() {
    scanf("%d",&n);
    int ans = 0;
    for(int i = 0 ; i < n ; ++i) {
        int num;
        scanf("%d",&num);
        if(isPrime(num)) ans++;
    }
    printf("%d\n",ans);
}