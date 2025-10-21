#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, p, q;
struct node {
	int num;
	int cost;
	bool operator <(node right) const {
		return cost > right.cost;
	}
};
vector<node> arr[5010];
vector<int> home;
int dist[5010];
priority_queue<node> pq;

void dijkstra() {

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = dist[now.num] + next.cost;

			if (dist[next.num] <= nextcost) continue;
			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	fill(dist, dist + n + 1, INT_MAX);

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}

	cin >> p >> q;

	for (int i = 0; i < p; i++) {
		int num;
		cin >> num;
		home.push_back(num);
	}
	sort(home.begin(), home.end());
	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		pq.push({ num, 0 });
		dist[num] = 0;
	}
	
	dijkstra();

	int min = INT_MAX;
	int min_idx;
	for (int i = 0; i < home.size(); i++) {
		if (dist[home[i]] < min) {
			min = dist[home[i]];
			min_idx = home[i];
		}
	}

	cout << min_idx;

	return 0;
}
