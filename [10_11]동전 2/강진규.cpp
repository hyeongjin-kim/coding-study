#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int coins[100];
int bag[10001];

int main(void) {
	int n, k;

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> coins[i];

	sort(coins, coins + n);
	memset(bag + 1, -1, 10000 * sizeof(int));

	for (int i = 0; i < n; ++i) {
		int curCoin = coins[i];
		for (int j = 1; j <= k; ++j) {
			int withoutCur = j - curCoin;
			if (withoutCur < 0) continue;
			if (bag[withoutCur] == -1) continue;

			bag[j] = (bag[j] == -1 ? bag[withoutCur] + 1 : min(bag[withoutCur] + 1, bag[j]));
		}
	}

	cout << bag[k];
	return 0;
}
