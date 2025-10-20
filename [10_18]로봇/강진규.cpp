#include <iostream>
#include <queue>

using namespace std;

struct Coord {
	int x;
	int y;
	int dir;
};

int field[100][100];
bool vis[100][100][4];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int dirToCode[] = { 1,3,2,0 };

int main(void) {
	int M, N;
	int sx, sy, sd, ex, ey, ed;
	cin >> M >> N;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> field[i][j];
		}
	}

	cin >> sx >> sy >> sd;
	cin >> ex >> ey >> ed;
	--sx; --sy; --ex; --ey;
	sd = dirToCode[sd - 1];
	ed = dirToCode[ed - 1];

	int ans = 0;

	queue<Coord> q;
	q.push({ sx,sy,sd });
	vis[sx][sy][sd] = true;
	while (!q.empty()) {
		int it = q.size();
		while (it--) {
			Coord cur = q.front(); q.pop();

			if (cur.x == ex && cur.y == ey && cur.dir == ed) {
				cout << ans;
				return 0;
			}

			for (int i = 1; i <= 3; i += 2) {
				int ndir = (cur.dir + i) % 4;
				if (vis[cur.x][cur.y][ndir]) continue;
				vis[cur.x][cur.y][ndir] = true;
				q.push({ cur.x,cur.y,ndir });
			}


			int nx = cur.x, ny = cur.y;
			int curDx = dx[cur.dir];
			int curDy = dy[cur.dir];
			
			for (int i = 1; i <= 3; ++i) {
				nx += curDx;
				ny += curDy;
				if (nx < 0 || nx >= M || ny < 0 || ny >= N || field[nx][ny]) break;
				if (vis[nx][ny][cur.dir]) continue;
				vis[nx][ny][cur.dir] = true;
				q.push({ nx,ny,cur.dir });
			}

		}
		++ans;
	}
	return 0;
}
