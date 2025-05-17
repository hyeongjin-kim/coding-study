#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N;
char cmd[15];
int visited[15];
vector<int> res;

int flag;

void input() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> cmd[i];
	}
}

void init() {

	flag = 0;
	memset(visited, 0, sizeof(visited));
	res.clear();
}

void solution(int depth, int mode) {

	/*
	9부터 0까지 내려가면서 백트래킹 한번만
	0부터 9까지 올라가면서 백트래킹 한번만
	*/

	if (depth >= N+1) {
		for (int i = 0; i < N+1; i++) {
			cout << res[i];
		}
		cout << "\n";

		flag = 1;

		return;
	}

	if (mode == 1) {
		for (int i = 9; i >= 0; i--) {
			if (flag) return;
			if (visited[i])continue;
			if (depth > 0) {
				if (cmd[depth] == '<') {
					if (res[depth - 1] >= i)continue;
				}
				else if (cmd[depth] == '>') {
					if (res[depth - 1] <= i)continue;
				}
			}

			visited[i] = 1;
			res.push_back(i);
			solution(depth + 1, mode);
			res.pop_back();
			visited[i] = 0;
		}
	}
	if (mode == 2) {
		for (int i = 0; i <= 9; i++) {
			if (flag) return;
			if (visited[i])continue;
			if (depth > 0) {
				if (cmd[depth] == '<') {
					if (res[depth - 1] >= i)continue;
				}
				else if (cmd[depth] == '>') {
					if (res[depth - 1] <= i)continue;
				}
			}

			visited[i] = 1;
			res.push_back(i);
			solution(depth + 1, mode);
			res.pop_back();
			visited[i] = 0;
		}
	}

}

int main() {

	input();
	solution(0, 1);
	init();
	solution(0, 2);

	return 0;
}
