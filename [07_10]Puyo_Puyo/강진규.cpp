#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

char field[12][6];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool vis[12][6];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int total = 0, current, checked, nextCurrent;
	char checking;
	for (int i = 0; i < 12; ++i)
		for (int j = 0; j < 6; ++j) {
			cin >> field[i][j];
			if (field[i][j] != '.')
				++total;
		}
	current = nextCurrent = total;
	int combo = 0;

	while (1) {
		fill(&vis[0][0], &vis[11][6], false);
		checked = 0;
		for (int row = 11; row >= 0 && checked < current; --row) {
			for (int col = 0; col < 6 && checked < current; ++col) {
				if (field[row][col] == '.' || vis[row][col]) continue;
				vector<pair<int, int>> boom;
				boom.push_back({ row, col });
				checking = field[row][col];
				vis[row][col] = true;
				++checked;
				queue<pair<int, int>> q;
				q.push({ row, col });
				while (!q.empty()) {
					int curx = q.front().first;
					int cury = q.front().second;
					q.pop();
					for (int d = 0; d < 4; ++d) {
						int nx = curx + dx[d];
						int ny = cury + dy[d];
						if (nx < 0 || nx > 11 || ny < 0 || ny > 5) continue;
						if (field[nx][ny] == checking && !vis[nx][ny]) {
							vis[nx][ny] = true;
							q.push({ nx,ny });
							boom.push_back({ nx,ny });
							++checked;
						}
					}
				}
				if (boom.size() >= 4) {
					for (int i = 0; i < boom.size(); ++i) {
						field[boom[i].first][boom[i].second] = '.';
					}
					nextCurrent -= boom.size();
				}


			}
		}
		if (nextCurrent == current) break;
		++combo;
		if (nextCurrent == 0) break;
		current = nextCurrent;

		for (int col = 0; col < 6; ++col) {
			int bottom = 11, top = 10;
			while(top >= 0) {
				if (field[bottom][col] == '.') {
					for (; top >= 0 && field[top][col] == '.'; --top);
					if (top < 0) break;
					swap(field[bottom][col], field[top][col]);
					--bottom;
					--top;
				}
				else {
					if (--bottom == top)
						--top;
				}

			}
		}

	}

	cout << combo;
	return 0;

}
