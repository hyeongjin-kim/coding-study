#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[20][20] = {};
bool visit[26];

int R, C;

//방향 배열
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

//지금까지 최대로 지나간 알파벳 수
int ans = 0;

//지금 보는 경로가 지나간 알파벳 수
int cnt = 1;

void dfs(int r, int c) {
	//최대로 지나간 알파벳 수 갱신
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++) {
		int newr = r + dr[i], newc = c + dc[i];
		if (newr < 0 or newr >= R or newc < 0 or newc >= C) continue;
		//이 알파벳을 지난 것이 없다면 지나감
		if (visit[arr[newr][newc]] == 0) {
			visit[arr[newr][newc]] = 1; //지나갔다는 표시
			cnt++; //현재 지나간 알파벳 수 증가
			dfs(newr, newc);
			visit[arr[newr][newc]] = 0; //지나갔다는 표시 복구
			cnt--; //현재 지나간 알파벳 수 복구
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	char a;

	//계산하기 편하게 아예 알파벳을 0 ~ 25의 숫자로 맵핑해서 저장함
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> a;
			arr[r][c] = a - 'A';
		}
	}
	//시작지점은 무조건 방문한 상태임
	visit[arr[0][0]] = 1;
	dfs(0,0);

	cout << ans;

	return 0;
}