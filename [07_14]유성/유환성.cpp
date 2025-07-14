#include <iostream>
using namespace std;
#define STAR 2
#define GROUND 1
#define AIR 0

// 맨 아래는 무조건 땅, 

int R, S;
int map[3005][3005];
int min_dis= 21e8;

bool inRange(int x, int y) {
	return x>=0 && y>=0 && x<R&&y<S;
}

void input() {
	cin >> R >> S;
	char c;

	for (int i = 0; i < R;i++) {
		for (int j = 0; j < S; j++) {
			cin >> c;
			if (c == '.') map[i][j] = AIR;
			else if (c == '#') map[i][j] = GROUND;
			else if (c == 'X') map[i][j] = STAR;
		}
	}
}
void falling() {
	// 별 찾기 -> 땅 찾기
	for (int i = 0; i < S; i++) { //세로
		//별 찾기, 별이 없을 수도!, 여러 개일 수도!
		//땅에 닿기 전까지 마지막 별
		int star_position = -1;		//일단 별은 없는 걸로
		if (map[0][i] == STAR) star_position = 0;

		int last_position = 0;
		while (map[last_position][i] != GROUND && inRange(last_position,i)) {	
			if (map[last_position][i] == STAR) star_position = last_position;	
			last_position++;
		}
		if (!inRange(star_position, i))continue;


		

		if (min_dis > last_position - star_position -1) min_dis = last_position - star_position -1;

	}

	for (int i = R - 1; i >= 0; i--) {
		for (int j = S - 1; j >= 0; j--) {

			if (map[i][j] == STAR) {
				map[i + min_dis][j] = STAR;
				map[i][j] = AIR;
			}

		}
	}

}
void output() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {

			if (map[i][j] == STAR) cout << 'X';
			else if (map[i][j] == AIR) cout << '.';
			else if (map[i][j] == GROUND) cout << '#';
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  
	input();
	falling();
	output();
}
