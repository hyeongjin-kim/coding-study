#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool field[101][101];
bool vis[101][101];
int sizes[10000];

int main(void) {
	int M, N, K;
	cin >> N >> M >> K;

	int idx = 0;

	int x1, y1, x2, y2;
	for (int k = 0; k < K; ++k) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; ++i)
			for (int j = y1; j < y2; ++j)
				field[i][j] = true;
	}


	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (vis[i][j] || field[i][j]) continue;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis[i][j] = true;
			++sizes[idx];
			while (!q.empty()) {
				int curx = q.front().first;
				int cury = q.front().second;
				q.pop();
				for (int d = 0; d < 4; ++d) {
					int nx = curx + dx[d];
					int ny = cury + dy[d];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (vis[nx][ny] || field[nx][ny]) continue;
					vis[nx][ny] = true;
					q.push({ nx,ny });
					++sizes[idx];
				}
			}
			++idx;
		}
	}
	sort(sizes, sizes + idx);
	cout << idx << "\n";
	for (int i = 0; i < idx; ++i)
		cout << sizes[i] << " ";
	return 0;
}
