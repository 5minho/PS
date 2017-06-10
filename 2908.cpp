//
// Created by 오민호 on 2017. 6. 10..
//

#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::string num1, num2;
    std::cin >> num1 >> num2;
    for(int i = 2 ; i >=0 ; --i) {
        if(num1[i] == num2[i]) continue;
        if (num1[i] > num2[i]) {
            std::cout << num1[2] << num1[1] << num1[0] << "\n";
            break;
        } else {
            std::cout << num2[2] << num2[1] << num2[0] << "\n";
            break;
        }
    }
}