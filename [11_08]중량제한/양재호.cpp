#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, a, b;
struct node {
	int num;
	int cost;
	bool operator < (const node& right) const {
		if (cost != right.cost) return cost < right.cost;
		return false;
	}
};
vector<node> arr[10010];
int dist[10010];

void dijkstra(int num) {
	priority_queue<node> pq;
	pq.push({ num, INT_MAX });
	dist[num] = INT_MAX;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.num] > now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = (dist[now.num] > next.cost) ? next.cost : dist[now.num];

			if (dist[next.num] < nextcost) {
				dist[next.num] = nextcost;
				pq.push({ next.num, nextcost });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}
	cin >> a >> b;

	dijkstra(a);
	
	cout << dist[b];

	return 0;
}
