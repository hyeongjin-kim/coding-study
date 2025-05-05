#include <iostream>
#include <queue>
using namespace std;
#define SIZE 305

int dx[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int dist[SIZE][SIZE];
int ans;
int N;
int sx, sy;
int ex, ey;

queue<pair<int, int>> Q;
bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < N && y < N;
}
void init() {
	while (!Q.empty())Q.pop();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = -1;
		}
	}
}
void input() {
	cin >> N;	// 체스판의 크기
	cin >> sx >> sy;	//출발
	cin >> ex >> ey;	//도착

}
void solution() {
	Q.push({ sx,sy });
	dist[sx][sy] = 0;

	while (!Q.empty()) {
		
		auto cur = Q.front(); Q.pop();

		if (cur.first == ex && cur.second == ey) return;

		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (!inRange(nx, ny))continue;
			if (dist[nx][ny] != -1) continue;

			Q.push({ nx,ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		input();
		init();
		solution();

		cout << dist[ex][ey] <<"\n";
	}

	return 0;
}
