#include <iostream>
using namespace std;

//백트래킹

//백트래킹으로 모든 좌표에서 색종이 1~5를 붙여보기
//붙일 때마다 겹치는 것을 방지하기 위해 0, 돌아오면 1로 다시 셋

int map[10][10];
int paper[6] = { 0,5,5,5,5,5 };
int ans = 21e8;
int cnt;
void input() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
}

bool check(int x, int y, int k) {
	for (int i = x; i < x + k;i++) {
		for (int j = y; j < y + k; j++) {
			if (map[i][j] == 0) return false;	//크기 k인 종이를 붙일 수 없음
		}
	}

	return true;
}

void attach(int x, int y, int k) {
	for (int i = x; i < x + k;i++) {
		for (int j = y; j < y + k; j++) {
			map[i][j] = 0;
		}
	}
}

void detach(int x, int y, int k) {
	for (int i = x; i < x + k;i++) {
		for (int j = y; j < y + k; j++) {
			map[i][j] = 1;
		}
	}
}
void solution(int x, int y) {

	if (x >= 10) {
		if (cnt < ans) ans = cnt;
		return;
	}
	
	if (map[x][y] == 0 || y >=10) {
		if (y < 9) solution(x, y + 1);
		else solution(x + 1, 0);
	}

	else {
		for (int i = 5; i > 0; i--) { //큰 종이부터 붙여보기
			if (check(x, y, i) && paper[i] > 0 && i <= 10-y && i <= 10-x) {	//붙일 수 있으면
				paper[i]--;
				attach(x, y, i); cnt++;	// 붙이기, 색종이 범위 모두 0으로 처리
				solution(x, y);
				detach(x, y, i); cnt--;	// 떼기, 모두 1로 복귀
				paper[i]++;
			}
		}
	}

}



int main() {
	
	input();
	solution(0,0);


	if (ans == 21e8) ans = -1;
	cout << ans;
	return 0;
}
