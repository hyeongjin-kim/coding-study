#include <iostream>
using namespace std;

/*

 3가지 행동 (가로 세로 대각선)으로 최대 3^32의 연산 : DP

*/
  //dp[방향][x][y]

long long int dp[3][33][33];
int map[33][33];
int N;

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < N && y < N;
}

void input() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

}

void solution() {
	

	dp[0][0][1] = 1;

	for (int row = 0; row < N; row++) {
		for (int col = 2; col < N; col++) {

			// dp[0] : 가로, dp[1] : 세로, dp[2] : 대각선

			if (map[row][col] == 1) {

				dp[0][row][col] = dp[1][row][col] = dp[2][row][col] = 0;

			}

			else {

				//대각선일 때 주의

				if (inRange(row, col - 1)) {
					dp[0][row][col] = dp[0][row][col - 1] + dp[2][row][col - 1];
				}
				
				if (inRange(row - 1, col)) {
					dp[1][row][col] = dp[1][row - 1][col] + dp[2][row - 1][col];
				}

				if (map[row - 1][col] || map[row][col - 1]) continue;

				if (inRange(row - 1, col - 1)) {

					dp[2][row][col] =
						dp[0][row - 1][col - 1] +
						dp[1][row - 1][col - 1] +
						dp[2][row - 1][col - 1];
				}
			}

		}
	}

}

int main() {

	input();

	solution();


	cout << dp[0][N - 1][N - 1]+ dp[1][N - 1][N - 1]+ dp[2][N - 1][N - 1];
	return 0;
}
