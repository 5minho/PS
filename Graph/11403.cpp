//
// Created by 오민호 on 2017. 6. 30..
//

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> adj;
int main() {
    std::cin >> N;
    adj.assign(N, std::vector<int>(N, 0));
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            std::cin >> adj[i][j];
    for(int k = 0 ; k < N ; ++k)
        for(int i = 0 ; i < N ; ++i)
            for(int j = 0 ; j < N ; ++j)
                adj[i][j] = adj[i][j] || adj[i][k] && adj[k][j];
    for(int i = 0 ; i < N ; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << adj[i][j] << " ";
        }
        std::cout << "\n";
    }

}
