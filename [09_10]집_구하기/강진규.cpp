#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <memory.h>

using namespace std;

int V, E;
//unordered_map<int, unordered_map<int, int>> graph;
vector<vector<pair<int, int>>> graph;
int sMinDist[10001];
int mMinDist[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	graph.assign(V, vector<pair<int, int>>());
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		/*if (graph[u].find(v) == graph[u].end()) {
			graph[u][v] = w;
			graph[v][u] = w;
		}
		else {
			graph[u][v] = min(graph[u][v], w);
			graph[v][u] = graph[u][v];
		}*/
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
	int M, x, S, y;
	cin >> M >> x;

	memset(mMinDist, -1, sizeof(mMinDist));
	priority_queue<pair<int, int>> pq;
	unordered_set<int> noHome;
	for (int i = 0; i < M; ++i) {
		int inp;
		cin >> inp;
		--inp;
		pq.push({ 0, inp });
		noHome.insert(inp);
		mMinDist[inp] = 0;
	}
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curDist = -pq.top().first;

		pq.pop();

		if (curDist > x) break;

		if (mMinDist[cur] < curDist)
			continue;		

		for (auto it : graph[cur]) {
			int next = it.first;
			int dist = it.second;

			if (mMinDist[next] != -1 && mMinDist[next] <= curDist + dist) continue;
			if (curDist + dist > x) continue;

			mMinDist[next] = curDist + dist;
			pq.push({ -mMinDist[next], next });
		}
	}
	priority_queue<pair<int, int>> pq2;
	cin >> S >> y;
	memset(sMinDist, -1, sizeof(sMinDist));
	for (int i = 0; i < S; ++i) {
		int inp;
		cin >> inp;
		--inp;
		pq2.push({ 0,inp });
		noHome.insert(inp);
		sMinDist[inp] = 0;
	}
	while (!pq2.empty()) {
		int cur = pq2.top().second;
		int curDist = -pq2.top().first;
		pq2.pop();

		if (curDist > y) break;

		if (sMinDist[cur] < curDist)
			continue;

		for (auto it : graph[cur]) {
			int next = it.first;
			int dist = it.second;

			if (sMinDist[next] != -1 && sMinDist[next] <= curDist + dist) continue;
			if (curDist + dist > y) continue;

			sMinDist[next] = curDist + dist;
			pq2.push({ -sMinDist[next], next });
		}
	}
	int ans = 200000002;
	for (int i = 0; i < V; ++i) {
		int mMin = mMinDist[i];
		int sMin = sMinDist[i];
		if (mMin == -1 || sMin == -1 || mMin > x || sMin > y || noHome.find(i) != noHome.end()) continue;
		ans = min(ans, mMin + sMin);
	}

	cout << ((ans == 200000002) ? -1 : ans);
	return 0;
}
