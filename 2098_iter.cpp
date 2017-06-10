//
// Created by 오민호 on 2017. 6. 1..
//

#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX = 16;
const int INF = 987654321;
//dist[a][b] : a -> b 가는 비용
int dist[MAX][MAX];
//dp[state][a] : 현재 state 에서 마지막으로 도착한 도시가 a 일때 최소비용
int dp[1 << MAX][MAX];
int N = 0;
int main() {
//    scanf("%d",&N);
//    for(int i = 0 ; i < N ; ++i)
//        for(int j = 0 ; j < N ; ++j) {
//            scanf("%d",&dist[i][j]);
//            if((i != j) && !dist[i][j]) dist[i][j] = INF;
//        }
//    for(int state = 1 ; state < (1 << N) ; ++state)
//        for(int i = 0 ; i < N ; ++i)
//            dp[state][i] = INF;
//    dp[1][0] = 0;
//
//    for(int currentState = 1 ; currentState < (1 << N) ; ++currentState) {
//        for(int here = 0 ; here < N ; ++here) {
//            if(dp[currentState][here] == INF) continue;
//            for(int next = 0 ; next < N ; ++ next) {
//                int nextState = currentState | (1 << next);
//                if(nextState == currentState) continue;
//                dp[nextState][next] = std::min(dp[nextState][next], dp[currentState][here] + dist[here][next]);
//            }
//        }
//    }
//    int ans = INF;
//    for(int i = 0 ; i < N ; ++i)
//        ans = std::min(ans, dp[(1 << N) - 1][i] + dist[i][0]);
//    printf("%d",ans);

    printf("%-10s : %s\n","abd", "A");
    printf("%-10s : %s\n","abdd", "A");
    printf("%-10s : %s\n","abd", "A");

}