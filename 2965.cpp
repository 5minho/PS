//
// Created by 오민호 on 2017. 5. 30..
//

#include <cstdio>
#include <algorithm>

int A,B,C;

int main() {
    scanf("%d%d%d",&A,&B,&C);
    int ret = std::max(B - A, C - B);
    printf("%d\n",ret - 1);
}