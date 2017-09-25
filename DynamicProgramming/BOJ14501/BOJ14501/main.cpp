//
//  main.cpp
//  BOJ14501
//
//  Created by 오민호 on 2017. 9. 26..
//  Copyright © 2017년 Minomi. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::ios::sync_with_stdio(false);
    int N = 0;
    std::cin >> N;
    
    std::vector<int> T(N + 1);
    std::vector<int> P(N + 1);
    std::vector<int> dp(N + 1);
    
    for(int i = 1 ; i <= N ; ++i) {
        std::cin >> T[i] >> P[i];
        dp[i] = P[i];
    }
    
    for(int i = 2; i <= N ; ++i) {
        for(int j = 1 ; j < i ; ++j) {
            if (i - j >= T[j]) {
                dp[i] = std::max(dp[j] + P[i], dp[i]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1 ; i <= N ; ++i) {
        if (i + T[i] <= N + 1)
            ans = std::max(dp[i], ans);
    }
    
    std::cout << ans;
    return 0;
}
