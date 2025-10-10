#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <cstring>

#define endl '\n'

#define LIM 987654321

using namespace std;

struct edge {
	int y;
	int x;
	int c;

	bool operator()(const edge& a, const edge& b) {
		return a.c > b.c;
	}
};

int n;
int board[126][126];
int cost[126][126];

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 0;

	while (true) {
		t++;
		cin >> n;
		if (n == 0) return 0;
		
		priority_queue<edge, vector<edge>, edge> pq;
		fill(&cost[0][0], &cost[125][126], LIM);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		
		cost[0][0] = board[0][0];
		pq.push({ 0, 0, cost[0][0]});
		
		while (!pq.empty()) {
			edge cur = pq.top(); pq.pop();
			if (cost[cur.y][cur.x] < cur.c) continue;

			for (int i = 0; i < 4; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				int nc = cur.c + board[ny][nx];

				if (!isRange(ny, nx)) continue;
				if (cost[ny][nx] <= nc) continue;
				cost[ny][nx] = nc;

				pq.push({ ny, nx, nc });

			}



		}

		cout << "Problem " << t << ": " << cost[n - 1][n - 1] << endl;

	}

	
	return 0;
	
}
