//
// Created by 오민호 on 2017. 6. 24..
//

#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    int N,M,K;
    std::cin >> N >> M;
    std::vector<std::vector<int>> m1(N, std::vector<int>(M, 0));
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j)
            std::cin >> m1[i][j];
    std::cin >> M >> K;
    std::vector<std::vector<int>> m2(M, std::vector<int>(K, 0));
    for(int i = 0 ; i < M ; ++i)
        for(int j = 0 ; j < K ; ++j)
            std::cin >> m2[i][j];
    std::vector<std::vector<int>> m3(N, std::vector<int>(K, 0));
    for(int i = 0 ; i < N ; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < M; ++k) {
                m3[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }

    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < K ; ++j) {
            std::cout << m3[i][j] << " ";
        }
        std::cout << "\n";
    }
}