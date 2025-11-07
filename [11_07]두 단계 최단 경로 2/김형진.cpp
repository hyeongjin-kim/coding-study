
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, u, v, w, P, x, y, z;

struct Road {
	long long dest = 0, weight = 0;
};

struct Node {
	long long cur, weight;
	bool fromX;
};

struct cmp {
	bool operator()(const Node& a, const Node& b) const {
		if (a.weight != b.weight) return a.weight > b.weight;
		return a.cur < b.cur;
	}
};

vector<vector<Road>> adj(100005, vector<Road>());

//X에서 오는 거리
long long distToX[100005];
//Z에서 오는 거리
long long distToZ[100005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N>> M;

	fill(distToX, distToX + 100005, 1e18);
	fill(distToZ, distToZ + 100005, 1e18);

	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	cin >> x >> z >> P;

	priority_queue<Node, vector<Node>, cmp> q;
  //q에 x, z 삽입
	q.push({ x, 0, true });
	q.push({ z, 0, false });
	distToX[x] = 0;
	distToZ[z] = 0;

	vector<long long> p;

	for (int i = 0; i < P; i++) {
		cin >> y;
		p.push_back(y);
	}

	while (!q.empty()) {
		Node Cur = q.top();
		q.pop();
		long long cur = Cur.cur, fromX = Cur.fromX, weight = Cur.weight;
		//x에서 온 경우
		if (fromX) {
			if (distToX[cur] < weight) continue;
			
			for (Road next : adj[cur]) {
				if (distToX[next.dest] <= weight + next.weight) continue;
				distToX[next.dest] = weight + next.weight;
				q.push({ next.dest, weight + next.weight, true });
			}
		}
    //z에서 온 경우
		else {
			if (distToZ[cur] < weight) continue;
			
			for (Road next : adj[cur]) {
				if (distToZ[next.dest] <= weight + next.weight) continue;
				distToZ[next.dest] = weight + next.weight;
				q.push({ next.dest, weight + next.weight, false });
			}
		}

	}
	
	long long ans = 1e18;
  //x에서 온 거리랑 z에서 온 거리를 더해서 ans와 비교
	for (int node : p) {
		if (distToZ[node] == 1e18 or distToX[node] == 1e18) continue;
		ans = min(ans, distToX[node] + distToZ[node]);
	}

	if (ans == 1e18) ans = -1;

	cout << ans;
	return 0;
}
