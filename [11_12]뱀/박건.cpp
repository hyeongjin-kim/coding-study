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
#include <utility>

#define endl '\n'
#define LIM 9223372036854775807


typedef long long ll;

using namespace std;

struct pos {
	int y;
	int x;
};

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

int n, k, l;
int board[102][102];
deque<pos> snake;
deque<pair<int, char>> command;
int d = 1;
int timer;

bool inRange(int y, int x) {
	return y >= 1 && y <= n && x >= 1 && x <= n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		board[y][x] = 2;
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		command.push_back({ t, dir });
	}
	
	snake.push_back({ 1, 1 });
	board[1][1] = 1;

	while (1) {
		timer++;
		int cury = snake.front().y;
		int curx = snake.front().x;
		int ny = cury + dy[d];
		int nx = curx + dx[d];


		if (!inRange(ny, nx) || board[ny][nx] == 1) break;

		if (board[ny][nx] != 2) {
			board[snake.back().y][snake.back().x] = 0;
			snake.pop_back();
		}

		snake.push_front({ ny, nx });
		board[ny][nx] = 1;

		if (command.empty() || command.front().first != timer) continue;

		if (command.front().second == 'L') {
			d = (d - 1 + 4) % 4;
		}
		else {
			d = (d + 1) % 4;
		}

		command.pop_front();

	}

	cout << timer << endl;


	return 0;
}
