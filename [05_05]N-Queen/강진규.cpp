#include <iostream>

using namespace std;

int pos[15];
bool vis[15];
int N, res;

bool checkDiag(int cur, int curPos) {
	for (int i = 0;i < cur;++i) {
		if (cur - i == abs(curPos - pos[i]))
			return false;
	}
	return true;
}

void rec(int cur) {
	if (cur == N) {
		++res;
		return;
	}
	for (int i = 0;i < N;++i) {
		if (vis[i])continue;
		if (!checkDiag(cur, i)) continue;
		vis[i] = true;
		pos[cur] = i;
		rec(cur + 1);
		vis[i] = false;
	}
}

int main(void) {
	cin >> N;
	
	rec(0);

	cout << res;
	return 0;
}
