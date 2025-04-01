#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int N, M;
int map[1000][1000];
int visited[1000][1000];
int sx, sy;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < N && y < M;
}

void init() {
	memset(visited,-1, sizeof(visited));
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				sx = i;
				sy = j;
			}
		}
	}
}

void bfs() {
	int nx, ny;
	queue<pair<int, int>> Q;
	Q.push({ sx,sy });
	visited[sx][sy] = 0;


	while (!Q.empty()) {	
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			nx = cur.first + dx[dir];
			ny = cur.second + dy[dir];

			if (!inRange(nx, ny))continue;
			if (map[nx][ny] == 0) continue;
			if (visited[nx][ny] > -1)continue;

			Q.push({ nx,ny });
			visited[nx][ny] = visited[cur.first][cur.second] + 1;
		}
	}

}

void output() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) visited[i][j] = 0;
			cout << visited[i][j]<<" ";
		}
		cout << "\n";
	}
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	init();
	input();
	bfs();
	output();

}