#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> edges[1000];
vector<pair<int, int>> edgesRev[1000];
int minDist[1000];
int acc[1000];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, X;
	cin >> N >> M >> X;
	--X;
	int curmax = 0;
	memset(minDist, -1, sizeof(minDist));
	memset(acc, -1, sizeof(acc));
	for (int i = 0;i < M;++i) {
		int a,b,c;
		cin >> a >> b >> c;
		edges[a - 1].push_back({ b - 1,c });
		edgesRev[b - 1].push_back({ a - 1,c });
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ X,0 });
	minDist[X] = 0;
	while (!pq.empty()) {
		int cur = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();
		for (int j = 0;j < edges[cur].size();++j) {
			int next = edges[cur][j].first;
			int nextCost = edges[cur][j].second;
			if (minDist[next] == -1 || minDist[cur] + nextCost < minDist[next]) {
				minDist[next] = minDist[cur] + nextCost;
				pq.push({ next,minDist[next] });
			}
		}
	}
	swap(acc, minDist);
	pq.push({ X,0 });
	minDist[X] = 0;
	while (!pq.empty()) {
		int cur = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();
		for (int j = 0;j < edgesRev[cur].size();++j) {
			int next = edgesRev[cur][j].first;
			int nextCost = edgesRev[cur][j].second;
			if (minDist[next] == -1 || minDist[cur] + nextCost < minDist[next]) {
				minDist[next] = minDist[cur] + nextCost;
				pq.push({ next,minDist[next] });
			}
		}
	}
	for (int i = 0;i < N;++i) {
		curmax = max(curmax, acc[i] + minDist[i]);
	}
	cout << curmax;
	return 0;
}
