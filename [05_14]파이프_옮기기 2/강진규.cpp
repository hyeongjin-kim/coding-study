#include <iostream>

using namespace std;

bool arr[32][32];
long long dp[32][32][3];
int N;

int main(void) {
	cin >> N;
	for (int i = 0;i < N;++i)
		for (int j = 0;j < N;++j)
			cin >> arr[i][j];
	dp[0][1][0] = 1;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < N;++j) {
			if (j + 1 < N && !arr[i][j + 1])
				dp[i][j + 1][0] += dp[i][j][0] + dp[i][j][2];
			if (i + 1 < N && !arr[i + 1][j])
				dp[i + 1][j][1] += dp[i][j][1] + dp[i][j][2];
			if (i + 1 < N && j + 1 < N && !arr[i + 1][j + 1] && !arr[i + 1][j] && !arr[i][j + 1])
				dp[i + 1][j + 1][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
		}
	}
	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
	return 0;
}
