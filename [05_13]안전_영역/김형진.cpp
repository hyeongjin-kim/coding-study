#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[100][100];
int visit[100][100];

struct Node {
	int r;
	int c;
};

int dr[4] = {0,0, 1, -1,};
int dc[4] = { 1, -1, 0, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	int m = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
      //탐색을 최대치 전까지 하기 위해 최대치를 미리 찾아놓기
			m = max(m, arr[i][j]);
		}
	}
  //아무것도 안잠겼을 때가 최소이고 1이다.
	int ans = 1;
  //각 높이마다 몇개의 안전영역이 나오는지 확인
	for (int t = 1; t < m; t++) {
		queue<Node> q;
		int tempans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
        //물에 잠기지 않고, 아직 탐사하지 않은 영역이 있다면 안전영역 하나 추가
				if (visit[i][j] < t and arr[i][j] > t) {
					q.push({ i, j });
					visit[i][j] = t;
					tempans++;
          //이 안전영역과 같은 영역에 속하는 칸 모두 찾기
					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int newr = cur.r + dr[dir], newc = cur.c + dc[dir];
							if (newr < 0 or newr >= N or newc < 0 or newc >= N) continue;
							if (visit[newr][newc] == t) continue;
							if (arr[newr][newc] <= t) continue;
							q.push({ newr, newc });
							visit[newr][newc] = t;
						}
					}
				}
			}
		}
		ans = max(ans, tempans);
	}

	cout << ans;
	return 0;
}
