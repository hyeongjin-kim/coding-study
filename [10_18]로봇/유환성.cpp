#include <iostream>
#include <queue>
using namespace std;

int N,M;
int map[105][105];
int visited[10][105][105];
int sx, sy, sd;
int ex, ey, ed;
int ans = 0;
int dx[] = { 0,0,0,1,-1};
int dy[] = { 0,1,-1,0,0 };

struct state{
	int dir;
	int x;
	int y;
};

queue<state> Q;

bool in_range(int x, int y) {
	return x >= 1 && y >= 1 && x <= N && y <= M;
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy >> sd;
	cin >> ex >> ey >> ed;
}

//동 서 남 북
int turn_left(int dir) {
	int res;
	switch (dir) {
	case 1: res = 4; break;
	case 2: res = 3; break;
	case 3: res = 1; break;
	case 4: res = 2; break;
	default:;
	}
	return res;
}
int turn_right(int dir) {
	int res;
	switch (dir) {
	case 1: res = 3; break;
	case 2: res = 4; break;
	case 3: res = 2; break;
	case 4: res = 1; break;
	default:;
	}
	return res;
}

void solution() {
	Q.push({ sd,sx,sy });
	visited[sd][sx][sy] = 1;
	while (!Q.empty()) {
		int size = Q.size();

		for (int turn = 0; turn < size; turn++) {
			auto cur = Q.front(); Q.pop();

			if (cur.x == ex && cur.y == ey && cur.dir == ed) {
				return;
			}

			//명령 1. Go k : k는 1, 2 또는 3일 수 있다.현재 향하고 있는 방향으로 k칸 만큼 움직인다.
			for (int k = 1; k <= 3; k++) {
				int nx = cur.x + dx[cur.dir] * k;
				int ny = cur.y + dy[cur.dir] * k;

				if (!in_range(nx, ny))continue;
				if (map[nx][ny])break;
				if (visited[cur.dir][nx][ny]) continue;

				Q.push({ cur.dir,nx,ny });
				visited[cur.dir][nx][ny] = 1;
			}

			//명령 2. Turn dir : dir은 left 또는 right 이며, 각각 왼쪽 또는 오른쪽으로 90° 회전한다.
			for (int k = 0; k < 2; k++) {
				int nd;
				if (k == 1) nd = turn_left(cur.dir);
				else nd = turn_right(cur.dir);

				if (visited[nd][cur.x][cur.y]) continue;
				Q.push({ nd,cur.x, cur.y });
				visited[nd][cur.x][cur.y] = 1;

			}
		}


		ans++;
	}
}

int main() {

	input();
	solution();
	cout << ans;

	return 0;
}
