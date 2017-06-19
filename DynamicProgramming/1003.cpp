//
// Created by 오민호 on 2017. 5. 11..
//

#include <cstdio>
#include <cstring>
#include <vector>


struct zeroAndone {
    int zero;
    int one;
    zeroAndone operator+(const zeroAndone& ref) {
        zeroAndone ret = {this->zero + ref.zero, this->one + ref.one};
        return ret;
    }
};

int T = 0;

int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        int num = 0;
        scanf("%d",&num);
        zeroAndone arr[41];
        arr[0] = {1,0};
        arr[1] = {0,1};
        for(int i = 2 ; i <= num ; ++i)
            arr[i] = arr[i-1] + arr[i-2];
        printf("%d %d\n",arr[num].zero, arr[num].one);
    }
}