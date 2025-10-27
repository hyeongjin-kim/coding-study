#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct state {
	int row;
	int col;
	int mss;
	int dir;
	int spd;
	int cnt;
	bool flag;
};

int N, M, K;
state map[55][55];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

queue<state> fireball;
void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireball.push({ r,c,m,d,s,0,false });
	}
}

void init() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			map[r][c] = { r,c,0,0,0,0,0 };
		}
	}
}

void move_fireball() {
	int size = fireball.size();
	for (int i = 0; i < size; i++) {
		auto cur = fireball.front(); fireball.pop();
		int nx = cur.row + dx[cur.dir] * cur.spd;
		int ny = cur.col + dy[cur.dir] * cur.spd;
		
		nx = ((nx - 1) % N + N) % N + 1;
		ny = ((ny - 1) % N + N) % N + 1;

		if (map[nx][ny].cnt == 0) {
			map[nx][ny].flag = true;
			map[nx][ny].dir = cur.dir;
		}
		else {
			if (map[nx][ny].flag) {
				map[nx][ny].flag = (map[nx][ny].dir % 2 == 1 && cur.dir % 2 == 1) || (map[nx][ny].dir % 2 == 0 && cur.dir % 2 == 0);
			}
		}

		map[nx][ny].cnt++;
		map[nx][ny].mss += cur.mss;
		map[nx][ny].spd += cur.spd;

	}
}
void divide_fireball() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (map[r][c].cnt == 1) {
				fireball.push({ r,c,map[r][c].mss,map[r][c].dir, map[r][c].spd, 0,false });
			}
			else if (map[r][c].cnt >= 2) {
				int nm = map[r][c].mss / 5;
				if (nm == 0) continue;
				int ns = map[r][c].spd / map[r][c].cnt;
				if (map[r][c].flag) {
					for (int dir = 0; dir < 8; dir += 2)
						fireball.push({ r,c,nm,dir,ns,0,false });
				}
				else {
					for (int dir = 1; dir < 8; dir += 2)
						fireball.push({ r,c,nm,dir,ns,0,false });
				}
			}
		}
	}
}

void solution() {

	for (int cmd = 0; cmd < K; cmd++) {
		init();
		move_fireball();
		divide_fireball();
	}

}

void output() {
	int ans=0;
	while (!fireball.empty()) {
		auto cur = fireball.front(); fireball.pop();
		ans += cur.mss;
	}
	cout << ans;
}
int main() {

	

	input();
	solution();
	output();
	return 0;
}
