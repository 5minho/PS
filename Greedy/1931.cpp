//
// Created by 오민호 on 2017. 5. 9..
//

#include <cstdio>
#include <algorithm>

typedef long long ll;

const int MAX = 100001;
int n = 0;

struct MeetingTime {
    ll start;
    ll end;

    bool operator== (const MeetingTime& ref) {
        return (start == ref.start) && (end == ref.end);
    }

    bool operator!= (const MeetingTime& ref) {
        return !((start == ref.start) && (end == ref.end));
    }
};

bool operator < (const MeetingTime& ref1, const MeetingTime& ref2) {
    if(ref1.end == ref2.end)
        return ref1.start < ref2.start;
    return ref1.end < ref2.end;
}

MeetingTime meetings[MAX];

int main() {
    int ans = 1;
    std::scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i)
        scanf("%lld %lld", &meetings[i].start , &meetings[i].end);
    std::sort(&meetings[0], &meetings[n + 1]);

    MeetingTime curTime = meetings[1];

    for(int i = 2 ; i <= n ; ++i) {
        if(curTime.end <= meetings[i].start) {
            ans++;
            curTime = meetings[i];
        }
    }

    printf("%d\n",ans);
    return 0;
}