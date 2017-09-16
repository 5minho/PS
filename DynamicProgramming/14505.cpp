//
// Created by 오민호 on 2017. 9. 16..
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    string s;
    std::cin >> s;

    int len = s.size();

    vector<std::vector<int>> dp(len + 1, vector<int>(len + 1));

    for (int i = 0; i < len; ++i)
    {
        dp[i][i] = 1;
        dp[i][i + 1] = (s[i] == s[i + 1]) ? 3 : 2;

    }

    for (int l = 2; l < len; ++l)
    {
        for (int left = 0; left < len - l; ++left)
        {
            int right = left + l;

            dp[left][right] = dp[left + 1][right] + dp[left][right - 1] - dp[left + 1][right - 1];

            if (s[left] == s[right])
                dp[left][right] += dp[left + 1][right - 1] + 1;

        }
    }

    cout << dp[0][len - 1] << "\n";

    return 0;
}