#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct edge {
	int to;
	int weight;
};

struct node {
	int to;
	int weight;

	bool operator<(const node& right) const {
		return weight < right.weight;
	}
};

int minDist[10001];
vector<edge> edges[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	int A, B, C;
	while (M--) {
		cin >> A >> B >> C;
		edges[A].push_back({ B,C });
		edges[B].push_back({ A,C });
	}
	int S, E;
	cin >> S >> E;
	priority_queue<node> q;
	q.push({ S,2000000000 });
	memset(minDist, -1, 10001 * sizeof(int));
	minDist[S] = 2000000000;
	while (!q.empty()) {
		node cur = q.top();
		q.pop();
		int curNode = cur.to;
		int curWeight = cur.weight;

		if (curWeight < minDist[curNode])
			continue;

		for (edge e : edges[curNode]) {
			int nextNode = e.to;
			int nextWeight = min(curWeight, e.weight);

			if (minDist[nextNode] != -1 && minDist[nextNode] >= nextWeight)
				continue;

			minDist[nextNode] = nextWeight;
			q.push({ nextNode, nextWeight });
		}
	}

	cout << minDist[E];
	return 0;
}
