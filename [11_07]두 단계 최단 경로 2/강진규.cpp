#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct edge {
	int to;
	int weight;
};

struct node {
	int to;
	long long weight;
	bool visFlag;

	bool operator<(const node& right) const {
		return weight > right.weight;
	}
};

vector<edge> edges[100001];
long long minDist[2][100001];
bool isMiddle[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({ v, w });
		edges[v].push_back({ u, w });
	}
	int x, z, p;
	cin >> x >> z >> p;

	priority_queue<node> q;

	while (p--) {
		int inp;
		cin >> inp;
		isMiddle[inp] = true;
	}

	fill(&minDist[0][0], &minDist[1][100001], -1);

	minDist[0][x] = 0;
	q.push({ x, 0, false });

	while (!q.empty()) {
		node cur = q.top(); q.pop();

		int curNode = cur.to;
		long long curWeight = cur.weight;
		bool visFlag = cur.visFlag;

		if (curNode == z && visFlag)
			break;

		for (edge e : edges[curNode]) {
			int nextNode = e.to;
			long long nextWeight = curWeight + (long long)e.weight;
			bool nextVisFlag = visFlag || isMiddle[nextNode];

			if (minDist[nextVisFlag][nextNode] != -1 && minDist[nextVisFlag][nextNode] <= nextWeight)
				continue;

			minDist[nextVisFlag][nextNode] = nextWeight;
			q.push({ nextNode, nextWeight, nextVisFlag });
		}
	}

	cout << minDist[1][z];

	return 0;
}
