//
// Created by 오민호 on 2017. 4. 21..
//

#include <stdio.h>

int main() {
    int T = 0;
    int a = 0,b = 0;
    int cnt[10] = {1,1,4,4,2,1,1,4,4,2};
    int tmp[10][4] = {
            {0},
            {1},
            {6,2,4,8},
            {1,3,9,7},
            {6,4},
            {5},
            {6},
            {1,7,9,3},
            {6,8,4,2},
            {1,9}
    };

    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        scanf("%d %d",&a,&b);
        int x = a % 10;
        int com = tmp[x][b % cnt[x]];
        if(!com) printf("10\n");
        else printf("%d\n",com);
    }
}