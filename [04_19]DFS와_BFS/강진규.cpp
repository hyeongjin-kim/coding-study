#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

bool edges[1000][1000];
bool vis[1000];
int visN;

int N, M, V;

void rec(int cur) {
	cout << cur + 1 << " ";
	for (int i = 0;i < N;++i) {
		if (!edges[cur][i]) continue;
		if (vis[i]) continue;
		vis[i] = true;
		++visN;
		rec(i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fill(&edges[0][0], &edges[999][999], 0);
	memset(vis, 0, 1000);
	cin >> N >> M >> V;

	while (M--) {
		int x, y;
		cin >> x >> y;
		edges[x - 1][y - 1] = true;
		edges[y - 1][x - 1] = true;
	}
	vis[V - 1] = true;
	rec(V - 1);
	cout << "\n";

	memset(vis, 0, 1000);
	visN = 0;
	queue<int> q;
	q.push(V - 1);
	vis[V - 1] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur + 1 << " ";
		for (int i = 0;i < N;++i) {
			if (!edges[cur][i]) continue;
			if (vis[i]) continue;
			vis[i] = true;
			q.push(i);
		}
	}


	return 0;
}
