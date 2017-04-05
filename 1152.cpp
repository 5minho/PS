//
// Created by 오민호 on 2017. 4. 6..
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string str;
string buf;
vector<string> tokens;

int main() {
    getline(cin, str);
    stringstream ss(str);
    while(ss >> buf) {
        tokens.push_back(buf);
    }
    cout << tokens.size();
}