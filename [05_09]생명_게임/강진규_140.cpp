#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int arr[100][100];
int newArr[100][100];
bool noacc[100][100];
int N, M, T;
int K, a, b;

int around(int x, int y, int k) {
	int cnt = 0;
	int i, j;
	int myself = (noacc[x][y] ? 1 : 0);
	for (i = x + k;i >= N;--i);
	for (j = y + k;j >= M;--j);
	int rightDown = arr[i][j];
	int m, n;
	int rightUp, leftDown, leftUp;
	for (m = x - k - 1;m < 0;++m);
	if (m >= x - k)
		rightUp = 0;
	else
		rightUp = arr[m][j];
	for (n = y - K - 1;n < 0;++n);
	if (n >= y - k)
		leftDown = 0;
	else
		leftDown = arr[i][n];
	if (m >= x - k || n >= y - k)
		leftUp = 0;
	else
		leftUp = arr[m][n];

	return rightDown - rightUp - leftDown + leftUp - myself;
}

void update() {
	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			int val;
			int tmp = around(i, j, K);
			if (!noacc[i][j]) {
				if (a < tmp && tmp <= b)
					val = 1;
				else
					val = 0;
			}
			else {
				if (tmp >= a && tmp <= b)
					val = 1;
				else
					val = 0;
			}
			int up = (i - 1 < 0 ? 0 : newArr[i - 1][j]);
			int left = (j - 1 < 0 ? 0 : newArr[i][j - 1]);
			int diag = (i - 1 < 0 || j - 1 < 0 ? 0 : newArr[i - 1][j - 1]);
			newArr[i][j] = val + up + left - diag;
			noacc[i][j] = (val == 1);
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
			int up = (i - 1 < 0 ? 0 : arr[i - 1][j]);
			int left = (j - 1 < 0 ? 0 : arr[i][j - 1]);
			int diag = (i - 1 < 0 || j - 1 < 0 ? 0 : arr[i - 1][j - 1]);
			arr[i][j] = (inp == '*' ? 1 : 0) + up + left - diag;
			noacc[i][j] = (inp == '*');
		}
	for (int t = 0;t < T;++t)
		update();

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			if (noacc[i][j])
				cout << '*';
			else
				cout << '.';
		}
		cout << "\n";
	}
	return 0;
}
