//
// Created by 오민호 on 2017. 5. 12..
//

#include <iostream>
#include <vector>
#include <algorithm>

const int MAX = 1000;
int n = 0;
std::vector<int> weights;


int main() {
    std::cin.sync_with_stdio(false);
    std::cin >> n;
    weights.assign(n, 0);

    for(int i = 0 ; i < n ; ++i)
        std::cin >> weights[i];
    std::sort(weights.begin(), weights.end());
    if(weights[0] != 1) std::cout<<"1\n";
    else {
        int sum = weights[0];
        for(int i = 1 ; i < weights.size() && sum + 1 >= weights[i] ; ++i)
            sum += weights[i];
        std::cout << sum + 1 << "\n";
    }
    return 0;
}