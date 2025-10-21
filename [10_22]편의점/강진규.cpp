#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct edge {
	int to;
	int dist;
};

struct queueNode {
	int start;
	int cur;
	int dist;

	bool operator<(const queueNode& right) const {
		if (dist == right.dist)
			return start > right.start;
		return dist > right.dist;
	}
};

vector<edge> edges[5001];
int minDist[5001];
bool isConv[5001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int p, q;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	priority_queue<queueNode> pq;

	cin >> p >> q;
	for (int i = 0; i < p; ++i) {
		int inp;
		cin >> inp;
		pq.push({ inp,inp,0 });
		minDist[inp] = -1;
	}
	for (int i = 0; i < q; ++i) {
		int inp;
		cin >> inp;
		isConv[inp] = true;
	}

	while (!pq.empty()) {
		queueNode cur = pq.top(); pq.pop();
		int startNode = cur.start;
		int curNode = cur.cur;
		int curDist = cur.dist;

		if (isConv[curNode]) {
			cout << startNode;
			return 0;
		}

		if (minDist[curNode] > 0 && curDist > minDist[curNode])
			continue;

		for (edge next : edges[curNode]) {
			int nextNode = next.to;
			int nextDist = minDist[curNode] + next.dist;

			if (minDist[nextNode] && minDist[nextNode] <= nextDist)
				continue;

			pq.push({ startNode, nextNode, nextDist });
			minDist[nextNode] = nextDist;
		}
	}
	return 0;
}
