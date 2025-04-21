#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int arr[50][50];
int vis[50][50];
int xpos[] = { 0,0,-1,1 };
int ypos[] = { -1,1,0,0 };
int N, L, R;

int bfs(int x, int y, int day) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	q.push({ x,y });
	v.push_back({ x,y });
	vis[x][y] = day;
	int total = arr[x][y];
	while (!q.empty()) {
		int curx = q.front().first, cury = q.front().second;
		q.pop();
		for (int d = 0;d < 4;++d) {
			int nx = curx + xpos[d];
			int ny = cury + ypos[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (vis[nx][ny] == day) continue;
			
			int diff = abs(arr[nx][ny] - arr[curx][cury]);
			if (diff <= R && diff >= L) {
				q.push({ nx,ny });
				v.push_back({ nx,ny });
				total += arr[nx][ny];
				vis[nx][ny] = day;
			}
		}
	}
	for (int i = 0;i < v.size();++i) {
		arr[v[i].first][v[i].second] = total / v.size();
	}
	return v.size() - 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	fill(&vis[0][0], &vis[49][49], 0);
	cin >> N >> L >> R;

	for (int i = 0;i < N;++i)
		for (int j = 0;j < N;++j)
			cin >> arr[i][j];

	int day = 1;
	while (1) {
		int todayN = 0;

		for (int i = 0;i < N;++i) {
			for (int j = 0;j < N;++j) {
				if (vis[i][j] < day) {
					if(bfs(i, j, day))
						++todayN;
				}
			}
		}
		if (!todayN)
			break;
		++day;
	}
	cout << day - 1;
	return 0;
}
