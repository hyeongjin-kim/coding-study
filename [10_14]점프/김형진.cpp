#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;

int arr[10005][155];



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	
	fill(&arr[0][0], &arr[0][0] + 10005 * 155, 1e9);

	arr[2][1] = 1;

	int no;

	for (int i = 0; i < M; i++) {
		cin >> no;
		arr[no][0] = -1;
	}

	for (int i = 2; i <= N; i++) {
		if (arr[i][0] == -1) continue;

		for (int j = 1; j < 150; j++) {
			if (arr[i][j] == 1e9) continue;
			if (j > 1 and i + j - 1 <= N) arr[i + j - 1][j - 1] = min(arr[i + j - 1][j - 1], arr[i][j] + 1);
			if(i + j  <= N) arr[i + j][j] = min(arr[i + j][j], arr[i][j] + 1);
			if (i + j + 1 <= N) arr[i + j + 1][j + 1] = min(arr[i + j + 1][j + 1], arr[i][j] + 1);
		}
	}

	int ans = 1e9;

	for (int i = 1; i < 150; i++) {
		ans = min(ans, arr[N][i]);
	}

	if (ans == 1e9) ans = -1;

	cout << ans;

	return 0;

}
