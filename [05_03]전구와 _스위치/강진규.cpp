#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string current, target, tmp;
	cin >> N >> current >> target;
	int ans = -1;
	int cnt = 0;
	tmp = current;
	for (int i = 1; i < N; ++i) {
		if (tmp[i - 1] != target[i - 1]) {
			for (int j = -1; j < 2 && i + j < N; ++j) {
				tmp[i + j] = tmp[i + j] == '0' ? '1' : '0';
			}
			++cnt;
		}
	}
	if (tmp == target)
		ans = cnt;
	cnt = 1;
	tmp = current;
	tmp[0] = tmp[0] == '0' ? '1' : '0';
	tmp[1] = tmp[1] == '0' ? '1' : '0';
	for (int i = 1; i < N; ++i) {
		if (tmp[i - 1] != target[i - 1]) {
			for (int j = -1; j < 2 && i + j < N; ++j) {
				tmp[i + j] = tmp[i + j] == '0' ? '1' : '0';
			}
			++cnt;
		}
	}
	if (tmp == target)
		if (ans == -1)
			ans = cnt;
		else
		ans = min(ans, cnt);
	cout << ans;
	return 0;
}
