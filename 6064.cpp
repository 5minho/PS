//
// Created by 오민호 on 2017. 4. 19..
//

#include <cstdio>
#include <cstdlib>

int extended_euclid(int r0, int r1) {
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;

    while(r1) {
        int q = r0 / r1;
        int r = r0 - q * r1;
        r0 = r1;
        r1 = r;

        int s = s0 - q * s1;
        s0 = s1;
        s1 = s;

        int t = t0 - q * t1;
        t0 = t1;
        t1 = t;
    }

    return r0;
}

int solve(int M, int N, int x, int y) {
    int r = extended_euclid(M , N);
    if((x - y) % r) return -1;

    int a = 0, b = 0;
    while(1) {
        if(M * a + x > N * b + y) b++;
        else if (M * a + x < N * b + y) a++;
        else break;
    }
    return a * M + x;
}

int main() {
    int T = 0;
    int M, N, x, y;
    scanf("%d",&T);

    for(int i = 0 ; i < T ; ++i) {
        scanf("%d %d %d %d",&M, &N, &x, &y);
        printf("%d\n",solve(M, N, x, y));
    }

    return 0;
}

