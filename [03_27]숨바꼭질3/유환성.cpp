#include<iostream>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define SIZE 100000

int map[SIZE + 5];
int visited[SIZE + 5];
int s;
int g;

int dx[] = { -1,1 };

bool inRange(int x) {
	return 0 <= x && x <= SIZE;
}

queue <int> Q;

void solution() {
	Q.push(s);
	visited[s] = 0;

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int te_position = cur;

		if (g == cur) {//동생을 찾았어
			return;
		}

		while (inRange(te_position)) { //순간이동
			if (cur == 0) break;
			if (visited[te_position] == -1) {
				visited[te_position] = visited[cur];
				Q.push(te_position);
			}

			if (g == te_position) { //순간이동으로 동생을 찾았어
				return;
			}
			te_position *= 2;
		}

		for (int dir = 0; dir < 2;dir++) { // 걷기 
			int nx = cur + dx[dir];

			if (!inRange(nx))continue; //범위 밖이면 continue
			if (visited[nx] != -1)continue; // 이미 값이 들어있으면 pass

			visited[nx] = visited[cur] + 1;
			Q.push(nx);
		}

	}
}

int main() {
	cin >> s >> g;
	memset(visited, -1, sizeof(visited));

	solution();

	cout << visited[g];


	return 0;
}