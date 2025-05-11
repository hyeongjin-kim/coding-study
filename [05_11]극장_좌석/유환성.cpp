#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

//dp[0] : 왼쪽
//dp[1] : 가만히
//dp[2] : 오른쪽
int dp[3][41];
int N;
int vipcnt;
int num;
int main() {
	cin >> N;
	cin >> vipcnt;
	
	memset(dp, -1, sizeof(dp));

	dp[0][1] = 0;
	dp[1][1] = 1;
	dp[2][1] = 1;

	for (int i = 0; i < vipcnt; i++) {
		cin >> num;
		dp[0][num] = 0;
		dp[2][num] = 0;

	}

	for (int i = 2; i <= N; i++) {

		if (dp[0][i] == 0) {	//vip석
			dp[1][i] = dp[1][i - 1] + dp[0][i - 1];
		}
		else {
			dp[0][i] = dp[2][i - 1];
			dp[1][i] = dp[1][i - 1] + dp[0][i - 1];
			dp[2][i] = dp[1][i];
		}
	}

	int ans = dp[0][N] + dp[1][N];

	cout << ans;

	


}
