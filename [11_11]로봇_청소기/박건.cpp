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
#define LIM 9223372036854775807


typedef long long ll;

using namespace std;

struct botinfo {
	int x;
	int y;
	int d;
};

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

bool room[51][51];
bool cleaned[51][51];
botinfo bot;
int n, m;
int res;

bool inRange(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}

bool behavior() {
	if (!cleaned[bot.y][bot.x]) {
		cleaned[bot.y][bot.x] = true;
		res++;
	}

	bool isClearAround = true;
	for (int i = 0; i < 4; i++) {
		int ny = bot.y + dy[i];
		int nx = bot.x + dx[i];
		if (!inRange(ny, nx))continue;
		if (!room[ny][nx] && !cleaned[ny][nx]) {
			isClearAround = false;
			break;
		}
	}

	if (isClearAround) { // 청소 다 됐으면
		int bd = (bot.d + 2) % 4;
		int by = bot.y + dy[bd];
		int bx = bot.x + dx[bd];

		if (room[by][bx]) return false; // 후진에 벽이 있으면
		else {
			bot.y = by;
			bot.x = bx;
			return true;
		}
	}
	else { // 청소 안된칸이 있으면
		int nd = (bot.d + 1) % 4;
		bot.d = nd;
		int ny = bot.y + dy[nd];
		int nx = bot.x + dx[nd];

		if (!room[ny][nx] && !cleaned[ny][nx]) {
			bot.y = ny;
			bot.x = nx;
		}

	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> bot.y >> bot.x >> bot.d;

	if (bot.d == 1) bot.d = 3;
	else if (bot.d == 3) bot.d = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	while (behavior());

	cout << res << endl;



	return 0;
}
