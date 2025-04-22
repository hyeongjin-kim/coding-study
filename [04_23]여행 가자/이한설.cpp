#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

bool bfs(int srt, int end, unordered_map<int, vector<int>> graph, vector<bool>& visited) {
	queue<int> q;
	q.push(srt);
	visited[srt] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == end) {
			return true;
		}

		for (auto& node : graph[x]) {
			if (!visited[node]) {
				q.push(node);
				visited[node] = true;
			}
		}
	}
	return false;
}

int main() {
	int N, M; cin >> N >> M;
	unordered_map<int, vector<int>> graph;

	for (int idx = 0; idx < N; idx++) {
		for (int jdx = 0; jdx < N; jdx++){
			int x; cin >> x;
			if (x == 1) {
				graph[idx + 1].push_back(jdx + 1);
			}
		}
	}

	vector<int> target;

	for (int idx = 0; idx < M; idx++) {
		int y; cin >> y;
		target.push_back(y);
	}

	for (int idx = 0; idx < M - 1; idx++) {
		vector<bool> visited(N + 1, false);
		bool is_pos = bfs(target[idx], target[idx + 1], graph, visited);
		if (is_pos) {
			continue;
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}
