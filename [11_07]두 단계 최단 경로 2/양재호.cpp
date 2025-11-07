#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n, m, x, z;
int p;
vector<int> mid;
struct node {
	int num;
	long long cost;
	bool operator<(const node& right) const{
		if (cost != right.cost) return cost > right.cost;
		return false;
	}
};
vector<node> arr[100010];
long long dist1[100010];
long long dist2[100010];

void dijkstra(int num, long long dist[]) {
	fill(dist, dist + n + 1, LLONG_MAX);
	priority_queue<node> pq;
	pq.push({ num, 0 });
	dist[num] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			long long nextcost = dist[now.num] + next.cost;

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

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}

	cin >> x >> z >> p;

	dijkstra(x, dist1);
	dijkstra(z, dist2);

	for (int i = 0; i < p; i++) {
		int num;
		cin >> num;
		mid.push_back(num);
	}
	bool flag = false;
	long long ans = LLONG_MAX;
	for (int i = 0; i < p; i++) {
		if (dist1[mid[i]] == LLONG_MAX || dist2[mid[i]] == LLONG_MAX) continue;
		else {
			if (dist1[mid[i]] + dist2[mid[i]] < ans) {
				ans = dist1[mid[i]] + dist2[mid[i]];
				flag = true;
			}
		}
	}

	if (flag) {
		cout << ans;
	}
	else {
		cout << -1;
	}

	return 0;
}
