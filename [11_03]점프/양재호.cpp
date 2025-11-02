#include <iostream>
#include <memory.h>

using namespace std;

int n;
int arr[105][105];
long long dp[105][105];

long long dfs(int y, int x) {
    if (y == n - 1 && x == n - 1) return 1;
    if (arr[y][x] == 0) return 0;

    if (dp[y][x] != -1) return dp[y][x];

    long long cnt = 0;

    if(y + arr[y][x] < n) cnt += dfs(y + arr[y][x], x);
    if (x + arr[y][x] < n) cnt += dfs(y, x + arr[y][x]);

    dp[y][x] = cnt;

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dfs(0, 0);

    cout << dp[0][0];

    return 0;
}
