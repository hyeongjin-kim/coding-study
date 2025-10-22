#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int x, y;
	int dist;

	bool operator<(const Node& right) const {
		return dist > right.dist;
	}
};

int field[501][501];
int minDist[501][501];
bool vis[501][501];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	int sx, sy;
	cin >> sx >> sy;
	int a, b, c;
	cin >> a >> b >> c;
	int topx, topy, toph = 0;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			cin >> field[i][j];
			if (field[i][j] > toph) {
				topx = i;
				topy = j;
				toph = field[i][j];
			}
		}

	priority_queue<Node> pq;
	pq.push({ sx,sy,0 });
	vis[sx][sy] = true;
	while (!pq.empty()) {
		Node curNode = pq.top(); pq.pop();
		int curx = curNode.x;
		int cury = curNode.y;
		int curDist = curNode.dist;

		if (curDist > minDist[curx][cury])
			continue;

		if (curx == topx && cury == topy) {
			cout << curDist;
			return 0;
		}

		for (int d = 0; d < 4; ++d) {
			int nx = curx + dx[d];
			int ny = cury + dy[d];
			if (nx<1 || nx>N || ny<1 || ny>M) continue;

			int cost = field[nx][ny] - field[curx][cury];
			if (cost > c)
				continue;

			if (cost > 0)
				cost *= a;
			else if (cost < 0)
				cost = b * (-cost);
			else
				++cost;

			int nDist = curDist + cost;

			if (vis[nx][ny] && minDist[nx][ny] <= nDist)
				continue;

			vis[nx][ny] = true;
			minDist[nx][ny] = nDist;
			pq.push({ nx,ny,nDist });
		}
	}
	cout << -1;
	return 0;
}
