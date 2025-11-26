#include <iostream>

using namespace std;

int n, m, r;
int arr[305][305];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int layer = (n > m) ? m / 2 : n / 2;

	for (int i = 0; i < layer; i++) {
		int left = i, right = m - i- 1;
		int bottom = i, top = n - i- 1;

		int len = (right - left) * 2 + (top - bottom) * 2;
		int k = r % len;

		for (int j = 0; j < k; j++) {
			int temp = arr[right][bottom];
			for (int x = right; x >= left; x--) {
				swap(temp, arr[bottom][x]);
			}
			for (int y = bottom + 1; y < top; y++) {
				swap(temp, arr[y][left]);
			}
			for (int x = left; x <= right; x++) {
				swap(temp, arr[top][x]);
			}
			for (int y = top -1; y >= bottom; y--) {
				swap(temp, arr[y][right]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
