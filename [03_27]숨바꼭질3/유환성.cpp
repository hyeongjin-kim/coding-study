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

		if (g == cur) {//������ ã�Ҿ�
			return;
		}

		while (inRange(te_position)) { //�����̵�
			if (cur == 0) break;
			if (visited[te_position] == -1) {
				visited[te_position] = visited[cur];
				Q.push(te_position);
			}

			if (g == te_position) { //�����̵����� ������ ã�Ҿ�
				return;
			}
			te_position *= 2;
		}

		for (int dir = 0; dir < 2;dir++) { // �ȱ� 
			int nx = cur + dx[dir];

			if (!inRange(nx))continue; //���� ���̸� continue
			if (visited[nx] != -1)continue; // �̹� ���� ��������� pass

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