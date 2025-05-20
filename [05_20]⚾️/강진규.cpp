#include <iostream>
//#include <queue>

using namespace std;
int arr[50][9];
int batterIdx[9];
bool vis[9];
int N;
int maxScore;

void rec(int depth) {
	if (depth == 9) {
		int batter = 0;
		int score = 0;
		for (int inn = 0;inn < N;++inn) {
			/*queue<int> q;
			q.push(0);
			q.push(0);
			q.push(0);*/
			int out = 0;
			bool first = false, second = false, third = false;
			while (out < 3) {
				switch (arr[inn][batterIdx[batter++ % 9]]) {
				case 0:
					++out; break;
				case 1:
					/*score += q.front(); q.pop();
					q.push(1);*/
					score += third;
					third = second;
					second = first;
					first = true;
					break;
				case 2:
					/*score += q.front(); q.pop();
					score += q.front(); q.pop();
					q.push(1); q.push(0);*/
					score += third + second;
					third = first;
					second = true;
					first = false;
					break;
				case 3:
					/*score += q.front(); q.pop();
					score += q.front(); q.pop();
					score += q.front(); q.pop();
					q.push(1); q.push(0); q.push(0);*/
					score += third + second + first;
					third = true;
					second = first = false;
					break;
				case 4:
					/*score += q.front(); q.pop();
					score += q.front(); q.pop();
					score += q.front(); q.pop();
					++score;
					q.push(0); q.push(0); q.push(0);*/
					score += third + second + first + 1;
					third = second = first = false;
				}
			}
		}
		maxScore = max(maxScore, score);
		return;
	}
	if (depth == 3) {
		batterIdx[3] = 0;
		rec(depth + 1);
		return;
	}
	for (int i = 1;i < 9;++i) {
		if (vis[i]) continue;
		vis[i] = true;
		batterIdx[depth] = i;
		rec(depth + 1);
		vis[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;++i)
		for (int j = 0;j < 9;++j)
			cin >> arr[i][j];

	rec(0);
	cout << maxScore;
	return 0;
}
