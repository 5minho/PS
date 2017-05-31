//
// Created by 오민호 on 2017. 5. 28..
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

std::string s1;
std::string s2;
const int MAX = 1001;
int dp[MAX][MAX];

void backTracking(int i, int j) {
    if(i == 0 || j == 0) return;
    else if(s1[i - 1] == s2[j - 1]) backTracking(i - 1, j - 1), std::cout << s1[i - 1];
    else dp[i - 1][j] > dp[i][j - 1] ? backTracking(i - 1, j) : backTracking(i, j - 1);
}

int main() {
    memset(dp, 0, sizeof(dp));
    std::cin >> s1 >> s2;
    for(int i = 1 ; i <= s1.size(); ++i)
        for(int j = 1 ; j <= s2.size() ; ++j)
            dp[i][j] = ((s1[i - 1] == s2[j - 1]) ? dp[i - 1][j - 1] + 1 : std::max(dp[i][j - 1], dp[i - 1][j]));
    std::cout << dp[s1.size()][s2.size()] << "\n";
    backTracking(s1.size(), s2.size());

}