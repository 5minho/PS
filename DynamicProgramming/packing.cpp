//
// Created by 오민호 on 2017. 7. 8..
//

#include <iostream>
#include <vector>
#include <cstring>

struct Item{
    std::string name;
    int volume;
    int need;
};

int C;
int N, W;
int cache[1001][101];
std::vector<Item> items;
int pack(int capacity, int item) {
    if (item > N) return 0;
    int& ret = cache[capacity][item];
    if(ret != -1) return ret;
    ret = pack(capacity , item + 1);
    if(capacity >= items[item].volume)
        ret = std::max(ret, pack(capacity - items[item].volume, item + 1) + items[item].need);
    return ret;
}

void reconstruct(std::vector<std::string>& itemNames, int capacity, int item) {
    if(item > N) return;
    if(pack(capacity, item + 1) == pack(capacity, item))
        reconstruct(itemNames, capacity , item + 1);
    else {
        itemNames.push_back(items[item].name);
        reconstruct(itemNames, capacity - items[item].volume, item + 1);
    }
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> C;
    while(C--) {
        memset(cache, -1, sizeof(cache));
        std::cin >> N >> W;
        items.clear();
        items.resize(N + 1);
        for(int i = 1 ; i <= N ; ++i)
            std::cin >> items[i].name >> items[i].volume >> items[i].need;

        int needSum = pack(W, 0);
        std::vector<std::string> picked;
        reconstruct(picked, W, 0);

        std::cout << needSum << " " << picked.size() << "\n";
        for(auto name : picked)
            std::cout << name << "\n";
    }
}