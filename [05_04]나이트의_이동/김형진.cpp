#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

bool visit[300][300];

//나이트의 이동을 담은 방향배열
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int r, c, l;
		cin >> l >> r >> c;
		memset(visit, 0, sizeof(visit));
		queue < pair<int, int>> q;
		//현재 위치 담기
        q.push({ r, c });
		int er, ec;
		cin >> er >> ec;
		int dist = 0;
		bool check = false;
		while (!q.empty()) {
            //거리가 dist인 애들만 보기위해 현재 q의 크기만큼만 봄
            //이 뒤의 애들은 dist +1 인 애들임
			int j = q.size();

			for (int i = 0; i < j; i++) {
				auto cur = q.front();
				q.pop();
				int row = cur.first, col = cur.second;
                //찾으면 종료
				if (row == er and col == ec) {
					check = true;
					break;
				} 
                //8가지 가능성을 모두 테스트함
				for (int dir = 0; dir < 8; dir++) {
					int newr = row + dr[dir], newc = col + dc[dir];
					if (newr < 0 or newr >= l or newc < 0 or newc >= l) continue;
					if (visit[newr][newc]) continue;
					visit[newr][newc] = true;
					q.push({ newr, newc });
				}
			}
			if (check) break;
			dist++;
		}
		cout << dist << '\n';
	}
	

	return 0;
}