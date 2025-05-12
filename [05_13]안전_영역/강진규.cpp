#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100][100];
bool vis[100][100];

struct coord {
	int x, y;
};

int xpos[] = { 0,0,-1,1 };
int ypos[] = { -1,1,0,0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int minH = 200, maxH = 0;
	for (int i = 0;i < N;++i)
		for (int j = 0;j < N;++j) {
			cin >> arr[i][j];
			minH = (minH <= arr[i][j] ? minH : arr[i][j]);
			maxH = (maxH >= arr[i][j] ? maxH : arr[i][j]);
		}
	int totalMax = 1;
	for (int h = minH;h < maxH;++h) {
		fill(&vis[0][0], &vis[99][100], false);
		int curMax = 0;
		for (int i = 0;i < N;++i) {
			for (int j = 0;j < N;++j) {
				if (vis[i][j] || arr[i][j] <= h) continue;
				++curMax;
				queue<coord> q;
				q.push({ i,j });
				vis[i][j] = true;
				while (!q.empty()) {
					int curX = q.front().x, curY = q.front().y; q.pop();
					for (int d = 0;d < 4;++d) {
						int nx = curX + xpos[d];
						int ny = curY + ypos[d];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[nx][ny] || arr[nx][ny] <= h) continue;
						vis[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}
		totalMax = max(totalMax, curMax);
	}
	cout << totalMax;
	return 0;
}
