#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int N, M;
int map[500][500];
int ans;
int sum;
int visited[500][500];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < N && y < M;
}

void dfs(int sx, int sy, int level) {

	if (ans >= (4 - level) * MAX + sum) return;

	if (level == 4) {
		if (sum > ans) ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		for (int dir = 0; dir < 4;dir++) {

			int nx = sx + dx[dir];
			int ny = sy + dy[dir];

			if (!inRange(nx, ny))continue;
			if (visited[nx][ny])continue;

			visited[nx][ny] = 1;
			sum += map[nx][ny];
			dfs(nx, ny,level+1);
			sum -= map[nx][ny];
			visited[nx][ny] = 0;

		}

	}

}
	
void mountain(int sx, int sy) {
	vector<int> vect;
	int center = map[sx][sy];
	

	for (int dir = 0; dir < 4; dir++) {
		int nx, ny;
		nx = sx + dx[dir];
		ny = sy + dy[dir];
		if (!inRange(nx, ny))continue;

		vect.push_back(map[nx][ny]);
	}
	sort(vect.begin(), vect.end(), greater<>());
	if (vect.size() >= 3) {
		for (int i = 0; i < 3; i++) {
			center += vect[i];
		}
	}

	if (center > ans) ans = center;

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 0);
			mountain(i, j);
		}
	}

	cout << ans;
}
