#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>

#define endl '\n'
#define LIM 987654321

using namespace std;

struct node {
	int y;
	int x;
	int h;
};

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

const int tleft[] = {3, 2, 0, 1};
const int tright[] = { 2, 3, 1, 0 };

int n, m;
int board[102][102];
int dist[102][102][4];

int sy, sx, sh;
int ey, ex, eh;

bool isRange(int y, int x) {
	return y >= 1 && y <= m && x >= 1 && x <= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<node> dq;

	cin >> m >> n;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	fill(&dist[0][0][0], &dist[101][101][4], -1);

	cin >> sy >> sx >> sh >> ey >> ex >> eh;

	--sh;
	--eh;
	
	dq.push_back({ sy, sx, sh });
	dist[sy][sx][sh] = 0;

	while (!dq.empty()) {
		node cur = dq.front(); dq.pop_front();

		// 왼쪽 회전
		int nh = tleft[cur.h];
		if (dist[cur.y][cur.x][nh] == -1) {
			dist[cur.y][cur.x][nh] = dist[cur.y][cur.x][cur.h] + 1;
			dq.push_back({ cur.y, cur.x, nh });
		}

		// 오른쪽 회전
		nh = tright[cur.h];
		if (dist[cur.y][cur.x][nh] == -1) {
			dist[cur.y][cur.x][nh] = dist[cur.y][cur.x][cur.h] + 1;
			dq.push_back({ cur.y, cur.x, nh });
		}

		for (int i = 1; i <= 3; i++) {
			int ny = cur.y + dy[cur.h] * i;
			int nx = cur.x + dx[cur.h] * i;

			if (!isRange(ny, nx)) break;
			if (board[ny][nx] == 1) break;
			if (dist[ny][nx][cur.h] != -1) continue;

			dist[ny][nx][cur.h] = dist[cur.y][cur.x][cur.h] + 1;
			dq.push_back({ ny, nx, cur.h });

		}

	}


	cout << dist[ey][ex][eh];

	return 0;
}
