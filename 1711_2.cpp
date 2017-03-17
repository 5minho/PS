#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int MAX = 1000000000;
typedef pair<int, int> coord;

class Node {
    public:
        int x, y;
        int from, to;
        vector<coord> left;
        vector<coord> right;
        Node(int _x, int _y): x(_x), y(_y) {} 
};

typedef vector<Node> Event;

int main() {
    int n  = 0;
    scanf("%d",&n);
    vector<coord> coords(n); 
//    vector<coord> count(MAX, make_pair(0, 0)); 
    for(int i = 0 ; i < n; ++i) {
        scanf("%d %d",&coords[i].first, &coords[i].second);
       // count[coords[i].first].first++; count[coords[i].second].second++;
        //printf("%d %d",coords[i].first, coords[i].second);
    }
    sort(coords.begin(), coords.end()); 
    vector<Event> events;
    for(int i = 0 ; i < coords.size() ; i++) {
        Event e;
        int x = coords[i].first;
        while(x == coords[i].first && i < coords.size()) {
            e.push_back(Node(coords[i].first, coords[i].second));
            ++i;
        }
        printf("%d\n",i);
        printf("%d\n",events.size());
        events.push_back(e);
    }

    printf("event size : %ld",events.size());
    for(int i = 0 ; i < events.size() ; ++i) {
        vector<coord> left;
        vector<coord> right;
        //처음 이벤트
        for(int j = 0 ; j < events.size() ; ++j) {
            printf("event[i] size : %d",events[i].size());
            if(i == j) continue;
            for(int k = 0 ; k < events[j].size() ; ++k) {
                if(i > j) left.push_back(make_pair(events[i][j].x - events[j][k].x, events[i][j].y - events[j][k].y));
                else right.push_back(make_pair(events[i][j].x - events[j][k].x, events[i][j].y - events[j][k].y ));
            }
            events[i][j].left = left;
            events[i][j].right = right;
        }
    }

    for(int i = 0 ; i < events.size() ; ++i) {
        for(int j = i ; j < events[i].size() ; ++j) {
            for(int k = 0 ; k < events[j].size(); ++k) {
                printf("event[%d] 의 right vector : (%d, %d)\n",i,(events[i][j].left)[k].first, events[i][j].left[k].second); 
                printf("event[%d] 의 left vector : (%d, %d)",i, (events[i][j].left)[k].first, events[i][j].left[k].second);
            }
            printf("\n");
        }
    }
}
