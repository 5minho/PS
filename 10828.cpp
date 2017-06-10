//
// Created by 오민호 on 2017. 4. 20..
//

#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
const int capacity = 20000;


struct IntStack {
    typedef void (IntStack::*func)(int);
    std::map<std::string, func> funcMap;

    int m_arr[capacity];
    int m_pos;

public:
    IntStack(): m_pos(-1) {
        funcMap["push"] = &IntStack::push;
        funcMap["pop"] = &IntStack::pop;
        funcMap["size"] = &IntStack::size;
        funcMap["empty"] = &IntStack::empty;
        funcMap["top"] = &IntStack::top;
    }

    void call(std::string cmd, int x = -1) {
        //std::cout << cmd << " " << x <<  std::endl;
        (this->*funcMap[cmd])(x);
    }
    void push(int x) {
        if(m_pos < capacity - 1) m_arr[++m_pos] = x;
    }

    void size(int x) {
        printf("%d\n",m_pos + 1);
    }

    void empty(int x) {
        printf("%d\n",(m_pos == -1));
    }

    void pop(int x) {
        if(m_pos == -1) {
            printf("%d\n",m_pos);
            return;
        }
        printf("%d\n",m_arr[m_pos--]);
    }
    void top(int x) {
        printf("%d\n",(m_pos == -1) ? -1 : m_arr[m_pos]);
    }
};



int main() {
    int N = 0;
    scanf("%d",&N); getchar();
    IntStack stack;

    for(int i = 0 ; i < N ; ++i) {
        std::string cmd;
        getline(std::cin, cmd);
        if(!cmd.substr(0,4).compare("push")) {
            stack.call(cmd.substr(0,4), atoi(cmd.substr(5).c_str()));
            continue;
        }
        //std::cout<<cmd<<std::endl;
        //std::cout << (cmd.back() - 1) <<std::endl;
        stack.call(cmd);
    }
}