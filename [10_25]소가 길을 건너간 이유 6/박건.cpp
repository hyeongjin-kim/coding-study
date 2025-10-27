#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

#define endl '\n'
#define LIM 987654321

typedef long long ll;

using namespace std;

// 100100100100

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int n, k, r;
int board[105][105];
vector<pair<int, int>> cows;
unordered_map<ll, bool> cantGo;
bool visited[105][105];
int res;
deque<pair<int, int>> dq;

ll hs(const ll &cy, const ll &cx, const ll &ny, const ll &nx) {
	return cy * 1'000'000'000 + cx * 1'000'000 + ny * 1'000 + nx;
}

bool isRange(int y, int x) {
	return y >= 1 && y <= n && x >= 1 && x <= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> r;

	for (int i = 0; i < r; i++) {
		int cy, cx, ny, nx;
		cin >> cy >> cx >> ny >> nx;

		cantGo[hs(cy, cx, ny, nx)] = true;
		cantGo[hs(ny, nx, cy, cx)] = true;
	}

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		cows.push_back({ y, x });
	}
	
	for (int i = 0; i < k; i++) {
		memset(visited, 0, sizeof(visited));
		dq.push_back(cows[i]);
		visited[cows[i].first][cows[i].second] = true;

		while (!dq.empty()) {
			int cury = dq.front().first;
			int curx = dq.front().second;
			dq.pop_front();

			for (int i = 0; i < 4; i++) {
				int ny = cury + dy[i];
				int nx = curx + dx[i];

				if (!isRange(ny, nx)) continue;
				if (visited[ny][nx]) continue;
				if (cantGo[hs(cury, curx, ny, nx)]) continue;

				dq.push_back({ ny, nx });
				visited[ny][nx] = true;
				
			}

		}

		for (int j = i + 1; j < k; j++) {
			int y = cows[j].first;
			int x = cows[j].second;
			if (!visited[y][x]) res++;
		}

	}

	cout << res << endl;


	return 0;
}