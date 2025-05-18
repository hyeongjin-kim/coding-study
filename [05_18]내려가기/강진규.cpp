#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int max_acc[3] = { 0, };
	int min_acc[3] = { 0, };
	int cur[3];
	for (int i = 0;i < N;++i) {
		cin >> cur[0] >> cur[1] >> cur[2];
		int tmp_max_acc[3];
		int tmp_min_acc[3];
		tmp_max_acc[0] = cur[0] + max(max_acc[0], max_acc[1]);
		tmp_max_acc[1] = cur[1] + max(max(max_acc[0], max_acc[1]), max_acc[2]);
		tmp_max_acc[2] = cur[2] + max(max_acc[1], max_acc[2]);
		tmp_min_acc[0] = cur[0] + min(min_acc[0], min_acc[1]);
		tmp_min_acc[1] = cur[1] + min(min(min_acc[0], min_acc[1]), min_acc[2]);
		tmp_min_acc[2] = cur[2] + min(min_acc[1], min_acc[2]);
		swap(tmp_max_acc, max_acc);
		swap(tmp_min_acc, min_acc);
	}
	cout << max(max(max_acc[0], max_acc[1]), max_acc[2]) << " ";
	cout << min(min(min_acc[0], min_acc[1]), min_acc[2]);
	return 0;
}
