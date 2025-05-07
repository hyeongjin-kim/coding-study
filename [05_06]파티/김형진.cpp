#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj(1001);

int visit[1001];
int totaldist[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, X;
	cin >> N >> M >> X;

	int s, e, w;
	//인접배열
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		adj[s].push_back({e, w});

	}
	//정답
	int ans = 0;
	//다익스트라를 N번 함
	for (int i = 1; i <= N; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

		pq.push({ 0, i });

		while (!pq.empty()) {
			auto cur = pq.top();
			pq.pop();

			int dist = cur.first, node = cur.second;
			if (visit[node] == i) continue;
			
			if (i != X and node == X) {
				//X에 도착하면 거리 갱신하고 정답 갱신
				totaldist[i] += dist;
				ans = max(ans, totaldist[i]);
				break;
			}
			if (i == X){
				//X에서 출발하는 경우 도착하는 노드마다 정답 갱신
				totaldist[node] += dist;
				ans = max(ans, totaldist[node]);
			}
			visit[node] = i;

			for (auto next : adj[node]) {
				int next_node = next.first, weight = next.second;
				if (visit[next_node] == i) continue;
				pq.push({ dist + weight, next_node });
			}

		}
	}

	cout << ans;

	return 0;
}
