#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int mapsize;
int map[105][105];
int visited[105][105];
int mapstate[105][105];
int ans;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < mapsize && y < mapsize;
}

void input() {

	cin >> mapsize;

	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int sx, int sy) {

	queue<pair<int, int>> Q;
	visited[sx][sy] = 1;
	Q.push({sx,sy});

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int nx, ny;
		for (int dir = 0; dir < 4; dir++) {
			nx = cur.first + dx[dir];
			ny = cur.second + dy[dir];

			if (!inRange(nx, ny))continue;
			if (visited[nx][ny])continue;
			//잠김 : 1, 안 잠김 : 0
			if (mapstate[nx][ny]) continue;

			Q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}


}

int find_LandCnt() {

	//land의 개수 찾기
	int cnt = 0;
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (mapstate[i][j]) continue;
			if (visited[i][j]) continue;

			bfs(i, j);
			cnt++;
		}
	}
	
	return cnt;

}

void solution(int level) {

	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {

			//맵이 잠겼으면 1, 안잠겼으면 0
			if (map[i][j] <= level) mapstate[i][j] = 1;
		}
	}

	int cnt = find_LandCnt();
	if (cnt > ans) ans = cnt;
}

int main() {

	input();

	// 높이가 0~N까지 잠기는 경우 다 계산해보면서 최대 개수 찾기 
	for (int i = 0; i <= 100; i++) {
		memset(visited, 0, sizeof(visited));
		memset(mapstate, 0, sizeof(mapstate));
		solution(i);
	}

	cout << ans;
	return 0;
}
