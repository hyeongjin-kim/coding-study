#include <iostream>

#include <algorithm>

#include <queue>

using namespace std;

#define MAX_N 55

#define MAX_M 10005

#define MAX_VAL 1000005

int n,m; // n - 크레인 개수, m - 박스 개수
int crane[MAX_N];
int box[MAX_M];

bool cmp (int left, int right){
    if(left > right)
        return true;
    if(left < right)
        return false;
    return false;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int max_crane = 0;

    for(int i=0; i<n; i++){
        cin >> crane[i];
        max_crane = max(max_crane, crane[i]);
    }

    cin >> m;
    bool flag = true;
    for(int i=0; i<m; i++){
        cin >> box[i];
        if(max_crane < box[i])
            flag = false;
    }

    if(flag == false){
        cout << -1;
        return 0;
    }

    sort(crane, crane+n,cmp);
    sort(box, box+m,cmp);

    int cnt = 0;
    int ans = 0;

    while(cnt != m){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(box[j] <= crane[i]){
                    box[j] = MAX_VAL;
                    cnt++;
                    break;
                }
            }
        }
        ans++;
    }

    cout << ans;
    return 0;
}

