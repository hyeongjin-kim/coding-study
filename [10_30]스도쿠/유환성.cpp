#include <iostream>
#include <vector>
using namespace std;

struct pos {
	int x;
	int y;
};

int board[10][10];
vector<pos> emp;
void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) emp.push_back({ i,j });
		}
	}
}
bool checkRow(int num, int idx) {
	//같은 행에서 같은 값 체크, 있으면 true
	for (int col = 0; col < 9; col++) {
		if (board[emp[idx].x][col] == num) return true;
	}
	return false;
}
bool checkCol(int num, int idx) {
	//같은 열에서 같은 값 체크
	for (int row = 0; row < 9; row++) {
		if (board[row][emp[idx].y] == num) return true;
	}
	return false;
}
bool checkCenter(int num, int idx) {
	//같은 행에서 같은 값 체크
	int centerX;
	int centerY;

	centerX = (emp[idx].x / 3)*3 + 1;
	centerY = (emp[idx].y / 3)*3 + 1;

	for (int r = centerX - 1; r <= centerX + 1; r++) {
		for (int c = centerY - 1; c <= centerY + 1; c++) {
			if (board[r][c] == num) return true;
		}
	}
	return false;
}
void output() {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
bool solution(int idx) {

	if (idx == emp.size()) {
		output();
		return true;
	}

	for (int i = 1; i <= 9; i++) {
		if (checkRow(i, idx)) continue;
		if (checkCol(i, idx)) continue;
		if (checkCenter(i, idx)) continue;

		board[emp[idx].x][emp[idx].y] = i;
		if (solution(idx + 1)) return true;;
		board[emp[idx].x][emp[idx].y] = 0;
	}

	return false;
}


int main() {
	input();
	solution(0);
	return 0;
}
