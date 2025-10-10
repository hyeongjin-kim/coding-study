#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int weight[125][125];
int minDist[125][125];

struct step {
	int x, y, dist;

	bool operator<(const step& right) const {
		if (dist == right.dist) {
			if (x == right.x)
				return y < right.y;
			return x < right.x;
		}
		return dist > right.dist;
	}
};

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int problemCnt = 0;

	int N;


	while (true) {
		cin >> N;
		if (!N) break;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> weight[i][j];
			}
			memset(minDist[i], -1, 125 * sizeof(int));
		}
		
		
		priority_queue<step> pq;
		pq.push({ 0,0,weight[0][0] });
		minDist[0][0] = weight[0][0];
		while (!pq.empty()) {
			step cur = pq.top(); pq.pop();
			int curX = cur.x, curY = cur.y, curDist = cur.dist;
			if (curX == N - 1 && curY == N - 1)
				break;
			for (int d = 0; d < 4; ++d) {
				int nx = curX + dx[d], ny = curY + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				int nDist = curDist + weight[nx][ny];
				if (minDist[nx][ny] != -1 && minDist[nx][ny] <= nDist) continue;
				pq.push({ nx,ny,nDist });
				minDist[nx][ny] = nDist;
			}
		}
		cout << "Problem " << ++problemCnt << ": " << minDist[N - 1][N - 1] << "\n";
	}
	return 0;
}
