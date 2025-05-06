#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, E, Target;
// 시간 초과..
struct Node {
	int num;
	int cost;

	bool operator<(Node right)const{
		return cost < right.cost;
	}
};
vector<Node> alis[1001];
int dist[1001];
int ans = 0;
priority_queue<Node> pq;

void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = 21e8;
	}
}

int dijkstra(int start, int end) {

	init();

	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.num] < cur.cost) continue;

		for (int i = 0; i < alis[cur.num].size(); i++) {
			auto next = alis[cur.num][i];
			int nextcost = dist[cur.num] + next.cost;

			if (nextcost >= dist[next.num])continue;

			dist[next.num] = nextcost;
			pq.push({ next.num, nextcost });
		}
	}

	return dist[end];
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> E >> Target;


	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to>>cost;
		alis[from].push_back({to,cost});
	}
	for (int i = 1; i <= N; i++) {
		// 1번 부터 N번까지, Target 마을에 왔다 갔다 하기
		// 최단시간으로 간다는 가장 하에, 가장 오래 걸린 시간은?
		int val1 = dijkstra(i, Target);
		int val2 = dijkstra(Target, i);
		int val = val1 + val2;
		if (val > ans) ans = val;
	}

	cout << ans;

	return 0;
}
