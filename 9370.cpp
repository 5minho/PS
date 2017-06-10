//
// Created by 오민호 on 2017. 5. 16..
//

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

const int INF = 987654321;

int T = 0;

struct Edge {
    int u,v;
    int w;
};

struct Dist {
    int d;
};
int main() {
    scanf("%d",&T);
    for(int i = 0 ; i < T ; ++i) {
        Edge edges[100002];
        int candi[101];
        Dist dist1[2001];
        Dist dist2[2001];

        int n,m,t;
        int s,g,h;

        scanf("%d %d %d",&n,&m,&t);
        scanf("%d %d %d",&s,&g,&h);

        for(int j = 1 ; j <= 2 * m ; j += 2) {
            scanf("%d %d %d", &edges[j].u, &edges[j].v, &edges[j].w);
            edges[j + 1].u = edges[j].v;
            edges[j + 1].v = edges[j].u;
            edges[j + 1].w = edges[j].w;
        }

        for(int j = 0 ; j < t ; ++j)
            scanf("%d", &candi[j]);

        for(int j = 1 ; j <= n ; ++j) {
            dist1[j].d = INF;
            dist2[j].d = INF;
        }

        dist1[s].d = 0;

        int change = 1;
        int temp = 0;

        while(change) {
            change = 0;
            for(int k = 1 ; k <= 2 * m ; ++k) {
                if(dist1[edges[k].v].d > (temp = dist1[edges[k].u].d + edges[k].w)) {
                    dist1[edges[k].v].d = temp;
                }
            }
        }

        int x = dist1[g].d > dist1[h].d ? g : h;
        dist2[x].d = 0;
        change = 1;
        while(change) {
            change = 0;
            for(int k = 1 ; k <= 2 * m ; ++k) {
                if(dist2[edges[k].v].d > (temp = dist2[edges[k].u].d + edges[k].w)) {
                    dist2[edges[k].v].d = temp;
                    change = 1;
                }

            }
        }

        std::sort(candi , candi + t);
        for(int j = 0 ; j < t ; ++j) {
            if(dist1[x].d + dist2[candi[j]].d == dist1[candi[j]].d)
                printf("%d ",candi[j]);
        }
        printf("\n");
    }
    return 0;
}
