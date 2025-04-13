#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int n;
vector<pair<int,int> > vec;

int CalDist(int idx1, int idx2){
    int x1,y1,x2,y2;
    tie(x1,y1) = vec[idx1];
    tie(x2,y2) = vec[idx2];
    return abs(x1-x2) + abs(y1-y2);
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    int total_dist = 0;
    for(int i=0; i<n-1; i++){
        int tmp = CalDist(i,i+1);
        total_dist += tmp;
    }
    int ans = INT_MAX;
    for(int i=0; i<n-2; i++){
            int tmp1 = CalDist(i,i+1);
            int tmp2 = CalDist(i+1,i+2);
            int tmp3 = CalDist(i,i+2);
            ans = min(ans, total_dist - tmp1-tmp2+tmp3);
    }
    cout << ans;
    return 0;
}
