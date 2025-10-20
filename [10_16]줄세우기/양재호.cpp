#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[205];
int dp[205];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int>lis;

	for (int i = 0; i < n; i++) {
		int now = arr[i];
		int idx = lower_bound(lis.begin(), lis.end(), now) - lis.begin();

		if (idx == lis.size()) {
			lis.push_back(now);
		}
		else {
			lis[idx] = now;
		}
	}
	cout << n - lis.size();

	return 0;
}
