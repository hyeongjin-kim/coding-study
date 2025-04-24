#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, H;
vector<vector<int>> directions = { {1, 0, 0}, {-1, 0, 0}, { 0, 1, 0 }, {0, 0, 1}, {0, -1, 0}, {0, 0, -1} };


void bfs(vector<vector<int>> rotten_tomato, vector<vector<vector<int>>>& tomato, vector<vector<vector<int>>>& visited) {
	queue<pair<int, pair<int, int>>> q;
	for (auto& rtmt : rotten_tomato) {
		int sh = rtmt[0];
		int sx = rtmt[1];
		int sy = rtmt[2];
		q.push({ sh, {sx, sy} });
		visited[sh][sx][sy] = 1;
	}

	while (!q.empty()) {
		int ch = q.front().first;
		int cx = q.front().second.first;
		int cy = q.front().second.second;
		q.pop();
		for (auto& dir : directions) {
			int nh = ch + dir[0];
			int nx = cx + dir[1];
			int ny = cy + dir[2];

			if (nh < 0 || nh >= H || nx < 0 || nx >= N || ny < 0 || ny >= M || tomato[nh][nx][ny] == -1 || tomato[nh][nx][ny] > 0) {
				continue;
			}
			else if (visited[nh][nx][ny] == 0 && tomato[nh][nx][ny] == 0) {
				visited[nh][nx][ny] = visited[ch][cx][cy] + 1;
				q.push({ nh, {nx, ny} });
			}
		}
	}

}

int main() {
	cin >> M >> N >> H;
	vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M, 0)));
	vector<vector<vector<int>>> visited(H, vector<vector<int>>(N, vector<int>(M, 0)));
	vector<vector<int>> rotten_tomato;

	for (int idx = 0; idx < H; idx++) {
		for (int jdx = 0; jdx < N; jdx++) {
			for (int kdx = 0; kdx < M; kdx++) {
				int tmt; cin >> tmt;
				tomato[idx][jdx][kdx] = tmt;
				if (tmt == -1) {
					visited[idx][jdx][kdx] = -1;
				}
				else if (tmt == 1) {
					rotten_tomato.push_back({ idx, jdx, kdx });
				}
			}
		}
	}
	bfs(rotten_tomato, tomato, visited);

	int max = 0;
	for (int idx = 0; idx < H; idx++) {
		for (int jdx = 0; jdx < N; jdx++) {
			for (int kdx = 0; kdx < M; kdx++) {
				int score = visited[idx][jdx][kdx];
				// cout << score << " ";
				if (score == 0) {
					cout << -1;
					return 0;
				}
				else {
					if (max < score) {
						max = score;
					}
				}
			}
			//cout << endl;
		}
		//cout << endl;
	}

	cout << max - 1;
	return 0;
}
