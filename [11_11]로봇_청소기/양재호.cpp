#include <iostream>

using namespace std;

int n, m;
int ydir[] = { -1, 0, 1, 0 };
int xdir[] = { 0, -1, 0, 1 };
int sy, sx, d;
int arr[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	cin >> sy >> sx >> d;

	if (d == 1) d = 3;
	else if (d == 3) d = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;

	while (arr[sy][sx] != 1) {
		if (arr[sy][sx] == 0) {
			arr[sy][sx] = 2;
			cnt++;
			continue;
		}
		bool flag = true;
		for (int i = 0; i < 4; i++) {
			d = (d + 1) % 4;
			int ny = sy + ydir[d];
			int nx = sx + xdir[d];
			if (arr[ny][nx] == 0) {
				sy = ny;
				sx = nx;
				flag = false;
				break;
			}
		}
		if (flag) {
			sy = sy + ydir[(d + 2) % 4];
			sx = sx + xdir[(d + 2) % 4];
		}
	}

	cout << cnt;

	return 0;
}
