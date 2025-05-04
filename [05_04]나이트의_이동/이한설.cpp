#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> directions = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, 
									{1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

void bfs(vector<vector<int>>& visited, int sx, int sy, int ex, int ey) {
	queue<pair<int, int>> q;
	int x = sx;
	int y = sy;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		if (cx == ex && cy == ey) {
			return;
		}
		int nx, ny;
		q.pop();


		for (auto& dir : directions) {
			nx = cx + dir[0];
			ny = cy + dir[1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] > 0) {
				continue;
			}
			else {
				visited[nx][ny] = visited[cx][cy] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		int sx, sy, ex, ey; 
		cin >> sx >> sy;
		cin >> ex >> ey;
		vector<vector<int>> visited(N, vector<int>(N, 0));
		
		bfs(visited, sx, sy, ex, ey);
		
		cout << visited[ex][ey] - 1 << endl;
	}
}
