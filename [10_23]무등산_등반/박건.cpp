#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <map>

#define endl '\n'
#define LIM 987654321

using namespace std;

struct edge {
	int y;
	int x;
	int w;

	bool operator()(const edge& a, const edge& b) {
		return a.w > b.w;
	}
};


const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int board[502][502];
int n, m;
int sy, sx;
int ey, ex, ev = -1;
int a, b, c;

bool isRange(int y, int x) {
	return y >= 1 && y <= n && x >= 1 && x <= m;
}

int calCo(int cy, int cx, int ny, int nx) {
	if (board[cy][cx] == board[ny][nx]) {
		return 1;
	}
	else if (abs(board[cy][cx] - board[ny][nx]) > c) {
		return -1;
	}

	else if (board[cy][cx] - board[ny][nx] < 0) {
		return (board[ny][nx] - board[cy][cx]) * a;
	}
	
	return (board[cy][cx] - board[ny][nx]) * b;
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> sy >> sx;
	cin >> a >> b >> c;

	priority_queue<edge, vector<edge>, edge> pq;
	vector<vector<int>> dist(n+1, vector<int>(m+1, LIM));


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (ev < board[i][j]) {
				ev = board[i][j];
				ey = i;
				ex = j;
			}
		}
	}

	dist[sy][sx] = 0;
	pq.push({ sy, sx, 0 });

	while (!pq.empty()) {
		edge cur = pq.top(); pq.pop();

		if (dist[cur.y][cur.x] < cur.w) continue;

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (!isRange(ny, nx)) continue;

			int mw = calCo(cur.y, cur.x, ny, nx);

			if (mw == -1) continue;
			if (dist[ny][nx] <= dist[cur.y][cur.x] + mw) continue;
			
			dist[ny][nx] = dist[cur.y][cur.x] + mw;
			pq.push({ ny, nx, dist[ny][nx] });

		}

	}

	if (dist[ey][ex] == LIM) 
		cout << -1 << endl;
	else
		cout << dist[ey][ex] << endl;

	return 0;
}
