#include <iostream>
#include <queue>

using namespace std;

bool vis[300][300];
int dx[] = { -2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0;tc < T;++tc) {
		int l, sx, sy, tx, ty;
		cin >> l >> sx >> sy >> tx >> ty;
		queue<pair<int, pair<int, int>>> q;
		q.push({ 0,{sx,sy} });
		fill(&vis[0][0], &vis[l - 1][l], false);
		vis[sx][sy] = true;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			int curX = cur.second.first;
			int curY = cur.second.second;
			int curCost = cur.first;
			if (curX == tx && curY == ty) {
				cout << curCost << "\n";
				break;
			}
			for (int d = 0;d < 8;++d) {
				int nx = curX + dx[d];
				int ny = curY + dy[d];
				if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = true;
				q.push({ curCost + 1,{nx,ny} });
			}
		}
	}
	return 0;
}
