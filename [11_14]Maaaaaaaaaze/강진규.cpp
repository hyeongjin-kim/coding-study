#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Coord {
	int x, y, z;
};

int maze[5][4][5][5];
int path[5];
int stack[5];
int ans;

bool mazeVis[5];
int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

int vis[5][5][5];
int times;

Coord start = {0,0,0};
Coord endC = {4,4,4};

void findPath() {
	if (!maze[stack[start.x]][path[start.x]][start.y][start.z])
		return;

	queue<Coord> q;
	q.push(start);
	vis[start.x][start.y][start.z] = times;
	int it = 0;
	bool flag = false;
	Coord curEnd = endC;


	while (!q.empty()) {
		++it;
		int qSize = q.size();
		while (qSize--) {
			Coord cur = q.front(); q.pop();

			if (cur.x == curEnd.x && cur.y == curEnd.y && cur.z == curEnd.z) {
				flag = true;
				break;
			}

			for (int d = 0; d < 6; ++d) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				int nz = cur.z + dz[d];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5)
					continue;
				int realX = stack[nx];
				if (vis[nx][ny][nz] == times)
					continue;
				if (!maze[realX][path[nx]][ny][nz])
					continue;

				q.push({ nx,ny,nz });
				vis[nx][ny][nz] = times;
			}
		}
		if (flag)
			break;
	}
	if (flag)
		ans = min(ans, it);
}

void dfs(int depth) {
	if (depth == 5) {
		++times;
		findPath();
		return;
	}
	for (int mazeN = 0; mazeN < 5; ++mazeN) {
		if (mazeVis[mazeN])
			continue;
		mazeVis[mazeN] = true;
		for (int i = 0; i < 4; ++i) {
			path[depth] = i;
			stack[depth] = mazeN;
			dfs(depth + 1);
		}
		mazeVis[mazeN] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int inp;
	ans = 10000;
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			for (int k = 0; k < 5; ++k) {
				cin >> inp;
				maze[i][0][j][k] = inp;
				maze[i][1][k][4 - j] = inp;
				maze[i][2][4 - j][4 - k] = inp;
				maze[i][3][4 - k][j] = inp;
			}

	dfs(0);

	cout << (ans == 10000 ? -1 : ans - 1);
	return 0;
}
