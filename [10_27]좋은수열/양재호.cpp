#include <iostream>

using namespace std;

int n;
int arr[90];
bool finish = false;

int isgood(int len) {
	for (int i = 1; i <= len / 2; i++) {
		int same = 1;
		for (int j = 0; j < i; j++) {
			int left_idx = len - 1 - i - j;
			int right_idx = len - 1 - j;

			if (arr[left_idx] != arr[right_idx]) {
				same = 0;
				break;
			}
		}
		if (same == 1) {
			return 0;
		}
	}
	return 1;
}

void dfs(int depth) {
	if (finish) return;

	if (depth == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		finish = true;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		arr[depth] = i;

		if (isgood(depth + 1)) {
			dfs(depth + 1);

			if (finish) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	dfs(0);

	return 0;
}
