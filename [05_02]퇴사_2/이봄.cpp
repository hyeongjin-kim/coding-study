#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1500055

int n;
int dp[MAX_N];
int arr[MAX_N][2];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	
	for (int i = 1; i <= n; i++) {
		int d = arr[i][0] + i-1;
		dp[i] = max(dp[i], dp[i - 1]);
		if (d <= n + 1) {
			dp[d] = max(dp[i - 1] + arr[i][1], dp[d]);
		}

	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;

	return 0;
}
