#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> inp[1500001];
int dp[1500001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0;i < N;++i)
		cin >> inp[i].first >> inp[i].second;
	for (int i = 0;i < N;++i) {
		if (i-1>=0)
			dp[i] = max(dp[i - 1], dp[i]);
		int nDay = i + inp[i].first;
		if (nDay > N) continue;
		
		dp[nDay] = max(dp[nDay], dp[i] + inp[i].second);
	}
	cout << max(dp[N], dp[N-1]);
	return 0;
}
