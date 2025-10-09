#include <iostream>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int M, N;

bool isOutofRange(int r, int c) {
	return (r < 0 or r >= M or c < 0 or c >= N);
}

int map[505][505];

bool visit[505][505];

int cnt[505][505];

void recur(int r, int c) {
	visit[r][c] = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dr[dir], nc = c + dc[dir];
		if (isOutofRange(nr, nc)) continue;
		if (map[r][c] <= map[nr][nc]) continue;
		if (!visit[nr][nc]) recur(nr, nc);
		cnt[r][c] += cnt[nr][nc];
	}
}


int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	visit[M - 1][N - 1] = true;
	cnt[M - 1][N - 1] = 1;
	recur(0, 0);
	cout << cnt[0][0];


	return 0;
}