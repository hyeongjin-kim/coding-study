#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <cstring>

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

int n, m;
int board[102][102];
int dist[102][102][4];

int sy, sx, sh;
int ey, ex, eh;

bool isRange(int y, int x) {
	return y >= 1 && y <= m && x >= 1 && x <= n;
}

int calCo(int ch, int nh) {
	if (nh > ch) {
		int temp = ch;
		ch = nh;
		nh = temp;
	}

	if (ch == nh) return 0;
	if (ch - nh == 1) return 1;
	if (ch - nh == 2) return 2;
	if (ch - nh == 3) return 1;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<node> dq;

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	fill(&dist[0][0][0], &dist[101][101][4], -1);

	cin >> sy >> sx >> sh >> ey >> ex >> eh;

	sh -= 1;
	eh -= 1;
	
	dq.push_back({ sy, sx, sh });
	dist[sy][sx][sh] = 0;

	while (!dq.empty()) {
		node cur = dq.front(); dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			int cost = calCo(cur.h, i);
			bool isTurn = cost ? true : false;

			if (!isRange(ny, nx)) continue;
			if (board[ny][nx] == 1) continue;
			if (dist[ny][nx][i] != -1) continue;

			if (isTurn) {
				dist[ny][nx][i] = dist[cur.y][cur.x][cur.h] + cost + 1;
			}
			else {
				dist[ny][nx][i] = dist[cur.y][cur.x][cur.h];
			}
			dq.push_back({ ny,nx,i });
			
		}

	}


	cout << dist[ey][ex][eh];

	return 0;
}
