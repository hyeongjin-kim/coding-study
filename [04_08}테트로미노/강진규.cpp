#include <iostream>
#include <algorithm>

using namespace std;

int xpos[] = { -1,0,1,0 };
int ypos[] = { 0,1,0,-1 };

int arr[500][500];
bool vis[500][500];

int N, M;
int curmax;

void rec(int x, int y, int depth, int acc) {
	if (depth == 4) {
		curmax = max(curmax, acc);
		return;
	}
	if (depth == 2) {
		for (int i = 0;i < 4;i++) {
			int x1 = x + xpos[i], y1 = y + ypos[i];
			if (x1 >= N || x1 < 0 || y1 >= M || y1 < 0 || vis[x1][y1]) continue;
			for (int j = 0;j < 4;j++) {
				if (i == j) continue;
				int x2 = x + xpos[j], y2 = y + ypos[j];
				if (x2 >= N || x2 < 0 || y2 >= M || y2 < 0 || vis[x2][y2]) continue;
				curmax = max(curmax, acc + arr[x1][y1] + arr[x2][y2]);
			}
		}
	}
	for (int d = 0;d < 4;d++) {
		int nx = x + xpos[d], ny = y + ypos[d];
		if (nx >= N || nx < 0 || ny >= M || ny < 0 || vis[nx][ny]) continue;
		vis[nx][ny] = true;
		rec(nx, ny, depth + 1, acc + arr[nx][ny]);
		vis[nx][ny] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;	
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> arr[i][j];

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++) {
			vis[i][j] = true;
			rec(i, j, 1, arr[i][j]);
			vis[i][j] = false;
		}
	}
	cout << curmax;
	return 0;
}
