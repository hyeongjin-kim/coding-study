#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1;tc <= T;++tc) {
		int l, n;
		cin >> l >> n;
		int fast = 0, slow = 0;
		int mid = l / 2;
		for (int i = 0;i < n;++i) {
			int cur;
			cin >> cur;
			if (cur <= mid) {
				fast = max(fast, cur);
				slow = max(slow, l - cur);
			}
			else {
				fast = max(fast, l - cur);
				slow = max(slow, cur);
			}
		}
		cout << fast << " " << slow << "\n";
	}
	return 0;
}
