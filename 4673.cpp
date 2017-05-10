//
// Created by 오민호 on 2017. 5. 10..
//

#include <cstdio>
#include <cstring>

const int MAX = 10000;
bool isSelfNum[MAX + 1];

int nextNum(int n) {
    int ret = n;
    while(n / 10) {
        int mod = n % 10;
        n /= 10;
        ret += mod;
    }
    ret += n % 10;
    return ret;
}

int main() {
    memset(isSelfNum,1,sizeof(isSelfNum));
    for(int i = 1 ; i <= MAX ; ++i) {
        if(isSelfNum[i]) {
            for(int j = i ; j <= MAX ;) {
                isSelfNum[j = nextNum(j)] = false;
            }
        }
    }
    for(int i = 1 ; i <= MAX ; ++i) {
        if(isSelfNum[i]) printf("%d\n",i);
    }
}