#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nextV(vector<int>& first, vector<int>& second) {
	int up = 0;
	int small, big;
	big = second.size();
	small = first.size();
	vector<int> ans;
	for (int i = 0;i < small;i++) {
		int now = first[i] * 2 + second[i] + up;
		up = now / 10;
		now %= 10;
		ans.push_back(now);
	}
	for (int i = small; i < big;i++) {
		int now = second[i] + up;
		up = now / 10;
		now %= 10;
		ans.push_back(now);
	}
	while (up) {
		int tmp = up % 10;
		up /= 10;
		ans.push_back(tmp);
	}
	return ans;
}

int main() {
	int dp[2];
	dp[0] = 1;
	dp[1] = 1;
	int n;
	while (cin >> n) {
		vector<int> first;
		vector<int> second;
		
		if (n < 2) {
			cout << dp[n] << '\n';
			continue;
		}
		first.push_back(1);
		second.push_back(1);


		for (int i = 2;i <= n;i++) {
			//dp[i] = dp[i - 1] + dp[i - 2] * 2;
			first = nextV(first, second);
			swap(first, second);
		}
		for (int i = second.size() - 1;i >= 0;i--)
			cout << second[i];
		cout << '\n';
	}

	return 0;
}
