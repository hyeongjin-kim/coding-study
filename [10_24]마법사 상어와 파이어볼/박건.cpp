#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <map>

#define endl '\n'
#define LIM 987654321

using namespace std;

struct fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
};

const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
deque<fireball> board[52][52];
deque<fireball> temp;
int res = 0;

bool isRange(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= N;
}

void move() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			while (!board[i][j].empty()) {
				fireball cur = board[i][j].front(); board[i][j].pop_front();

				int ns = cur.s % N;

				int nr = ((cur.r - 1 + dy[cur.d] * ns) % N + N) % N + 1;
				int nc = ((cur.c - 1 + dx[cur.d] * ns) % N + N) % N + 1;
				

				
				temp.push_back({ nr, nc, cur.m, cur.s, cur.d });
			}
		}
	}
	while (!temp.empty()) {
		fireball cur = temp.front(); temp.pop_front();
		board[cur.r][cur.c].push_back(cur);
	}
}

void merge(int r, int c){
	int tm = 0;
	int ts = 0;
	bool iseven = true;
	bool isodd = true;

	for (int i = 0; i < board[r][c].size(); i++) {
		tm += board[r][c][i].m;
		ts += board[r][c][i].s;
		if (board[r][c][i].d & 1) {
			iseven = false;
		}
		else {
			isodd = false;
		}
	}

	tm /= 5;
	ts /= board[r][c].size();

	board[r][c].clear();

	if (tm == 0) return;

	if (iseven || isodd) {
		board[r][c].push_back({ r, c, tm, ts, 0 });
		board[r][c].push_back({ r, c, tm, ts, 2 });
		board[r][c].push_back({ r, c, tm, ts, 4 });
		board[r][c].push_back({ r, c, tm, ts, 6 });
	}
	else {
		board[r][c].push_back({ r, c, tm, ts, 1 });
		board[r][c].push_back({ r, c, tm, ts, 3 });
		board[r][c].push_back({ r, c, tm, ts, 5 });
		board[r][c].push_back({ r, c, tm, ts, 7 });
	}

	return;
}

void command() {
	move();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].size() >= 2) {
				merge(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int ir, ic, im, is, id;
		cin >> ir >> ic >> im >> is >> id;
		board[ir][ic].push_back({ ir, ic, im, is, id });
	}

	for (int i = 0; i < K; i++) {
		command();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				res += board[i][j][k].m;
			}
		}
	}

	cout << res << endl;

	return 0;
}