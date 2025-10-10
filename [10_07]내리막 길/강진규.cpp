#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int field[500][500];
int dp[500][500];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int N, M;

void dfs(int x, int y) {
	dp[x][y] = 0;
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (field[nx][ny] <= field[x][y]) continue;

		if (dp[nx][ny] == -1)
			dfs(nx, ny);
		dp[x][y] += dp[nx][ny];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> field[i][j];
		}
		memset(dp[i], -1, 500 * sizeof(int));
	}
	dp[0][0] = 1;
	dfs(N - 1, M - 1);
	cout << dp[N - 1][M - 1];

	return 0;
}
