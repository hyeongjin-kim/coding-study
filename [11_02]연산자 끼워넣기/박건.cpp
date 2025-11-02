#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

#define endl '\n'

#define LIM 1000000005

using namespace std;

int n;
int arr[12];
int op[4];
int minres = LIM;
int maxres = -LIM;

void dfs(int idx, int res){
    if(idx == n){
        minres = min(minres, res);
        maxres = max(maxres, res);
        return;
    }

    for (int i = 0; i < 4; i++){
        if(op[i] <= 0)
            continue;

        op[i]--;
        if(i == 0){
            dfs(idx + 1, res + arr[idx]);
        }
        else if(i== 1){
            dfs(idx + 1, res - arr[idx]);
        }
        else if(i == 2){
            dfs(idx + 1, res * arr[idx]);
        }
        else {
            dfs(idx + 1, res / arr[idx]);
        }
        op[i]++;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++){
        cin >> op[i];
    }

    dfs(1, arr[0]);

    cout << maxres << endl;
    cout << minres << endl;

    return 0;
}
