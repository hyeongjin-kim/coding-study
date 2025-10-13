#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int n, k;
int dp[10005];
vector<int> coin;
void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		coin.push_back(val);
	}
	sort(coin.begin(), coin.end(), less<>());

}
void solution() {
	
	fill(dp, dp + k+1, 21e8);
	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < coin.size(); j++) {
			if (coin[j] > i) continue;

			dp[i] = min(dp[i], dp[i - coin[j]]+1);
		}
	}
	
	if (dp[k] == 21e8) cout << -1;
	else cout << dp[k];
	
}

int main() {

	input();
	solution();
	return 0;
}
