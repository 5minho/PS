//
// Created by 오민호 on 2017. 6. 17..
//

#include <iostream>
#include <stack>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::stack<int> stack;
    std::vector<std::string> result;
    int input;
    int num = 0;
    int max = 0;

    while(n--) {
        std::cin >> input;
        if (max < input) { // push
            int count = input - max;
            while (count--) {
                result.push_back("+");
                stack.push(++num);
            }
            stack.pop();
            result.push_back("-");
            max = input;
        } else { // pop
            result.push_back("-");
            if(stack.top() != input) {
                std::cout << "NO" << std::endl;
                return 0;
            }
            stack.pop();
        }
    }

    for(std::string s : result) {
        std::cout << s;
        std::cout << "\n";
    }
    return 0;
}