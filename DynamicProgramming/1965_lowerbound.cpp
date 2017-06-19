//
// Created by 오민호 on 2017. 6. 12..
//

//
// Created by 오민호 on 2017. 6. 12..
//

#include <iostream>
#include <algorithm>

const int MAX = 1001;
int boxes[MAX];
int lis[MAX];
int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1 ; i <= n ; ++i)
        std::cin >> boxes[i];
    int it;
    int size = 1;
    lis[1] = boxes[1];
    for(int i = 2 ; i <= n ; ++i) {
        if(lis[size] < boxes[i]) {
            size++;
            lis[size] = boxes[i];
            continue;
        }
        it = std::lower_bound(lis + 1, lis + size + 1, boxes[i]) - lis;
        lis[it] = boxes[i];
    }
    std::cout << size;
}