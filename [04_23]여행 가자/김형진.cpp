#include <iostream>

using namespace std;

int N, M;
bool adj[201][201];

int target[1001];

int visit[201];

bool found = false;

//index에서 tar로 갈 수 있는지 확인하는 dfs, 방문표시는 mark로 함
void dfs(int index, int tar, int mark) {
	visit[index] = mark;
  //발견! 찾았다는 표시를 하고 리턴
	if (index == tar) {
		found = true;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (found) return;
    //방문하지 않았고, 갈 수 있는 곳이라면 이동
		if (visit[i] < mark and adj[index][i] == 1) dfs(i, tar, mark);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			cin >> adj[i][j];
		}
	}
	int prev, now;
	cin >> prev;
  //prev 에서 now로 갈 수 있는지 확인하고 싶음
	for (int i = 1; i < M; i++) {
		cin >> now;
		found = false;

		visit[prev] = i;
		dfs(prev, now, i);
		if (found){ 
      //갈 수 있다면, 반복을 줄이기 위해 이 둘을 잇는 간선 추가
			adj[prev][now] = 1;
			adj[now][prev] = 1;
			prev = now;
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}
