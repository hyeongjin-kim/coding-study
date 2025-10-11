#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int arr[105];
    int dp[10010];
    for (int i = 0; i < n; i++) cin >> arr[i];

    fill(dp, dp + k+ 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            if (dp[j - arr[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            }
        }
    }

    if (dp[k] == INT_MAX) {
        cout << -1;
    }
    else {
        cout << dp[k];
    }

    return 0;
}
