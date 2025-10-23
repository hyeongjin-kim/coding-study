#include <iostream>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

short n, m;
int a, b, c;
short sy, sx;
struct node {
	short y;
    short x;
	int cost;
	bool operator <(const node& right) const {
		return cost > right.cost;
	}
};
short ydir[] = { -1, 1, 0, 0 };
short xdir[] = { 0, 0, -1, 1 };
int arr[501][501];
int dist[501][501];
int Max, Max_y, Max_x;

void dijkstra(int y, int x) {
	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + m + 1, INT_MAX);
	}
	priority_queue<node> pq;
	pq.push({ y, x, 0 });
	dist[y][x] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.y][now.x] < now.cost) continue;
		
		for (int i = 0; i < 4; i++) {
			short ny = now.y + ydir[i];
			short nx = now.x + xdir[i];
			int nextcost;
			if (ny < 1 || nx < 1 || ny > n || nx > m) continue;
            if (dist[ny][nx] <= now.cost) continue;
			
			if (abs(arr[ny][nx] - arr[now.y][now.x]) > c) continue;
			if (arr[ny][nx] > arr[now.y][now.x]) nextcost = now.cost + (arr[ny][nx] - arr[now.y][now.x]) * a;
			else if (arr[ny][nx] < arr[now.y][now.x]) nextcost = now.cost + (arr[now.y][now.x] - arr[ny][nx]) * b;
			else nextcost = now.cost + 1;
			
			if (dist[ny][nx] <= nextcost) continue;
			dist[ny][nx] = nextcost;
			pq.push({ ny, nx, nextcost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	
	cin >> sy >> sx;

	cin >> a >> b >> c;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	Max = arr[sy][sx];

	dijkstra(sy, sx);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] > Max) {
				Max = arr[i][j];
				Max_y = i;
				Max_x = j;
			}
		}
	}

	if (dist[Max_y][Max_x] == INT_MAX) {
		cout << -1;
	}
	else {
		cout << dist[Max_y][Max_x];
	}

	return 0;
}
