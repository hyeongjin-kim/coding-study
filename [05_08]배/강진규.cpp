#include <iostream>
#include <algorithm>

using namespace std;
int crane[50];
int box[10000];
int N, M;

bool possible(int day) {
	int craneIdx = N - 1;
	int boxIdx = M - 1;
	while (craneIdx >=0 && boxIdx >= 0) {
		for (int i = 0;i < day && boxIdx >= 0;++i) {
			if (crane[craneIdx] >= box[boxIdx])
				--boxIdx;
			else
				return false;
		}
		--craneIdx;
	}
	if (boxIdx == -1)
		return true;
	else
		return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;++i)
		cin >> crane[i];
	cin >> M;
	for (int i = 0;i < M;++i)
		cin >> box[i];
	sort(crane, crane + N);
	sort(box, box + M);
	int left = 0, right = 10001;
	while (left < right) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			right = mid;
		}
		else
			left = mid + 1;
	}
	if (right == 10001)
		cout << -1;
	else
		cout << right;
	return 0;
}
