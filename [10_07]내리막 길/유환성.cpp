#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int ans;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int board[505][505];
int route[505][505];


struct Pos {
	int x;
	int y;
};

bool in_range(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}
void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			route[i][j] = -1;
		}
	}
	
}
int solution(int x, int y) {


	// 아직 탐색 안한 부분 : 값 채워 넣기
	// 탐색 했던 부분 : 기존 배열에 더하기

	if (x == N - 1 && y == M - 1) {
		return 1;
	}
	
	//갔던 부분은 더 이상 안가기
	if (route[x][y] != -1) {
		return route[x][y];
	}

	route[x][y] = 0;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!in_range(nx, ny))continue;
		if (board[nx][ny] >= board[x][y])continue;

		route[x][y] += solution(nx, ny);

	}
	return route[x][y];
}

void output() {
	cout << ans<<"\n";
}


int main() {

	input();
	ans = solution(0, 0);
	output();

	return 0;
}
