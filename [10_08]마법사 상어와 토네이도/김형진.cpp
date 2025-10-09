#include <iostream>

using namespace std;

int sand_dr[4][9] = { {1, 2, 1, 1, 0, -1, -1, -2, -1}, {0, 1, 1, 2, 3, 2, 1, 1, 0 } , {-1, -2, -1, -1, 0, 1, 1, 2, 1},{0, -1, -1, -2, -3, -2, -1, -1, 0} };
int sand_dc[4][9] = { {0, -1, -1, -2, -3, -2, -1, -1, 0} ,{1, 2, 1, 1, 0, -1, -1, -2, -1}, {0, 1, 1, 2, 3, 2, 1, 1, 0}, {-1, -2, -1, -1, 0, 1, 1, 2, 1} };

int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };

int sand_move[9] = { 1,2,7,10,5,10,7,2,1 };
int  N;

bool isOutofRange(int r, int c) {
	return (r < 0 or r >= N or c < 0 or c >= N);
}

int map[505][505];
int visit[505][505];


int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int dir = 0;
	int answer = 0;
	int r = N / 2, c = N / 2;
	
	for (int i = 0; i < N * 2 - 1; i++) {
		int step = i / 2 + 1;
		for (int j = 0; j < step; j++) {
			visit[r][c] = 1;
			int nr = r + dr[dir], nc = c + dc[dir];
			if (isOutofRange(nr, nc)) {
				cout << answer;
				return 0;
			}
			int sand = map[nr][nc];
			
			if (sand > 0) {
				int sand_alpha = sand;
				map[nr][nc] = 0;
				for (int sdir = 0; sdir < 9; sdir++) {
					int snr = r + sand_dr[dir][sdir], snc = c + sand_dc[dir][sdir];
					int sand_to_move = sand * sand_move[sdir] / 100;
					if (isOutofRange(snr, snc)) {
						answer += sand_to_move;
						sand_alpha -= sand_to_move;
					}
					else {
						map[snr][snc] += sand_to_move;
						sand_alpha -= sand_to_move;
					}
				}
				int nnr = nr + dr[dir], nnc = nc + dc[dir];
				if (isOutofRange(nnr, nnc)) {
					answer += sand_alpha;
				}
				else {
					map[nnr][nnc] += sand_alpha;
				}
			}
			r = nr, c = nc;
		}
		dir = (dir + 1) % 4;
	}

	return 0;
}