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
#include <unordered_set>
#include <set>

#define endl '\n'
#define LIM 9223372036854775807


typedef long long ll;

using namespace std;

struct edge {
	int node;
	ll w;

	bool operator()(const edge& a, const edge& b) {
		return a.w > b.w;
	}
};


int n, m;
int x, z;
vector<int> p;
vector<vector<edge>> g;
vector<ll> distx;
vector<ll> distz;
priority_queue<edge, vector<edge>, edge> pq;
ll res = LIM;

void dijk(int st, vector<ll>& dist) {
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty()) {
		edge cur = pq.top(); pq.pop();
		
		if (dist[cur.node] < cur.w) continue;
		
		for (edge next : g[cur.node]) {
			if (dist[next.node] <= dist[cur.node] + next.w) continue;
			dist[next.node] = dist[cur.node] + next.w;
			pq.push({ next.node, dist[next.node] });
		}

	}

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	g.resize(n + 1);
	distx.resize(n + 1, LIM);
	distz.resize(n + 1, LIM);

	int u, v, w;
	int pc;

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
	}
	
	cin >> x >> z;

	cin >> pc;
	int inp;
	for (int i = 0; i < pc; i++)
	{
		cin >> inp;
		p.push_back(inp);
	}

	dijk(x, distx);
	dijk(z, distz);

	for (int i = 0; i < p.size(); i++) {
		if (distx[p[i]] == LIM || distz[p[i]] == LIM) continue;
		res = min(res, distx[p[i]] + distz[p[i]]);
	}

	cout << (res != LIM ? res : -1) << endl;

	return 0;
}
