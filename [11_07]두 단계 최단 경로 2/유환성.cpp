#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1e13

using namespace std;

/*
	서준이는 아빠로부터 생일선물로 세계 지도를 받아서 매우 기뻤다.
	세계 지도에서 최단 경로를 찾는 프로그램을 개발해서 아빠께 감사의 마음을 전달하려고 한다.
	세계 지도는 도시를 정점으로 갖고 도시 간의 도로를 간선으로 갖는 무방향성 그래프이며(undirected graph),
	도로의 길이가 간선의 가중치이다.
	출발 정점 X에서 출발해서 P개의 중간 정점 중 적어도 한 개의 정점을 반드시 거친 후
	도착 정점 Z에 도달하는 최단 거리를 구해서 우리 서준이를 도와주자.

	출발 정점 X에서 출발해서 P개의 중간 정점 중 적어도 1개 이상 거친 후 Z에 도착하는 최단거리
*/
int N, M;
int X, Z;
int P;
long long int mini = INF;
long long int dist[100005];

struct Edge {
	long long int to, cost;

	bool operator<(Edge r)const {
		return cost > r.cost;
	}
};

vector<vector<Edge>> graph(100005);
vector<int> Necessary;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ to,cost });
		graph[to].push_back({ from,cost });
	}
	cin >> X >> Z;
	cin >> P;

	for (int i = 0; i < P; i++) {
		int nes;
		cin >> nes;
		Necessary.push_back(nes);
	}
}

vector<long long int> dijkstra(int s) {
	vector<long long int> dist(N + 1, INF);
	priority_queue<Edge> pq;
	pq.push({ s, 0 });
	dist[s] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (cur.cost > dist[cur.to]) continue;

		for (auto next : graph[cur.to]) {
			long long int nextcost = dist[cur.to] + next.cost;

			if (nextcost >= dist[next.to]) continue;

			dist[next.to] = nextcost;
			pq.push({ next.to, nextcost });

		}

	}

	return dist;
}

void solution() {

	vector<long long int> distX = dijkstra(X);
	vector<long long int> distZ = dijkstra(Z);

	for (int i = 0; i < P; i++) {
		int mid = Necessary[i];

		if (mini > distX[mid] + distZ[mid]) mini = distX[mid] + distZ[mid];
	}
	if (mini == INF) mini = -1;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();
	cout << mini;

	return 0;
}
