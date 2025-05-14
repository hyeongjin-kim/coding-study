#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 25

int n,m;
int l,r;
int order[MAX_N];
int ans = INT_MAX;

void f(int idx, int le, int ri, int cost){
    if(idx == m){
        ans = min(cost, ans);
        return;
    }
    
    int next = order[idx];
    f(idx+1, next, ri, cost + abs(le - next) );
    f(idx+1, le, next, cost + abs(ri - next) );
    return;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    cin >> l >> r;
    
    cin >> m;
    
    for(int i=0; i<m; i++){
        cin >> order[i];
    }
    
    f(0,l,r,0);
    
    cout << ans;
    
    return 0;
}

