#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool visit[50][50] = {};
int arr[50][50] = {};
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N, L, R;

vector<pair<int, int>> target;

//dfs로 국경이 열린 나라를 탐색함
void dfs(int r, int c, int & sum) {
	sum += arr[r][c];
	visit[r][c] = 1;
	target.push_back({ r, c });
	for (int i = 0; i < 4; i++) {
		int newr = r + dr[i], newc = c + dc[i];
		if (newr < 0 or newr >= N or newc < 0 or newc >= N) continue;
		if (visit[newr][newc] == 1) continue;
		int diff = abs(arr[newr][newc] - arr[r][c]);
		if(L <= diff and diff <= R)	dfs(newr, newc, sum);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	bool moved = true;
	int ans = 0;
	while (moved) {
		moved = false;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
                //방문하지 않은 나라가 있으면 방문
				if (visit[i][j] == 0) {
					int sum = 0;
					target.clear();
                    //dfs로 국경이 열린 나라 탐색
					dfs(i, j, sum);
                    //연합이 된 나라가 둘 이상이면 인구 이동이 있음 해당 나라에 이를 모두 반영
					if (target.size() > 1) {
						moved = true;
						for (auto tar : target) {
							int r = tar.first, c = tar.second;
							arr[r][c] = sum / target.size();
						}
					}
				}

			}
		}
		if (moved) ans++;
	}

	cout << ans;

	return 0;

}