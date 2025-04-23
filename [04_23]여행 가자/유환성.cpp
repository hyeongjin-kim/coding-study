
//못 품

#include <iostream>
#include <vector>
using namespace std;

int N, M;
int graph[201][201];
int visited[201][201];
vector<int> path;
vector<int> want;
int pre;
int ans;
bool flag;

bool check() {
	for (int i = 0; i < want.size(); i++) {
		bool f = false;
		for (int j = i; j < path.size(); j++) {
			if (want[i] == path[j]) f = true;

		}
		if (f == false) return false;
	}

	return true;

}

void dfs(int now) {

	if (check()) {
		flag = true;
		return;
	}

	for (int i = 0; i < N; i++) {
		int next = i;
		if (flag) break;
		if (graph[now][next] == 0)continue;
		if (visited[now][next])continue;

		visited[now][next] = 1;
		path.push_back(next+1);
		dfs(next);
		path.pop_back();
		visited[now][next] = 0;
	}

}

int main() {
	cin >> N >> M;
	int num;
	for (int from = 0; from < N; from++) {
		for (int to = 0; to < N; to++) {
			cin >> num;
			graph[from][to] = num;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> num;
		want.push_back(num);
	}

	dfs(want[0]);

	if (flag) cout << "YES";
	else cout << "NO";


	return 0;
}
