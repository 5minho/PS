//
// Created by 오민호 on 2017. 9. 20..
//

#include <iostream>
#include <vector>
#include <cstring>

const int INF = 987654321;
const int MAX = 1001;
int N,M;
int cache[MAX][MAX];

bool checkOutBound(int y, int x) {
    return (x <= 0 || y <= 0 || x > M || y > N);
}

int candy(std::vector<std::vector<int>>& map, int y, int x) {

    if (checkOutBound(y, x)) {
        return 0;
    }

    int& ret = cache[y][x];

    if (ret != -1)
        return ret;

    ret = std::max(std::max(candy(map, y, x - 1), candy(map, y - 1, x)), candy(map, y - 1, x - 1)) + map[y][x];
    return ret;

}

int main() {

    memset(cache, -1, sizeof(cache));

    std::ios::sync_with_stdio(false);
    std::cin >> N >> M;
    std::vector<std::vector<int>> map(N + 1, std::vector<int>(M + 1));

    for(int i = 1 ; i <= N ; ++i)
        for(int j = 1 ; j <= M ; ++j)
            std::cin >> map[i][j];



    std::cout << candy(map, N, M) << "\n";

    return 0;
}