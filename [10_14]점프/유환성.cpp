#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

bool visited[10005][200];
bool ban[10005];
int acc[] = { -1,0,1 };


bool in_range(int x) {
	return x >= 1 && x <= N;
}

struct state{
	int pos;
	int velo;
	int jmp;
};
queue <state> rock_reached;
int ans = 21e8;
void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int pos;
		cin >> pos;
		ban[pos] = true;
	}
}

void solution() {
	
	// 앞으로만 이동
	// 처음은 무조건 1칸 이동
	// X-1, X, X+1로 속도 변경 가능, 1이하는 불가
	// 금지된 돌은 올라갈 수 없음

	

	rock_reached.push({ 1,0,0 });

	while (!rock_reached.empty()) {
		auto cur = rock_reached.front(); rock_reached.pop();

		if (cur.pos ==  N) {
			if (ans > cur.jmp) {
				ans = cur.jmp;
			}
			break;
		}

		for (int dir = 0; dir < 3; dir++) {
			int nv = cur.velo + acc[dir];
			int np = cur.pos + nv;
			int nj = cur.jmp + 1;

			if (ban[np])continue;
			if (nv < 1) continue;
			if (!in_range(np))continue;
			if (visited[np][nv]) continue;
			

			visited[np][nv] = true;
			rock_reached.push({ np, nv, nj });
		}
	}

	if (ans == 21e8) cout << -1;
	else cout << ans;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solution();

	return 0;
}
