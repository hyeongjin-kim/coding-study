#include <iostream>
#include <vector>
using namespace std;

int R, C;
int map[21][21];
int visited[100];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int ans;

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < R && y < C;
}

void dfs(int x, int y, int depth) {

	if (ans < depth) ans = depth;

	visited[map[x][y]] = 1;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!inRange(nx, ny))continue;
		if (visited[map[nx][ny]])continue;

		dfs(nx, ny, depth + 1);

	}
	visited[map[x][y]] = 0;

}

int main() {

	cin >> R >> C;
	string str;

	for (int row = 0; row < R; row++) {
		cin >> str;
		for (int col = 0; col < str.size(); col++) {
			map[row][col] = str[col];
		}
	}

	dfs(0,0,1);
	cout << ans;

	return 0;
}
