//
// Created by 오민호 on 2017. 5. 18..
//

#include <cstdio>
#include <vector>

int computer = 0; // 컴퓨터 개수
int pair = 0; // 컴퓨터 쌍의 개수
bool visited[101];

int dfs(std::vector<std::vector<int> >& network, int here) {
    int ret = 0;
    //here번 컴퓨터는 확인함
    visited[here] = true;
    //here번 컴퓨터에 연결되어 있는 컴퓨터를 확인한다
    for(int i = 0 ; i < network[here].size() ; ++i) {
        int there = network[here][i];
        //there번 컴퓨터를 확인 안했다면 확인함
        if(!visited[there])
            ret += dfs(network, there) + 1;
    }
    return ret;
}

int main() {
    //computer 개수 입력
    scanf("%d",&computer);
    //graph를 구성할 배열 생성
    std::vector<std::vector<int> > network(computer + 1);
    //pair 입력
    scanf("%d",&pair);

    for(int i = 0 ; i < pair ; ++i) {
        int c1, c2;
        scanf("%d %d",&c1,&c2); // 컴퓨터 쌍을 입력 받아서
        network[c1].push_back(c2); // 네트워크 구성
        network[c2].push_back(c1);
    }

    // 1번 컴퓨터가 바이러스가 걸렸을때 감염되는 컴퓨터수를 dfs를 통해 구한다.
    printf("%d\n", dfs(network, 1));

}