#include <iostream>

int count = 0;

bool makeTarget(int target, int num) {
        if(target < num) return false;
            if(target == num) return true;
                if(makeTarget(target, num + 5) || makeTarget(target, num + 3)) {
                            count++;
                                    return true;
                                        }
                    return false;
}

int main(void) {
        int target = 0;
            std::cin >> target;
                if(makeTarget(target, 0)) std::cout << count << std::endl;
                    else std::cout << -1 << std::endl;
}
