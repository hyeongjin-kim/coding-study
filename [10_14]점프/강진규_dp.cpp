#include <iostream>
#include <algorithm>

using namespace std;

struct step {
	int loc;
	int hop;
};

//unordered_set<int> smallStones;
int dp[10001][150];
bool smallStones[10001];

int main(void) {
	int N, M;
	cin >> N >> M;

	while (M--) {
		int small;
		cin >> small;
		//smallStones.insert(small);
		smallStones[small] = true;
	}
	dp[1][0] = 1;
	for (int i = 2; i <= N; ++i) {
		if (smallStones[i])
			continue;
		for (int j = 1; j < 150; ++j) {
			int before = i - j;
			if (before < 1) continue;
			int curMin = 100000;
			for (int hop = j + 1; hop >= 0 && hop > j - 2; --hop) {
				if (!dp[before][hop]) continue;
				curMin = min(curMin, dp[before][hop]);
			}
			if (curMin == 100000)
				continue;

			dp[i][j] = curMin + 1;
		}
	}
	int ans = 100000;
	for (int i = 1; i < 150; ++i) {
		if (!dp[N][i]) continue;
		ans = min(ans, dp[N][i]);
	}

	cout << (ans == 100000 ? -1 : ans - 1);
	
	return 0;
}
