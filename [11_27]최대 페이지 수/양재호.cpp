#include <iostream>
#include <memory.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int day[21];
	int read[21];
	int dp[201];
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> day[i] >> read[i];
	}

	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= day[i]; j--) {
			dp[j] = max(dp[j], dp[j - day[i]] + read[i]);
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		ans = (dp[i] > ans) ? dp[i] : ans;
	}

	cout << ans;

	return 0;
}
