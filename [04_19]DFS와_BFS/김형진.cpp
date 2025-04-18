#include <iostream>
#include <queue>
using namespace std;

//그래프의 연결관계를 저장하는 배열
int arr[1001][1001] = {};
//방문 여부 저장
int visit[1001] = {};

//방문한 순서 저장장
int result[1000] = {};

int N, M, V;

//이미 V는 방문했으므로 초기에 1
int num = 1;

void dfs(int idx) {
	//처음부터 시작해서 연결된 노드 중 방문 안한 노드를 방문
	for (int i = 1; i <= N; i++) {
		if (arr[idx][i] == 1 and visit[i] == 0) {
			result[num++] = i;
			visit[i] = 1;
			dfs(i);
		}
	}

}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		result[num++] = cur;
		q.pop();
        //처음부터 시작해서 연결된 노드 중 방문 안한 노드를 큐에 넣음
		for (int i = 1; i <= N; i++) {
			if (arr[cur][i] == 1 and visit[i] == 0) {
				visit[i] = 1;
				q.push(i);
			}
		}
	}


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> V;

	int a, b;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	result[0] = V;
	visit[V] = 1;
	dfs(V);

	for (int i = 0; i < num; i++) cout << result[i] << ' ';

	num = 0;
	cout << '\n';
	fill(visit, visit + 1001, 0);
	bfs(V);

	

	for (int i = 0; i < num; i++) cout << result[i] << ' ';


	return 0;

}