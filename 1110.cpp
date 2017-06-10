#include <stdio.h>

int main() {
    freopen("./InputFiles/1110.in", "r", stdin);
    int c = 0;
    scanf("%d",&c);
    int d = c;
    int l = 0;
    while(1) {
        int right = c % 10;
        int left = (c < 10) ? 0 : (c / 10);
        int new_num = left + right;
        c = right * 10 + new_num % 10;
        ++l;
        if(c == d) break;
    }
    printf("%d\n",l); 
    return 0;
}