#include <iostream>

using namespace std;

int dp[3][100001];
int N;

// dp[0][i] = 왼쪽 배치
// dp[1][i] = 오른쪽 배치
// dp[2][i] = 미배치



int main() {

	cin >> N;

	dp[0][1] = 1;
	dp[1][1] = 1;
	dp[2][1] = 1;
	
	//왼쪽을 배치 했을 때, 그 다음은 오른쪽과 미배치만 가능
	//오른쪽을 배치 했을 때, 그 다음은 왼쪽과 미배치만 가능
	//미배치 했을 때, 그 다음은 모두 가능


	for (int i = 2; i <= N; i++) {
		dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % 9901;
		dp[1][i] = (dp[0][i-1] + dp[2][i-1]) % 9901;
		dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1]) % 9901;
	}

	cout << (dp[0][N] + dp[1][N] + dp[2][N]) % 9901;

	return 0;
}
