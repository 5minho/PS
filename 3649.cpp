//
// Created by 오민호 on 2017. 5. 12..
//

#include <cstdio>
#include <vector>
#include <algorithm>

const int nm = 10000000;
int n = 0;
int widthOfHole = 0;
std::vector<int> lengthSet;

int biSearch(int findValue, int l1) {
    int low = l1;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(lengthSet[mid] == findValue) {
            return mid;
        }
        if(lengthSet[mid] < findValue) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    bool find;

    while (scanf("%d", &widthOfHole) == 1) {
        widthOfHole *= nm;
        scanf("%d",&n);
        lengthSet.assign(n,0);
        for(int i = 0 ; i < n ; ++i)
            scanf("%d",&lengthSet[i]);

        std::sort(lengthSet.begin(), lengthSet.end());
        find = false;
        for(int l1 = 0 ; l1 < n ; ++l1) {
            int l2 = biSearch(widthOfHole - lengthSet[l1], l1 + 1);
            if(l2 != -1) {
                find = true;
                printf("yes %d %d\n",lengthSet[l1], lengthSet[l2]);
                break;
            }
        }
        if(!find)
            printf("danger\n");
    }
    return 0;
}