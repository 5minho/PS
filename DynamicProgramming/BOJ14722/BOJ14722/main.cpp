//
//  main.cpp
//  test
//
//  Created by 오민호 on 2017. 9. 30..
//  Copyright © 2017년 Minomi. All rights reserved.
//
//
// Created by 오민호 on 2017. 9. 30..
//

#include <iostream>
#include <vector>
#include <cstring>

int N;
std::vector<std::vector<int>> milkCity;
int cache[3][1001][1001];

int drinkMilk(int y, int x, int current) {
    
    if (y >= N || x >= N) return -987654321;
    if (y == N - 1 && x == N - 1) return current == milkCity[y][x];
    
    int& ret = cache[current][y][x];
    if (ret != -1) return ret;
    
    int next = (current == milkCity[y][x]) ? (current + 1) % 3 : current;
    
    ret = std::max(drinkMilk(y + 1, x, next), drinkMilk(y, x + 1, next)) + (current == milkCity[y][x]);
    return ret;
    
}

int main() {
    
    memset(cache, -1, sizeof(cache));
    std::cin >> N;
    milkCity.assign(N, std::vector<int>(N));
    
    for(int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
            std::cin >> milkCity[i][j];
    
    std::cout << drinkMilk(0,0,0);
    
}
