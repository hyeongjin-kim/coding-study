#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int  N;

bool isOutofRange(int r, int c) {
	return (r < 0 or r >= N or c < 0 or c >= N);
}

int map[130][130];
int visit[130][130];

int adj[130][130][4];

struct Node {
	int r, c, rupee;
};


struct cmp {
	bool operator()(const Node a, const Node b) {
		return a.rupee > b.rupee;
	}
};

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int cnt = 1;
	while (1) {
		cin >> N;

		if (N == 0) return 0;

		memset(map, 0, sizeof(map));
		fill(&visit[0][0], &visit[0][0] + 130 * 130, 1e9);
		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int dir = 0; dir < 4; dir++) {
					int ni = i + dr[dir], nj = j + dc[dir];
					if (isOutofRange(ni, nj)) continue;
					adj[i][j][dir] = map[ni][nj];
				}
			}
		}

		priority_queue<Node, vector<Node>, cmp> q;

		q.push({ 0,0,map[0][0] });

		while (!q.empty()) {
			Node cur = q.top();
			q.pop();
			int r = cur.r, c = cur.c, rupee = cur.rupee;
			if (visit[r][c] <= rupee) continue;
			visit[r][c] = rupee;
			if (r == N - 1 and c == N - 1) break;

			for (int dir = 0; dir < 4; dir++) {
				int nr = r + dr[dir], nc = c + dc[dir];
				if (isOutofRange(nr, nc)) continue;
				if (visit[nr][nc] <= rupee + map[nr][nc]) continue;
				q.push({ nr, nc, rupee + map[nr][nc] });
			}
		}
		cout << "Problem " << cnt << ": " << visit[N - 1][N - 1] << endl;
		cnt++;
	}

	

	return 0;
}