#include <iostream>
#include <memory.h>

using namespace std;

int arr[9][9];
bool yused[9][10];
bool xused[9][10];
bool boxused[9][10];

int boxidx(int y, int x) {
	return (y / 3) * 3 + (x / 3);
}

bool dfs(int depth) {
	if (depth == 81) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		return true;
	}
	int y = depth / 9;
	int x = depth % 9;

	if (arr[y][x] != 0) {
		return dfs(depth + 1);
	}

	int b = boxidx(y, x);
	for (int i = 1; i <= 9; i++) {
		if (!yused[y][i] && !xused[x][i] && !boxused[b][i]) {
			arr[y][x] = i;
			yused[y][i] = true;
			xused[x][i] = true;
			boxused[b][i] = true;

			if (dfs(depth + 1)) return true;

			arr[y][x] = 0;
			yused[y][i] = false;
			xused[x][i] = false;
			boxused[b][i] = false;
		}
	}
	return false;
}

int main() {
	memset(yused, false, sizeof(yused));
	memset(xused, false, sizeof(xused));
	memset(boxused, false, sizeof(boxused));

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] != 0) {
				int a = arr[i][j];
				int b = boxidx(i, j);
				yused[i][a] = true;
				xused[j][a] = true;
				boxused[b][a] = true;
			}
		}
	}

	dfs(0);

	return 0;
}
