#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };

int sandX[][10] = {
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{0,1,0,-1,2,1,0,-1,0,1},
	{2,1,1,1,0,-1,-1,-1,-2,0},
	{0,-1,0,1,-2,-1,0,1,0,-1} };
int sandY[][10] = {
	{0,-1,0,1,-2,-1,0,1,0,-1},
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{0,1,0,-1,2,1,0,-1,0,1},
	{2,1,1,1,0,-1,-1,-1,-2,0} };

int sandPortion[] = { 2, 10, 7, 1, 5, 10, 7, 1, 2 };

int field[500][500];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> field[i][j];

	int dirCnt1, dirCnt2;
	dirCnt1 = dirCnt2 = 1;

	int dir = 0;
	int curX = N / 2;
	int curY = N / 2;
	int ans = 0;

	while (true) {
		for (int dirCnt = dirCnt1; dirCnt; --dirCnt) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int original = field[nx][ny];
			for (int i = 0; i < 9; ++i) {
				int curSandX = nx + sandX[dir][i];
				int curSandY = ny + sandY[dir][i];
				int move = sandPortion[i] * original / 100;
				if (curSandX < 0 || curSandX >= N || curSandY < 0 || curSandY >= N)
					ans += move;
				else
					field[curSandX][curSandY] += move;
				field[nx][ny] -= move;
			}
			int alphax = nx + sandX[dir][9];
			int alphay = ny + sandY[dir][9];
			if (alphax < 0 || alphax >= N || alphay < 0 || alphay >= N)
				ans += field[nx][ny];
			else
				field[alphax][alphay] += field[nx][ny];
			field[nx][ny] = 0;

			curX = nx;
			curY = ny;
			

		}
		if (curY < 0) break;
		swap(dirCnt1, dirCnt2);
		++dirCnt2;
		dir = (dir + 1) % 4;
	}

	cout << ans;
	return 0;
}
