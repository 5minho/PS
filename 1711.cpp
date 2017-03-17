nclude <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

const double PI = 2.0 * acos(0.0);

class vector2 {
    public:
            double x,y;
                vector2(double x = 0, double y = 0):x(x), y(y){}
                    
                    bool operator < (const vector2& rhs) const {
                                return x != rhs.x ? x < rhs.x : y < rhs.y;
                                    }
                        
                        vector2 operator - (const vector2 &rhs) const {
                                    return vector2(x - rhs.x, y - rhs.y);
                                        }
                            
                            double polar() const {
                                        return fmod(atan2(y, x) + 2.0 * PI, 2.0 * PI);
                                            }
                                
                                double dot(const vector2& rhs) const {
                                            return x * rhs.x + y * rhs.y;
                                                }
};

bool cmp(const std::pair<double, vector2>& ref1, const std::pair<double, vector2>& ref2) {
        return ref1.first < ref2.first;
}

int main(int argc, const char * argv[]) {
        using namespace std;
            const double e = 1e-9;
                
                int n = 0;
                    int cnt = 0;
                        scanf("%d",&n);
                            vector<vector2> vecs(n);
                                
                                for(int i = 0 ; i < n ; ++i)
                                            scanf("%lf %lf",&vecs[i].x, &vecs[i].y);

                                    for(int i = 0 ; i < n ; ++i) {
                                                vector<pair<double, vector2> > radians;
                                                        for(int j = 0 ; j < n ; ++j) {
                                                                        if(i == j) continue;
                                                                                    radians.push_back(make_pair((vecs[j] - vecs[i]).polar(), vecs[j] - vecs[i]));
                                                                                            }
                                                                
                                                                sort(radians.begin(), radians.end());
                                                                        
                                                                        for(int j = 0 ; j < radians.size() ; ++j) {
                                                                                        vector<pair<double, vector2> >::iterator begin =
                                                                                                            lower_bound(radians.begin(), radians.end(), make_pair(radians[j].first + (PI / 2.0) - e, 0), cmp);
                                                                                                    vector<pair<double, vector2> >::iterator end =
                                                                                                                        upper_bound(radians.begin(), radians.end(), make_pair(PI / 2.0 + radians[j].first + e, 0), cmp);
                                                                                                                while(begin != end) {
                                                                                                                                    if(radians[j].second.dot(begin->second) == 0.0) cnt++;
                                                                                                                                                    begin++;
                                                                                                                                                                }
                                                                                                                            
                                                                                                                            begin = lower_bound(radians.begin(), radians.end(), make_pair(radians[j].first + (3.0 * PI / 2.0) - e, 0), cmp);
                                                                                                                                        end = upper_bound(radians.begin(), radians.end(), make_pair(radians[j].first + (3.0 * PI / 2.0) + e, 0), cmp);
                                                                                                                                                    while(begin != end) {
                                                                                                                                                                        if(radians[j].second.dot(begin->second) == 0.0) cnt++;
                                                                                                                                                                                        begin++;
                                                                                                                                                                                                    }
                                                                                                                                                            }
                                                                            }
                                        
                                        printf("%d\n",cnt);
                                            return 0;
}
