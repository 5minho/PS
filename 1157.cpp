//
// Created by 오민호 on 2017. 4. 20..
//
#include <iostream>
#include <algorithm>
#include <string>


int main() {
    int alphaCount[26] = {0,};
    std::string word;
    getline(std::cin, word);
    int maxCnt = 0;
    char maxAlpha = 0;
    for(size_t i = 0 ; i < word.size() ; ++i) {
        if(word[i] < 'a') {
            maxCnt = std::max(maxCnt, ++alphaCount[word[i] - 'A']);
        }
        else {
            maxCnt = std::max(maxCnt, ++alphaCount[word[i] - 'a']);
        }
    }

    int cnt = 0;
    int idx = 0;
    for(size_t i = 0 ; i < 26; ++i) {
        if(maxCnt == alphaCount[i]) {
            cnt++;
            idx = i;
        }
    }

    if(cnt > 1) std::cout << "?" << std::endl;
    else  std::cout << (char)(idx + 'A')<< std::endl;

}