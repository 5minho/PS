//
//  main.cpp
//  TestXcodeProjs
//
//  Created by 오민호 on 2017. 3. 8..
//  Copight © 2017년 오민호. All rights reserved.
//


#include <stdio.h>
#include <vector>
#define MAX 100000
#define MIN -1001

inline int max(int a, int b) {
    return (a>b) ? a : b;
}

int n = 0;

int main() {
    scanf("%d",&n);
    std::vector<int> arr(n);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d",&arr[i]);
    int ret = MIN;
    int psum = 0;
    for(int i = 0 ; i < n ; ++i) {
        psum = max(0, psum) + arr[i];
        ret = max(ret, psum);
    }
    printf("%d\n",ret);
}


