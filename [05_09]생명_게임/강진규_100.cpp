#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>

using namespace std;

bool arr[100][100];
int N, M, T;
int K, a, b;
vector<pair<int, int>> v;

int around(int x, int y) {
	int cnt = 0;
	for (int i = x - K;i <= x + K;++i) {
		if (i < 0 || i >= N) continue;
		for (int j = y - K;j <= y + K;++j) {
			if (j < 0 || j >= M) continue;
			if (i == x && j == y) continue;
			if (arr[i][j]) ++cnt;
		}
	}
	return cnt;
}

void update() {
	bool newArr[100][100];
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			int tmp = around(i, j);
			if (!arr[i][j]) {
				if (a < tmp && tmp <= b)
					newArr[i][j] = true;
				else
					newArr[i][j] = false;
			}
			else {
				if (tmp >= a && tmp <= b)
					newArr[i][j] = true;
				else
					newArr[i][j] = false;
			}
		}
	}
	//swap(newArr, arr);
	memcpy(arr, newArr, sizeof(newArr));
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> T;
	cin >> K >> a >> b;
	for (int i = 0;i < N;++i)
		for (int j = 0;j < M;++j) {
			char inp;
			cin >> inp;
			arr[i][j] = (inp == '*');
			/*if (arr[i][j])
				v.push_back({ i,j });*/
		}
	for (int t = 0;t < T;++t)
		update();

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			if (arr[i][j])
				cout << '*';
			else
				cout << '.';
		}
		cout << "\n";
	}
	return 0;
}
