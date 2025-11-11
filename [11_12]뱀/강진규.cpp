#include <iostream>
#include <deque>

using namespace std;

struct Coord {
	int x, y;
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

short changeDir[10001];
short field[100][100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	while (K--) {
		int r, c;
		cin >> r >> c;
		field[r - 1][c - 1] = 2;
	}

	int L;
	cin >> L;
	while (L--) {
		int X;
		char C;
		cin >> X >> C;
		changeDir[X] = (C == 'L' ? 3 : 1);
	}

	int d = 1;
	int tx = 1, ty = 1;

	deque<Coord> snake;
	snake.push_back({ 0,0 });

	int ans = 0;
	while (true) {
		Coord cur = snake.front();

		int nx = cur.x + dx[d];
		int ny = cur.y + dy[d];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
		if (field[nx][ny] == 1) break;

		snake.push_front({ nx,ny });

		if (!field[nx][ny]) {
			Coord tail = snake.back();
			field[tail.x][tail.y] = 0;
			snake.pop_back();
		}
		
		field[nx][ny] = 1;


		d = (d + changeDir[++ans]) % 4;

	}
	cout << ans + 1;
	return 0;
}
