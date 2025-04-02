#include <iostream>
#include <queue>

using namespace std;

int xpos[] = { -1, 1, 0, 0 };
int ypos[] = { 0, 0, -1, 1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int** arr = new int* [N];
	int** minDist = new int* [N];
	int sx, sy;
	for (int i = 0;i < N;i++) {
		arr[i] = new int[M];
		minDist[i] = new int[M];
		for (int j = 0;j < M;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				sx = i;
				sy = j;
			}
			
			if (arr[i][j] == 0)
				minDist[i][j] = 0;
			else
				minDist[i][j] = -1;
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
	pq.push({ 0,{ sx, sy } });
	minDist[sx][sy] = 0;
	while (!pq.empty()) {
		int curStep = pq.top().first;
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		pq.pop();


		for (int d = 0;d < 4;d++) {
			int nx = curX + xpos[d];
			int ny = curY + ypos[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || !arr[nx][ny]) continue;

			if (minDist[nx][ny] == -1) {
				minDist[nx][ny] = minDist[curX][curY] + 1;
				pq.push({ minDist[nx][ny], {nx,ny} });
			}
			else {
				if (minDist[nx][ny] > minDist[curX][curY] + 1) {
					minDist[nx][ny] = minDist[curX][curY] + 1;
					pq.push({ minDist[nx][ny], {nx,ny} });
				}
			}

			
		}

	}
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < M;j++)
			cout << minDist[i][j] << " ";
		cout << '\n';
	}
	return 0;
}
