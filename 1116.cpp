#include <stdio.h>
#include <vector>

int main() {
    freopen("./InputFiles/1116.in", "r", stdin);
    int n = 0;
    scanf("%d",&n);
    std::vector<int> arr(n);
    for(int i = 0 ; i < n ; ++i)
        scanf("%d",&arr[i]);
    for(int i = 0 ; i < n ; ++i)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}