#include <iostream>

using namespace std;

int classroom[20][20];
bool favorite[401][401];

int happiness[5] = { 0, 1, 10, 100, 1000 };

int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int N;

bool in_range(int r, int c) {
	return r < 0 or r >= N or c < 0 or c >= N;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int student = 0; student < N * N; student++) {
		int cur_student;
		cin >> cur_student;

		int fri;
        //현재 학생이 좋아하는 학생 저장, 나중에 행복도 조사를 위해 또 필요하니 저장함
		for (int i = 0; i < 4; i++) {
			cin >> fri;
			favorite[cur_student][fri] = true;
		}

        //이 학생이 앉을 자리와 그 자리 주변 상태
		int max_friend = -1;
		int max_empty_seat = -1;

		int target_r = 0;
		int target_c = 0;

        //탐색 순서가 행 0 -> N, 열 0 -> N이므로 3, 4번 조건은 자동으로 만족
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (classroom[r][c] != 0) continue;

				int cur_friend = 0;
				int cur_empty_seat = 0;

				for (int dir = 0; dir < 4; dir++) {
					int newr = r + dr[dir], newc = c + dc[dir];

					if (in_range(newr, newc)) continue;

					int seat = classroom[newr][newc];
					
					if (seat == 0) cur_empty_seat++;
					else if (favorite[cur_student][seat]) cur_friend++;
					
				}

                //좋아하는 학생이 이전 자리보다 많거나, 같더라도 빈 자리가 더 많으면 앉을 자리 교체
				if (cur_friend > max_friend or (cur_friend == max_friend and cur_empty_seat > max_empty_seat) ) {
					max_friend = cur_friend;
					max_empty_seat = cur_empty_seat;
					target_r = r;
					target_c = c;
				}

			}
		}

		classroom[target_r][target_c] = cur_student;

	}

	int ans = 0;
    //학생별 행복도 조사
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int cur_student = classroom[r][c];

			int happy = 0;
            
			for (int dir = 0; dir < 4; dir++) {
				int newr = r + dr[dir], newc = c + dc[dir];

				if (in_range(newr, newc)) continue;

				int seat = classroom[newr][newc];

				if (favorite[cur_student][seat]) happy++;
			}

			ans += happiness[happy];

		}
	}

	cout << ans;

	return 0;
}