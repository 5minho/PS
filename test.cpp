#include <cstdio>
#include <vector>

using namespace std;

int c = 0;

void pick(int n, vector<int>& picked, int toPick) {
    if(toPick == 0) {
        c++;
        printf("(%d %d %d)",picked[0], picked[1], picked[2]);
        return;
    }
    int small = picked.empty() ? 0 : picked.back() + 1;
    for(int next = small ; next < n ; ++next) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main() {
    vector<int> vec;
    pick(1500, vec, 3);
    printf("%d\n",c);
}
