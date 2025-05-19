#include <iostream>
#include <vector>
using namespace std;

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
