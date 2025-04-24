#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
int box[100][100][100] = {};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, H;
	cin >> N >> M >> H;
  
	int tomato;

  //현재 익은 토마토를 담은 큐
  //tuple은 토마토의 좌표, 마지막 int는 토마토가 익은 날
	queue<pair<tuple<int, int, int>, int>> q;

	int yet = 0;

  //전후좌우상하를 이동하기 위한 방향 배열
	
  int dr[6] = {1,-1,0,0,0,0};
	int dc[6] = {0,0,-1,1,0,0};
	int dh[6] = {0,0,0,0,1,-1};

	//입력형식에 맞게 ijk를 맞춰서 입력받음
  for (int k = 0; k < H; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> tomato;
				if (tomato == 1) q.push({ {i,j,k}, 0 }); //익은 토마토라면 q에 넣음, 익은 날짜는 0
	
				else if (tomato == 0) yet++; //안익은 경우를 따로 셈
				box[i][j][k] = tomato; //배열에 저장
			}
		}
	}
	//이미 모두 익은 상태라면 0출력
  if (yet == 0) cout << 0;

	else {
		int r, c, h, day = 0;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			tie(r, c, h) = cur.first, day = cur.second;

			for (int i = 0; i < 6; i++) {
				int newr = r + dr[i], newc = c + dc[i], newh = h + dh[i];
				if (newr < 0 or newr >= M or newc < 0 or newc >= N or newh < 0 or newh >= H) continue; //박스 밖이면 넘어감
				if (box[newr][newc][newh] != 0) continue; //이미 익었거나 없으면 넘어감
				box[newr][newc][newh] = 1; //익은 상태로 만듬
				q.push({ {newr, newc, newh}, day + 1 }); //다음날 익었다고 q에 삽입
				yet--; //안익은 개수 감소
			}

		}
		if (yet == 0) cout << day; //모든 토마토가 익었다면, 마지막으로 익은 토마토의 날짜 출력
		else cout << -1; //안익은게 있으면 -1
	}
	
	


	return 0;
}
