#include <iostream>
#include <queue>
using namespace std;

int N, H, M;
int ans;
int map[101][101][101];

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

struct Node {
	int z;
	int x;
	int y;
};
int day = -1;
queue<Node> Q;

bool inRange(int z, int x, int y) {
	return 0 <= x && 0 <= y && 0 <= z && x < N && y < M && z < H;
}

void solution() {

	int size = Q.size();

	while (!Q.empty()) {
		size = Q.size();
		for (int i = 0; i < size; i++) {
			auto cur = Q.front();Q.pop();
			int nx, ny, nz;
			for (int dir = 0; dir < 6;dir++) {
				nx = cur.x + dx[dir];
				ny = cur.y + dy[dir];
				nz = cur.z + dz[dir];

				if (!inRange(nz, nx, ny))continue;
				if (map[nz][nx][ny] == -1 || map[nz][nx][ny] == 1) continue;

				map[nz][nx][ny] = 1;
				Q.push({ nz,nx,ny });
			}
		}
		day++;
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					Q.push({ i,j,k });
				}
			}
		}
	}

	solution();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[i][j][k] == 0) day = -1;
			}
		}
	}

	cout << day;
	return 0;
}
