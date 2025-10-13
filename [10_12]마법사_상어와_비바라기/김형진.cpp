#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dr[9] = {0, 0,-1,-1,-1,0,1,1,1 };
int dc[9] = {0, -1,-1,0,1,1,1,0,-1 };
int N, M;
int map[55][55];
int visit[55][55];

struct Cloud {
	int r, c;
};

bool is_Out_of_Range(int r, int c) {
	return r < 1 or r > N or c < 1 or c > N;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	queue<Cloud> q;

	q.push({ N,1 });
	q.push({ N,2 });
	q.push({ N - 1, 1 });
	q.push({ N -1, 2 });


	for (int turn = 1; turn <= M; turn++) {
		int d, s;
		cin >> d >> s;
		s %= N;
		int cur_could = q.size();

		for (int i = 0; i < cur_could; i++) {
			Cloud cur = q.front();
			q.pop();

			int nr = ((cur.r - 1 + dr[d] * s) % N + N) % N + 1;
			int nc = ((cur.c - 1 + dc[d] * s) % N + N) % N + 1;
			map[nr][nc]++;
			q.push({ nr, nc });
			visit[nr][nc] = turn;
		}

		cur_could = q.size();

		for (int i = 0; i < cur_could; i++) {
			Cloud cur = q.front();
			q.pop();

			for (int j = 1; j <= 4; j++) {
				int r = cur.r, c = cur.c;
				int nr = r + dr[j * 2] , nc = c + dc[j * 2];
				if (is_Out_of_Range(nr, nc)) continue;
				if (map[nr][nc] > 0) map[r][c]++;
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] > 1 and visit[i][j] != turn) {
					q.push({ i , j });
					map[i][j] -= 2;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += map[i][j];
		}
	}

	cout << ans;
	return 0;

}
