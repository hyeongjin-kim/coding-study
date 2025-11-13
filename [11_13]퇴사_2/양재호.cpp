#include <iostream>

using namespace std;

int n;
struct node {
	int num;
	int cost;
};
node arr[1500010];
int dp[1500010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].num >> arr[i].cost;
	}

	for (int i = 0; i < n; i++) {
		if (dp[i + 1] < dp[i]) {
			dp[i + 1] = dp[i];
		}

		int next = i + arr[i].num;
		if (next <= n) {
			int nextcost = dp[i] + arr[i].cost;
			if (dp[next] < nextcost) {
				dp[next] = nextcost;
			}
		}
	}


	cout << dp[n];

	return 0;
}
