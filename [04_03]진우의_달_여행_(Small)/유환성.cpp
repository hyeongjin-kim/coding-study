#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int dp[6][6][3];
int map[6][6];
int dy[] = { -1,0,1 };
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int j = 0; j < M; j++) {
		for (int dir = 0; dir < 3;dir++) {
			dp[0][j][dir] = map[0][j];
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {

			for (int dir = 0;dir < 3; dir++) {

				if (dir == 0 && j == 0) dp[i][j][dir] = 21e8;  // 경계 체크
				else if(dir == 2 && j==M-1) dp[i][j][dir] = 21e8;  
          
				else dp[i][j][dir] = min(dp[i - 1][j + dy[dir]][(dir + 1) % 3],	dp[i - 1][j + dy[dir]][(dir + 2) % 3]) + map[i][j];

			}

		}
	}

  //마지막 dp배열 중 최소값 구하기
	int ans = 21e8;
	for (int j = 0; j < M; j++) {  
		for (int dir = 0; dir < 3;dir++) {
			if (dp[N - 1][j][dir] < ans) ans = dp[N - 1][j][dir];
		}
	}
	cout << ans;
	return 0;
}
