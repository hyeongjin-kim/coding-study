#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
struct cmd {
	int d;
	int s;
};
int N, M;
int world[55][55];
bool clouded[55][55];
int dx[] = {0, 0,-1,-1,-1,0,1,1,1 };
int dy[] = {0, -1,-1,0,1,1,1,0,-1 };

queue<pair<int, int>> cloud;
cmd command[105];

void rainy_magic();
void cloud_move(int);
void water_bug_magic();
void make_cloud();

bool in_range(int x, int y) {
	return x >= 1 && y >= 1 && x <= N && y <= N;
}

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> world[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		
		cin >> command[i].d >> command[i].s;
	}
}

void solution() {

	cloud.push({ N,1 });
	cloud.push({ N,2 });
	cloud.push({ N-1,1 });
	cloud.push({ N-1,2 });


	for (int command_num = 0; command_num < M; command_num++) {
		cloud_move(command_num);
		rainy_magic();
		water_bug_magic();
		make_cloud();
	}
}
void output() {
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += world[i][j];
		}
	}
	cout << ans;
}
int main() {

	input();
	solution();
	output();


	return 0;
}

void cloud_move(int c) {
	
	int size = cloud.size();

	for (int s = 0; s < size; s++) {
		auto cur = cloud.front(); cloud.pop();
		int nx = cur.first + (dx[command[c].d] * (command[c].s%N));
		int ny = cur.second + (dy[command[c].d] * (command[c].s%N));

		if (nx < 1) nx += N;
		if (ny < 1) ny += N;
		if (nx > N) nx -= N;
		if (ny > N) ny -= N;

		cloud.push({ nx,ny });
	}

}
void rainy_magic() {

	int size = cloud.size();

	for (int s = 0; s < size; s++) {
		auto cur = cloud.front(); cloud.pop();
		world[cur.first][cur.second]++;
		clouded[cur.first][cur.second] = true;
		cloud.push(cur);
	}
}
void water_bug_magic() {
	int size = cloud.size();

	/*
	* ↖ : 2
	, ↗ : 4
	, ↘ : 6
	, ↙ : 8
	*/
	for (int s = 0; s < size; s++) {
		
		auto cur = cloud.front(); cloud.pop();
		
		for (int dir = 2; dir <= 8; dir += 2) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (!in_range(nx, ny)) continue;
			if (world[nx][ny] == 0) continue;

			world[cur.first][cur.second]++;
		}
	}
}
void make_cloud() {
	while (!cloud.empty())cloud.pop();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (world[i][j] >= 2 && !clouded[i][j]) {
				world[i][j] -= 2;
				cloud.push({ i,j });
			}
		}
	}

	memset(clouded, false, sizeof(clouded));
}
