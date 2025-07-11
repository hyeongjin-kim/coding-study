#include <iostream>
#include <algorithm>

using namespace std;

int length[1000000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, n;
	bool succ;
	while (1) {
		succ = false;
		cin >> x;
		if (cin.eof()) break;
		x *= 10000000;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> length[i];
		sort(length, length + n);
		int left = 0, right = n - 1;
		while (left < right) {
			int cur = length[left] + length[right];
			if (cur == x) {
				cout << "yes " << length[left] << " " << length[right] << "\n";
				succ = true;
				break;
			}
			else if (cur > x)
				--right;
			else
				++left;

		}
		if (!succ)
			cout << "danger\n";
	}
	return 0;

}
