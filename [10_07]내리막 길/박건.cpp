#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <cstring>

#define endl '\n'

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
int board[501][501];
int dp[501][501];
int res = 0;

bool isRange(int y, int x) {
	return y >= 0 && y < m && x >= 0 && x < n;
}

int dfs(int y, int x) {
	if (y == m - 1 && x == n - 1) return 1;
	if (dp[y][x] != -1) return dp[y][x];

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (!isRange(ny, nx)) continue;
		if (board[ny][nx] >= board[y][x]) continue;
		dp[y][x] += dfs(ny, nx);

	}
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	cout << dfs(0, 0);
	
	return 0;
}
