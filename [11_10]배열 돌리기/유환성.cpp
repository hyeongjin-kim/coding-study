#include<iostream>
#include<algorithm>
using namespace std;

int N, M, R;

int board[305][305];

void input() {
	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

void printAll() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void rotate() {

	int T = min(N, M) / 2;

	for (int i = 0; i < T; i++) {
		int sx = i, sy = i;
		int ex = N - i -1, ey = M - i -1;
		
		int x = sx;
		int y = sy;

		int temp = board[x][y];

		while (++x <= ex) swap(temp, board[x][y]); x--;
		while (++y <= ey) swap(temp, board[x][y]); y--;
		while (--x >= sx) swap(temp, board[x][y]); x++;
		while (--y >= sy) swap(temp, board[x][y]); y++;

	}
	
}

void solution() {

	for (int i = 0; i < R; i++) {
		rotate();
	}

	printAll();
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
	return 0;
}
