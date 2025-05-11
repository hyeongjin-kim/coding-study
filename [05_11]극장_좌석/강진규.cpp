#include <iostream>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	int seat[40][3];
	bool fixed[40] = { false };
	for (int i = 0;i < M;++i) {
		int inp;
		cin >> inp;
		fixed[inp - 1] = true;
	}
	seat[0][0] = 0;
	seat[0][1] = 1;
	seat[0][2] = !(fixed[0] || fixed[1]);
	for (int i = 1;i < N;++i) {
		if (fixed[i]) {
			seat[i][0] = 0;
			seat[i][1] = seat[i - 1][0] + seat[i - 1][1];
			seat[i][2] = 0;
			continue;
		}
		seat[i][0] = seat[i - 1][2];
		seat[i][1] = seat[i - 1][0] + seat[i - 1][1];
		seat[i][2] = (i + 1 >= N || fixed[i + 1] ? 0 : seat[i - 1][0] + seat[i - 1][1]);
	}
	cout << seat[N - 1][0] + seat[N - 1][1];
	return 0;
}
