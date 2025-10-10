#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int board[150][150];
int dist[150][150];
int testcase = 1;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

struct Edge {
	int x;
	int y;
};

queue<Edge> q;

bool in_range(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < N;
}

int input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			dist[i][j] = 21e8;
		}
	}

	return N;
	
	
}
void solution() {
	q.push({ 0,0});
	dist[0][0] = board[0][0];

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nc = dist[cur.x][cur.y] + board[nx][ny];
			if (!in_range(nx, ny))continue;
			if (dist[nx][ny] <= nc) continue;

			dist[nx][ny] = nc;
			q.push({ nx,ny });
		}

	}
}
void output() {
	cout << "Problem " << testcase++<<": " << dist[N - 1][N - 1]<<"\n";
}

int main() {

	while (input()) {
		solution();
		output();
	}

}
