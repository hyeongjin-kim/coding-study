#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> dice = { 1, 2, 3, 4, 5, 6 };

void bfs(int start, vector<int>& visited, unordered_map<int, vector<int>> graph) {
	queue<int> que;
	que.push(start);
	visited[start] = 1;

	while (!que.empty()) {
		int current = que.front();
		que.pop();

		if (current == 100) {
			break;
		}

		for (auto& num : dice) {
			int next = current + num;
			if (next > 100) break;
			if (visited[next] == 0) {
				if (graph.find(next) != graph.end() && visited[graph[next][0]] == 0) {
					visited[graph[next][0]] = visited[current] + 1;
					que.push(graph[next][0]);
				}
				else if (graph.find(next) == graph.end()) {
					visited[next] = visited[current] + 1;
					que.push(next);
				}
			}
		}
	}

}

int main() {
	int N, M; cin >> N >> M;
	unordered_map<int, vector<int>> graph;
	vector<int> visited(110, 0);

	for (int idx = 0; idx < N + M; idx++) {
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
	}

	bfs(1, visited, graph);
	cout << visited[100] - 1;

	//for (int idx = 0; idx < 110; idx++) {
	//	cout << idx << " " << visited[idx] << " ";
	//}
}
