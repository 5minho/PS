//
// Created by 오민호 on 2017. 6. 15..
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> arr(N, 0);
    for(int i = 0 ; i < N ; ++i)
        std::cin >> arr[i];

    std::vector<int> lis;
    lis.push_back(arr[0]);
    std::vector<int>::iterator iter;
    for(int i = 1 ; i < N ; ++i) {
        if(*(lis.end() - 1) < arr[i]) {
            lis.push_back(arr[i]);
            continue;
        }
        iter = std::lower_bound(lis.begin(), lis.end(), arr[i]);
        *iter = arr[i];
    }

    std::cout << lis.size();
}