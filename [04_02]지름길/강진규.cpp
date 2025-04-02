#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(void) {
	int N, D;
	cin >> N >> D;
	map<int, vector<pair<int, int>>> edges;
	int* minDist = new int[D+1];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for (int i = 0;i < N;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}
	pq.push({ 0,0 });
	for (int i = 1;i < D + 1;i++)
		minDist[i] = -1;
	minDist[0] = 0;
	while (!pq.empty()) {
		int curD = pq.top().first;
		int loc = pq.top().second;
		pq.pop();

		int nLoc = loc + 1;
		if (nLoc <= D) {
			if (minDist[nLoc] == -1 || minDist[nLoc] > minDist[loc] + 1) {
				minDist[nLoc] = minDist[loc] + 1;
				pq.push({ minDist[nLoc], nLoc });
			}
		}
		if (edges[loc].empty()) continue;
		for (auto it = edges[loc].begin();it != edges[loc].end();it++) {
			nLoc = it->first;
			int cost = it->second;
			if (nLoc > D) continue;
			if (minDist[nLoc] == -1 || minDist[nLoc] > minDist[loc] + cost) {
				minDist[nLoc] = minDist[loc] + cost;
				pq.push({ minDist[nLoc], nLoc });
			}
		}
	}
	cout << minDist[D];
	return 0;

}
