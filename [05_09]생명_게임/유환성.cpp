#include<iostream>
using namespace std;
/*
격자 판에 생명을 배치하고 관찰하기

바둑판 각 칸은 주위의 영향을 받는다.

1. 생존 : 만약 칸에 생명이 있고, 주위에 a개 이상, b개 이하의 생명이 있으면 다음 단계에 살아남음
2. 고독 : 만약 칸에 생명이 있고, 주위에 a개 미만의 생명이 있다면 다음칸에 죽음
3. 과밀 : 만약 칸에 생명이 있고, 주위에 b개 초과의 생명이 있다면 다음칸에 죽음
4. 탄생 : 만약 칸에 생명이 없고, 주위의 a개 초과, b개 이하의 생명이 있다면 
다음 단계에서 현재 칸에 생명이 생김

N : 세로 길이
M : 가로 갈이
T : 시간
K : 주위의 기준
생명 : *, 빈간 : .


*/
int map[301][105][105];
int N, M, T;
int K, a, b;

void stateDecision(int x, int y, int t) {

	int sx = x - K >= 0 ? x - K : 0;
	int sy = y - K >= 0 ? y - K : 0;
	int ex = x + K < N ? x + K : N;
	int ey = y + K < M ? y + K : M;
	
	int alive = 0;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (i == x && j == y) continue;
			if (map[t][i][j] == 1) alive++;
		}
	}

	//1 : map[x][y] == 1 && ( alive >= a && alive <=b)
	//2 : map[x][y] == 1 && ( alive < a)
	//3 : map[x][y] == 1 && ( alive > b)
	//4 : map[x][y] == 0 && ( alive > a && alive <=b)

	if (map[t][x][y] == 1 && (alive >= a && alive <= b)) {
		map[t+1][x][y] = 1;
	}
	else if (map[t][x][y] == 1 && (alive < a)) {
		map[t+1][x][y] = 0;
	}
	else if (map[t][x][y] == 1 && (alive > b)) {
		map[t+1][x][y] = 0;
	}
	else if (map[t][x][y] == 0 && (alive > a && alive <= b)) {
		map[t+1][x][y] = 1;
	}

	

}

void mapupdate(int t) {

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			stateDecision(r,c, t);
		}
	}

}

void printA(int t) {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[t][i][j] == 1) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}

}

int main() {
	cin >> N >> M >> T;
	cin >> K >> a >> b;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '*') map[0][i][j] = 1;
			else map[0][i][j] = 0;
		}
	}

	for (int time = 0; time < T; time++) {
		mapupdate(time);
		//printA(time);
	}

	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[T][i][j] == 1) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}

	return 0;
}
