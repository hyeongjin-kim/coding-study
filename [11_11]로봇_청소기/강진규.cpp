#include <iostream>

using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int field[50][50];

int N, M;

bool isDirty(int x, int y) {
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (!field[nx][ny])
			return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	int x, y, d;
	cin >> x >> y >> d;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> field[i][j];

	int ans = 0;
	while (true) {
		if (!field[x][y]) {
			++ans;
			field[x][y] = 2;
		}
		if (isDirty(x, y)) {
			d = (d + 3) % 4;
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (field[nx][ny])
				continue;
			x = nx;
			y = ny;
		}
		else {
			int nx = x - dx[d];
			int ny = y - dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || field[nx][ny] == 1)
				break;
			x = nx;
			y = ny;
		}
	}
	cout << ans;
	return 0;
}
