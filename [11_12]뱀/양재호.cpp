#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, k, l;
int arr[105][105];

struct node {
	int time;
	char drift;
};
struct edge {
	int y;
	int x;
};
vector<node> snake_time;
int ydir[] = { 0, 1, 0, -1 };
int xdir[] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		arr[y][x] = 5;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		int t;
		char a;
		cin >> t >> a;
		snake_time.push_back({ t, a });
	}

	int sy, sx;
	int idx = 0;
	int time = 0;
	int d = 0;
	sy = sx = 1;
	arr[sy][sx] = 1;
	deque<edge> snake;
	snake.push_back({ sy, sx });

	while (true) {
		if (idx < l && time == snake_time[idx].time) {
			if (snake_time[idx].drift == 'D') {
				d = (d + 1) % 4;
			}
			else if (snake_time[idx].drift == 'L') {
				d = (d + 3) % 4;
			}
			idx++;
		}
		sy += ydir[d];
		sx += xdir[d];
		if (sy < 1 || sx < 1 || sy > n || sx > n) break;
		if (arr[sy][sx] == 1) break;

		snake.push_front({ sy, sx });

		if(arr[sy][sx] != 5) {
			int ny = snake.back().y;
			int nx = snake.back().x;
			arr[ny][nx] = 0;
			snake.pop_back();
		}

		arr[sy][sx] = 1;

		time++;
	}

	cout << time + 1;

	return 0;
}
