#include <iostream>
#include <vector>
using namespace std;
/*

	9명으로 두 팀이 공격과 수비 번갈아 하기.
	한 이닝에 3아웃 발생하면 이닝이 종료되고, 공격과 수비 바꾸기
	타순은 이닝이 변경되어도 순서가 유지됨.
	공격팀의 선수가 홈에 도착하면 1점 득점

	감독 아인타는 1번선수를 4번 타자로 정함. 가장 많은 득점을 하는 타순을 찾기

	1 : 안타, 한 루씩 진루
	2 : 2루타, 두 루씩 진루
	3 : 3루타, 3 루씩 진루
	4 : 홈런, 홈까지 진루
	0 : 아웃, 공격팀 아웃 하나 증가

	각 선수가 이닝에서 얻는 결과

	아웃이 3일때까지 지속



4 3 2 1 0 4 3 2 1
1 2 3 4 1 2 3 4 0

1 2 3 0 5 6 7 8 4

8!

*/
int N;

int earning[60][15];
int visited[15];
int order[15];
unsigned int plate;
int score;
int max_score;

void input() {
	cin >> N;

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < 9; i++) {

			cin >> earning[j][i];
		}
	}

	visited[0] = 1;
	order[3] = 0;
}

void init() {

	plate = 0;
	score = 0;
}

void gogo(int step) {
	// 타 1 2 3 홈
	// -  - - - -

	plate = plate | 0b10000;

	for (int i = 0; i < step; i++) {
		
		plate = plate >> 1; 
	

		if (plate & 0x01) score++;

	}

}
void printA() {

	cout << "max :" << max_score << "\n";

	for (int i = 0; i < 9; i++) {
		cout << order[i] << " ";
	}
	cout << "\n";
}
void playgame() {

	int out;
	int idx = 0;// 타자 순서
	for (int i = 0; i < N; i++) {
		plate = 0;
		out = 0;
		while (out < 3) {
			switch (earning[i][order[(idx++) % 9]])
			{
				case 0: out++; break;
				case 1: gogo(1); break;
				case 2: gogo(2); break;
				case 3: gogo(3); break;
				case 4: gogo(4); break;
			}
		}
	}

	if (score > max_score) {

		max_score = score;

		//printA();
	}


}

void solution(int level) {

	//순열로 타자 순서 정하기, 정할 때마다 점수 계산
	if (level == 3) {
		solution(level + 1);
		return;
	}

	if (level >= 9) {
		//printA();
		init();
		playgame();
		return;
	}


	for (int i = 0; i < 9; i++) {

		if (visited[i]) continue;

		visited[i] = 1;
		order[level] = i;
		solution(level + 1);
		visited[i] = 0;
	}




}

int main() {
	
	input();
	solution(0);

	cout << max_score;
	return 0;
}
