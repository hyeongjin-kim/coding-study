#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;
	int*** arr = new int** [3];
	int** cost = new int* [N];
	for (int i = 0;i < 3;i++) {
		arr[i] = new int* [N];
		for (int j = 0;j < N;j++) {
			cost[j] = new int[M];
			arr[i][j] = new int[M];
			for (int k = 0;k < M;k++) {
				arr[i][j][k] = 1000;
			}
		}
	}
	for (int i = 0;i < N;i++)
		for (int j = 0;j < M;j++)
			cin >> cost[i][j];

	for (int i = 0;i < M;i++)
		arr[0][0][i] = arr[1][0][i] = arr[2][0][i] = cost[0][i];
	for (int i = 1;i < N;i++) {
		for (int j = 0;j < M;j++) {
			for (int k = 0;k < 3;k++) {
				int nj = j - k + 1;
				if (nj < 0 || nj >= M)continue;
				for (int l = 0;l < 3;l++) {
					if (l == k) continue;
					arr[k][i][j] = min(arr[k][i][j], arr[l][i - 1][nj] + cost[i][j]);
				}
			}
		}
	}
	int res = INT_MAX;
	for(int i=0;i<3;i++)
		for(int j=0;j<M;j++)
			res = min(arr[i][N - 1][j], res);
	cout << res;
	return 0;
}
