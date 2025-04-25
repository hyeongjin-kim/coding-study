#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//인접 리스트 adj[i]에 j가 있다 => i를 해킹하면 j를 해킹할 수 있다.
vector<vector<int>> adj(10001);
//방문 배열 visit[i] = j이면, i에서 j를 해킹함
int visit[10001];
int cnt[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;

	cin >> N >> M;
	int a, b;

    //인접 리스트 채우기
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
    //bfs를 담당하는 q
	queue<int> q;
    //결과를 저장하는 pq
	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= N; i++) {
		q.push(i);
		visit[i] = i;
		cnt[i]++;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int next : adj[cur]) { //현재 노드에서 갈 수 있는 곳
				if (visit[next] != i) {
					q.push(next); //q에 추가
					visit[next] = i; //i에서 해킹했음을 표시
					cnt[i]++; //해킹가능한 컴퓨터 수 추가
				}
			}
		}
		pq.push({cnt[i], -i}); //결과 저장, 컴퓨터 번호는 오름차순일 수 있도록 음수로 저장
	}

	int m = pq.top().first; //해킹할 수 있는 최대 컴퓨터수
	while (!pq.empty()) {
		if (pq.top().first < m) break; //최대로 해킹할 수 있는 경우라면 컴퓨터 번호 호출
		cout << -pq.top().second << ' ';
		pq.pop();
	}

	return 0;
}