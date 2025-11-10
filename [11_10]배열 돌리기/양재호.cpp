#include <iostream>
#include <vector>

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

	int layer = (n < m ? n : m) / 2;

	for (int i = 0; i < layer; i++) {
		int top = i;
		int left = i;
		int bottom = n - 1 - i;
		int right = m - 1 - i;

		vector<int> ring;

		for (int x = left; x <= right; x++) {
			ring.push_back(arr[top][x]);
		}
		for (int y = top + 1; y <= bottom - 1; y++) {
			ring.push_back(arr[y][right]);
		}
		if (bottom > top) {
			for (int x = right; x >= left; x--) {
				ring.push_back(arr[bottom][x]);
			}
		}
		if (right > left) {
			for (int y = bottom - 1; y >= top + 1; y--) {
				ring.push_back(arr[y][left]);
			}
		}

		int len = ring.size();
		int rot = r % len;
		if (rot == 0) continue;

		vector<int> rotate(len);
		for (int i = 0; i < len; i++) {
			int nextidx = (i + len - rot) % len;
			rotate[nextidx] = ring[i];
		}

		int idx = 0;

		for (int x = left; x <= right; x++) {
			arr[top][x] = rotate[idx++];
		}
		for (int y = top + 1; y <= bottom - 1; y++) {
			arr[y][right] = rotate[idx++];
		}
		if (bottom > top) {
			for (int x = right; x >= left; x--) {
				arr[bottom][x] = rotate[idx++];
			}
		}
		if (left < right) {
			for (int y = bottom - 1; y >= top + 1; y--) {
				arr[y][left] = rotate[idx++];
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
