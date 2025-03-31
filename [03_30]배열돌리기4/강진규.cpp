#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct rot {
	int r, c, s;
};

int** arr;
bool* vis;
vector<rot> order;
vector<rot> rots;
int N, M, K;
int curmin;

void cnt() {
	for (int i = 0; i < N; i++) {
		int cur = 0;
		for(int j=0;j<M;j++)
			cur += arr[i][j];
		curmin = min(curmin, cur);
	}
	return;
}

void rotate() {
	for (int i = 0; i < K; i++) {
		int r = order[i].r - 1, c = order[i].c - 1, s = order[i].s;
		for (int j = 1; j <= s; j++) {
			int tmp = arr[r - j][c - j];
			for (int k = r - j; k < r + j; k++)
				arr[k][c - j] = arr[k + 1][c - j];
			for (int k = c - j; k < c + j; k++)
				arr[r + j][k] = arr[r + j][k + 1];
			for (int k = r + j; k > r - j; k--)
				arr[k][c + j] = arr[k - 1][c + j];
			for (int k = c + j; k > c - j; k--)
				arr[r - j][k] = arr[r - j][k - 1];
			arr[r - j][c - j + 1] = tmp;
		}
	}
	cnt();
}

void rec(int depth) {
	if (K == depth) {
		int** tmp = new int* [N];
		for (int i = 0; i < N; i++) {
			tmp[i] = new int[M];
			for (int j = 0; j < M; j++)
				tmp[i][j] = arr[i][j];
		}
		rotate();
		swap(tmp, arr);
		for (int i = 0; i < N; i++)
			delete[] tmp[i];
		delete[] tmp;
		return;
	}
	for (int i = 0; i < K; i++) {
		if (vis[i])
			continue;
		vis[i] = true;
		order.push_back(rots[i]);
		rec(depth + 1);
		order.pop_back();
		vis[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	arr = new int* [N];
	vis = new bool[K];
	for (int i = 0; i < K; i++)
		vis[i] = false;
	for (int i = 0; i < N; i++) {
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	curmin = INT_MAX;
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rots.push_back({ r, c,s });
	}
	rec(0);
	cout << curmin;

	return 0;

}
