//
// Created by 오민호 on 2017. 11. 18..
//

#include<iostream>
#include<vector>
#include<cstring>

int cache[501];
int C, N;

std::vector<int> progression;
std::vector<int> choice;

int lis(int n) {

    int& ret = cache[n + 1];
    if (ret != -1)
        return ret;

    ret = 1;
    int bestNext = -1;

    for(int i = n + 1 ; i < N ; ++i)
        if (n == -1 || progression[n] < progression[i]) {
            int cand = lis(i) + 1;
            if (ret < cand) {
                ret = cand;
                bestNext = i;
            }
        }

    choice[n + 1] = bestNext;
    return ret;

}

void reconstruct(int start, std::vector<int>& seq) {
    if (start != -1) seq.push_back(progression[start]);
    int next = choice[start + 1];
    if (next != -1) reconstruct(next, seq);
}

int main() {
    std::cin >> C;

    while(C--) {
        memset(cache, -1, sizeof(cache));

        std::cin >> N;
        progression.resize(N);
        choice.assign(N + 1, -1);

        for(int i = 0 ; i < N ; ++i)
            std::cin >> progression[i];

        int ans = lis(-1) - 1;

        std::cout << ans <<"\n";

        std::vector<int> seq;
        reconstruct(0, seq);

        for(auto n : seq)
            std::cout << n << " ";

        std::cout << "\n";
    }

    return 0;

}