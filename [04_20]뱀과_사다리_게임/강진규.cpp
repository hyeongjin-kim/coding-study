#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

int arr[100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N >> M;

	memset(arr, 0, 100 * sizeof(int));

	for (int i = 0;i < N + M;++i) {
		int x, y;
		cin >> x >> y;
		arr[x - 1] = y - 1;
	}

	queue<pair<int, int>> q;
	bool vis[100];
	memset(vis, 0, 100);
	q.push({ 0,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int step = q.front().second;
		q.pop();

		if (cur == 99) {
			cout << step;
			break;
		}

		for (int i = 1;i < 7;++i) {
			int nx = cur + i;
			if (nx >= 100) break;
			if (vis[nx]) continue;
			vis[nx] = true;
			if (arr[nx])
				nx = arr[nx];
			q.push({ nx, step + 1 });
		}
	}

	return 0;
}
