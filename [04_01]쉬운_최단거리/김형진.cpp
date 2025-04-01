#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//지도, 방문 배열
int arr[1000][1000] = {};
int visit[1000][1000] = {};

//방향 배열
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	
	int N, M;
	cin >> N >> M;

  //시작 좌표
	int si, sj;

  //맵 받아오기, 시작 좌표 지정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				si = i, sj = j;
			}
		}
	}
	// 시작지점 거리 초기화
	visit[si][sj] = 0;

  //거리와 좌표를 담는 pq
	priority_queue<pair<int, pair<int, int>> >q;

  //시작지점 push
	q.push({ 0, {si, sj} });
	
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		
		int dist = -cur.first, r = cur.second.first, c = cur.second.second;
		//이미 방문한 곳이면 방문x
    if (visit[r][c] != 0) continue;
    //최소 거리 저장
		visit[r][c] = dist;

    //방향 배열을 돌면서 그 곳이 지도안에 있고, 갈 수 있는 곳이고, 가지 않았던 곳이면 push
		for (int i = 0; i < 4; i++) {
			int newr = r + dr[i], newc = c + dc[i];

			if (0 <= newr and newr < N and 0 <= newc and newc < M) {
				if (arr[newr][newc] != 0 and visit[newr][newc] == 0 ) {
					q.push({ -(dist + 1), {newr, newc} });
				}
			}
		}
	}

  //시작지점을 다시 갔을 것이기 때문에 0으로 초기화
	visit[si][sj] = 0;

  //조건에 맞춰 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(visit[i][j] != 0) cout << visit[i][j] << " ";
			else if(i == si and j == sj)cout << 0 << " ";
			else if(arr[i][j] == 0) cout << 0 << " ";
			else cout << -1 << " ";
		}
		cout << '\n';
	}

	return 0;
}
