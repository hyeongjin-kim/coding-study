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

#define endl '\n'
#define LIM 987654321

using namespace std;

struct edge {
	int node;
	int w;
	int coord;

	bool operator()(const edge& a, const edge& b) {
		if (a.w == b.w) return a.coord > b.coord;
		return a.w > b.w;
	}
};

int n, m;
int p, q;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<int> cons;
	vector<vector<edge>> g(n + 1);
	vector<pair<int, int>> dist(n + 1, { LIM, 0 });
	priority_queue<edge, vector<edge>, edge> pq;
	int resVal = 987654321;
	int res;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}

	cin >> p >> q;

	for (int i = 0; i < p; i++) {
		int a;
		cin >> a;
		pq.push({ a, 0, a });
		dist[a].first = 0;
	}

	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		cons.push_back(a);
	}

	while (!pq.empty()) {
		edge cur = pq.top(); pq.pop();

		if (dist[cur.node].first < cur.w) continue;

		for (edge next : g[cur.node]) {
			if (dist[next.node].first > dist[cur.node].first + next.w) {
				dist[next.node].first = dist[cur.node].first + next.w;
				dist[next.node].second = cur.coord;
				pq.push({ next.node, dist[next.node].first, cur.coord });
			}
		}
	}

	for (int i = 0; i < cons.size(); i++) {
		if (dist[cons[i]].first < resVal) {
			resVal = dist[cons[i]].first;
			res = dist[cons[i]].second;
		}
	}
	
	cout << res << endl;

	return 0;
}
