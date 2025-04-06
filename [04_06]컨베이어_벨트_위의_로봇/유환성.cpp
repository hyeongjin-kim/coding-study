#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace std;

int N, K, A;
vector<int> belt;
int ans;

void input() {
	int num;
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		cin >> num;
		belt.push_back(num);
	}
}

bool check() {
	int cnt = 0;

	for (int i = 0; i < belt.size(); i++) {
		if (belt[i] == 0) cnt++;
		if (cnt >= K) return true;
	}
	return false;

}

void solution() {
	deque<int> robot;
	while (1) {

		ans++;
		int num;

		//	1.1 컨베이어 벨트 회전
		num = belt.back();
		belt.pop_back();
		belt.insert(belt.begin(), num);

		//	1.2 로봇의 위치 회전
		for (int i = 0; i < robot.size(); i++) {
			robot[i] = (robot[i] + 1) % (2 * N);
		}

		// 회전하면서 N-1 제거, N-1은 항상 앞
		if (!robot.empty() && robot.front() == N - 1) {
			robot.pop_front();
		}
		
		//	2. 로봇의 이동
		int size = robot.size();
		deque<int> temp; // 로봇의 새 위치
		bool occupied[101];
		memset(occupied, 0, sizeof(occupied));

		for (int i = 0; i < size; i++) {
			int cur = robot.front(); robot.pop_front();
			int np = (cur + 1) % (2 * N);

			// 내리는 위치인 경우
			if (np == N - 1 && belt[np] > 0) {
				belt[np]--;
				continue;
			}

			if (belt[np] > 0 && !occupied[np]) {
				belt[np]--;
				temp.push_back(np);
				occupied[np] = true;
			}
			else {
				temp.push_back(cur);
				occupied[cur] = true;
			}
		}
		robot = temp;

		// 이동 후 N-1에 있는 로봇 내리기
		if (!robot.empty() && robot.front() == N - 1) {
			robot.pop_front();
		}


		//	3. 로봇 올리기
		if (belt[0] > 0) {
			robot.push_back(0);
			belt[0]--;
		}
		//	4. 조건에 따라 반복
		if (check()) {// 내구도가 0인 벨트 체크

			return;
		}

	}


}

int main() {

	input();
	solution();

	cout << ans;
	return 0;
}
