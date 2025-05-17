#include <iostream>

using namespace std;

int N;
int dp[3][100005];
char map[3][100005];

int max_ans;
int min_ans;
/*
	4MB 실화?

*/

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int num;
			cin >> num;

			map[j][i] = num;
		}
	}
}

void printDPtable() {

	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dp[j][i] << " ";
		}
		cout << "\n";
	}

}
void solution() {
	//dp[0] : 왼쪽, dp[1] : 중간, dp[2] : 오른쪽 
	// 왼쪽 : 왼쪽관 중간에서 옴
	// 오른쪽 : 오른쪽과 중간에서 옴
	// 중간 : 모든 방향에서 옴
	dp[0][0] = map[0][0];
	dp[1][0] = map[1][0];
	dp[2][0] = map[2][0];


	for (int i = 1; i < N; i++) {
		//최대 점수 구하기
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + map[0][i];
		dp[1][i] = max(dp[0][i - 1], max(dp[1][i - 1] , dp[2][i-1])) + map[1][i];
		dp[2][i] = max(dp[1][i - 1], dp[2][i - 1]) + map[2][i];
	}
	max_ans = max(dp[2][N - 1], max(dp[0][N - 1], dp[1][N - 1]));

	for (int i = 1; i < N; i++) {
		//최소 점수 구하기
		dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + map[0][i];
		dp[1][i] = min(dp[0][i - 1], min(dp[1][i - 1], dp[2][i - 1])) + map[1][i];
		dp[2][i] = min(dp[1][i - 1], dp[2][i - 1]) + map[2][i];
	}
	min_ans = min(dp[2][N - 1], min(dp[0][N - 1], dp[1][N - 1]));
}

int main() {

	input();
	solution();

	cout << max_ans << " " << min_ans;

	return 0;
}
