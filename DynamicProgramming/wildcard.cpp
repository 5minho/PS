//
// Created by 오민호 on 2017. 11. 16..
//


#include <iostream>
#include <vector>
#include <cstring>

std::string W;
std::string S;

int cache[101][101];

int match(int w, int s) {

    int& ret = cache[w][s];
    if (ret != -1) {
        return ret;
    }

    if(w < W.length() && s < S.length() &&
            (W[w] == '?' || W[w] == S[s])) {
        return (ret = match(w + 1, s + 1));
    }

    if (w == W.length())
        return ret = (s == S.length() ? 1 : 0);

    if (W[w] == '*') {
        if(match(w + 1, s) || (s < S.length() && match(w, s + 1)))
            return ret = 1;
    }

    return ret = 0;

}

int N;

int main() {

    std::cin >> N;

    for(int i = 0 ; i < N ; ++i) {
        std::vector<std::string> answers;

        int n = 0;
        std::cin >> W;
        std::cin >> n;
        for(int j = 0 ; j < n ; ++j) {
            memset(cache, -1, sizeof(cache));
            std::cin >> S;
            if (match(0, 0) == 1)
                answers.push_back(S);
        }

        sort(answers.begin(), answers.end());
        for (auto s : answers) {
            std::cout << s << "\n";
        }

    }


}