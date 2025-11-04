#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

#define endl '\n'
#define LIM 987654321

typedef long long ll;

using namespace std;

int board[101][101];
ll dp[101][101];
int res;
int n;

bool isRange(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

ll dfs(int y, int x) {
	if (!isRange(y, x)) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	if (board[y][x] == 0) return 0;

	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;

	dp[y][x] += dfs(y + board[y][x], x);
	dp[y][x] += dfs(y, x + board[y][x]);

	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0) << endl;

	return 0;
}
