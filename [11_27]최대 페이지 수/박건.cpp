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
#include <utility>

#define endl '\n'
#define LIM 987654321


typedef long long ll;

using namespace std;

struct chapter {
	int day;
	int page;
};

int n, m;
int dp[25][205]; // dp[x][y] : y 일동안 x 챕터까지 읽을 수 있는 최대 페이지
chapter arr[25];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> arr[i].day >> arr[i].page;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			if (arr[i].day <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].day] + arr[i].page);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

		}

	}

	cout << dp[m][n] << endl;

	return 0;
}
