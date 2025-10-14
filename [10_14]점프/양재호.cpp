#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int visited[300][10010];
int n, m;
bool arr[10010];
struct node {
	int num;
	int cost;
};

void bfs() {
	queue<node> q;
	q.push({ 1, 0 });
	visited[0][1] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		if (now.num == n) return;
		else if (now.num > n) continue;

		for (int i = 0; i < 3; i++) {
			int next;
			int nextcost = now.cost;
			if (i == 0) {
				nextcost = now.cost - 1;
				next = now.num + nextcost;
				if (next <= 1) continue;
				if (nextcost < 0) continue;
			}
			else if (i == 1) {
				nextcost = now.cost;
				next = now.num + nextcost;
				if (next <= 1) continue;
			}
			else {
				nextcost = now.cost + 1;
				next = now.num + nextcost;
				if (next <= 1) continue;
			}
			if (arr[next]) continue;
			if (visited[nextcost][next] > -1) continue;
			visited[nextcost][next] = visited[now.cost][now.num] + 1;
			q.push({ next, nextcost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(visited, -1, sizeof(visited));
	memset(arr, false, sizeof(arr));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		arr[num] = true;
	}

	bfs();

	int ans = 600;
	for (int i = 0; i < 300; i++) {
		if (visited[i][n] != -1) {
			if (visited[i][n] < ans) ans = visited[i][n];
		}
	}

	if (ans == 600) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}
