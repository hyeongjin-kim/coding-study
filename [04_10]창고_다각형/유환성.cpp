#include <iostream>
#include <queue>
using namespace std;
#define SIZE 1005
int N;
int x, h;

int map[SIZE][SIZE];
int boundary[SIZE][SIZE];

int maxpoint;
int maxh;
int ans;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < SIZE && y < SIZE;
}
void mapset() {
	
	for (int i = 1; i <= h ; i++) {
		map[SIZE - i][x] = 1;
	}

}

void projection_to_right() {

	int px = SIZE - 1;
	int py = 0;
	int nx, ny;
	while (py < maxpoint) {	//제일 높은 탑까지 가기
		nx = px - 1;
		ny = py + 1;
		while (map[px][ny] != 1) {	// 다음 탑 찾기
			boundary[px][py] = 1;
			if (ny > maxpoint) return;
			py = ny;
			ny = py + 1;
		}
		boundary[px][py] = 1;
		while (map[px][ny] != 0) {	// 탑의 끝까지 가기
			boundary[px][py] = 1;
			px = nx;
			nx = px - 1;
		}
	}

}

void projection_to_left() {

	int px = SIZE - 1;
	int py = SIZE - 1;
	int nx, ny;
	while (py > maxpoint) {	//제일 높은 탑까지 가기
		nx = px - 1;
		ny = py - 1;
		while (map[px][ny] != 1) {	// 다음 탑 찾기
			boundary[px][py] = 1;
			if (ny < maxpoint) return;
			py = ny;
			ny = py - 1;
		}
		boundary[px][py] = 1;
		while (map[px][ny] != 0) {	// 탑의 끝까지 가기
			boundary[px][py] = 1;
			px = nx;
			nx = px - 1;
		}
	}
}

void calc() {
	queue<pair<int, int>>Q;
	Q.push({ SIZE-1,maxpoint });
	boundary[SIZE - 1][maxpoint] = 1;
	ans++;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		int nx, ny;
		for (int dir = 0; dir < 4; dir++) {

			nx = cur.first + dx[dir];
			ny = cur.second + dy[dir];

			if (!inRange(nx, ny))continue;
			if (boundary[nx][ny])continue;

			Q.push({ nx,ny });
			boundary[nx][ny] = 1;
			ans++;

		}

	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> h;
		x++;
		if (maxh < h) {
			maxpoint = x;
			maxh = h;
		}
		mapset();
	}

	projection_to_right(); //오른쪽으로 투영
	projection_to_left(); //왼쪽으로 투영
	calc();

	cout << ans;
	return 0;
}
