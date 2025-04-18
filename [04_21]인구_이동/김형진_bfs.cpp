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
    //이동이 없을 때까지
	while (moved) {
		moved = false;
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
                //방문 안한 칸이 있다면 탐색 시작작
				if (visit[i][j] == 0) {
					
					queue<pair<int, int>> q;
                    //탐색한 나라 목록을 저장하는 백터터
					target.clear();
					q.push({ i, j });
					target.push_back({ i, j });
					visit[i][j] = 1;
					int total_population = 0;
					//bfs로 조건에 맞는 나라를 탐색하고 총 인구수를 구함
                    while (!q.empty()) {
						auto cur = q.front();
						q.pop();	
						int r = cur.first, c = cur.second;

						total_population += arr[r][c];
                        
						for (int dir = 0; dir < 4; dir++) {
							int newr = r + dr[dir], newc = c + dc[dir];
							if (newr < 0 or newr >= N or newc < 0 or newc >= N) continue;
							if (visit[newr][newc] == 1) continue;
							if (L <= abs(arr[newr][newc] - arr[r][c]) and abs(arr[newr][newc] - arr[r][c]) <= R) {
								moved = true;
								q.push({ newr,newc });
								target.push_back({ newr, newc });
								visit[newr][newc] = 1;
							}

						}
					}
                    //만약 인구이동이 가능해 목록에 2개 이상의 나라가 있다면 인구 이동을 모든 나라에 반영함
					if (target.size() > 1) {
						int population_after_move = total_population / target.size();
						for(auto cur: target){
							int r = cur.first, c = cur.second;
							arr[r][c] = population_after_move;
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