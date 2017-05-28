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
int cache[MAX][MAX];

int lcs(int s1Idx, int s2Idx) {
    if(s1Idx == -1 || s2Idx == - 1) return 0;
    int& ret = cache[s1Idx][s2Idx];
    if(ret != -1) return ret;
    if(s1[s1Idx] == s2[s2Idx]) ret =  lcs(s1Idx - 1, s2Idx - 1) + 1;
    else ret = std::max(lcs(s1Idx - 1, s2Idx), lcs(s1Idx, s2Idx - 1));
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    std::cin >> s1 >> s2;
    std::cout << lcs(s1.size() - 1, s2.size() - 1);
}