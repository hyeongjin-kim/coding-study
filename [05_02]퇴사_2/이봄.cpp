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
		// 소요 기간 // 금액 
	}
	
	for (int i = 1; i <= n; i++) {
		// i일에 시작하면 d일에 상담 끝남
		int d = arr[i][0] + i-1;
		dp[i] = max(dp[i], dp[i - 1]);
		// i일에 아무 상담도 하지 않은 경우 
		if (d <= n + 1) {
			// i일에 상담을 하고 d일에 끝났을 때 업데이트 
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
