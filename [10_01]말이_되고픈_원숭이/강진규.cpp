#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct step {
	int x, y;
	int dist, horse;

	bool operator<(const step& right) const {
		if (dist == right.dist) {
			if (horse == right.horse) {
				if (x == right.x)
					return y < right.y;
				return x < right.x;
			}
			return horse > right.horse;
		}
		return dist > right.dist;
	}
};

int horseMoveX[] = { -2,-1,1,2,2,1,-1,-2 };
int horseMoveY[] = { 1,2,2,1,-1,-2,-2,-1 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int K, W, H;
bool field[200][200];
int dist[200][200][31];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> W >> H;

	for (int i = 0; i < H; ++i)
		for (int j = 0; j < W; ++j)
			cin >> field[i][j];

	fill(&dist[0][1][0], &dist[199][199][31], -1);

	priority_queue<step> pq;
	pq.push({ 0,0,0,0 });
	while (!pq.empty()) {
		step cur = pq.top(); pq.pop();
		int curX = cur.x, curY = cur.y;
		int curDist = cur.dist, curHorse = cur.horse;
		if (curHorse < K) {
			for (int d = 0; d < 8; ++d) {
				int nx = curX + horseMoveX[d];
				int ny = curY + horseMoveY[d];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
				if (field[nx][ny]) continue;
				if (dist[nx][ny][curHorse + 1] != -1 && dist[nx][ny][curHorse + 1] <= curDist + 1) continue;
				dist[nx][ny][curHorse + 1] = curDist + 1;
				pq.push({ nx,ny,curDist + 1, curHorse + 1 });
			}
		}
		for (int d = 0; d < 4; ++d) {
			int nx = curX + dx[d];
			int ny = curY + dy[d];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (field[nx][ny]) continue;
			if (dist[nx][ny][curHorse] != -1 && dist[nx][ny][curHorse] <= curDist + 1) continue;
			dist[nx][ny][curHorse] = curDist + 1;
			pq.push({ nx,ny,curDist + 1,curHorse });
		}
	}
	int ans = 1000000;
	for (int i = 0; i < 31; ++i) {
		if (dist[H - 1][W - 1][i] == -1) continue;
		ans = min(ans, dist[H - 1][W - 1][i]);
	}

	cout << (ans == 1000000 ? -1 : ans);

	return 0;

}
