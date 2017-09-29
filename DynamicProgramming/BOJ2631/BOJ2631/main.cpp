//
//  main.cpp
//  BOJ2631
//
//  Created by 오민호 on 2017. 9. 30..
//  Copyright © 2017년 Minomi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    std::ios::sync_with_stdio(false);
    
    std::cin >> N;
    std::vector<int> children;
    
    for(int i = 0 ; i < N ; ++i) {
        int here = 0;
        std::cin >> here;
        auto pos = std::lower_bound(children.begin(), children.end(), here);
        if (pos == children.end())
            children.push_back(here);
        else
            std::swap(here, *pos);
    }
    
    std::cout << N - children.size() << "\n";
    return 0;
}
