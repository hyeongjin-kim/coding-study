#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int xpos[] = { 0,0,-1,1,0,0 };
int ypos[] = { -1,1,0,0,0,0 };
int zpos[] = { 0,0,0,0,1,-1 };

int arr[100][100][100];
struct coord {
	int x, y, z;
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N, H;
	cin >> M >> N >> H;
	queue<pair<coord,int>> q;
	int totalUnripe = 0;
	for (int k = 0;k < H;++k)
		for (int i = 0;i < N;++i)
			for (int j = 0;j < M;++j) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ { i,j,k },0 });
					//ripe[i][j][k] = true;
				}
				else if (arr[i][j][k] == 0)
					++totalUnripe;
			}
	if (!totalUnripe) {
		cout << 0;
		return 0;
	}

	int day = 0;
	while (!q.empty()) {
		int curx = q.front().first.x;
		int cury = q.front().first.y;
		int curz = q.front().first.z;
		int curDay = q.front().second;
		q.pop();

		for (int d = 0;d < 6;++d) {
			int nx = curx + xpos[d];
			int ny = cury + ypos[d];
			int nz = curz + zpos[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			if (arr[nx][ny][nz] != 0) continue;
			q.push({ {nx,ny,nz},curDay + 1 });
			arr[nx][ny][nz] = 1;
			if (--totalUnripe == 0) {
				day = curDay + 1;
				break;
			}
		}
		if (day)
			break;
	}
	if (!day)
		cout << -1;
	else
		cout << day;
	return 0;
	
}
