#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int map[10][10];
int remain[5];
int spaceCnt = 0;
int curmin;

bool canPut(int x, int y, int size) {
	bool flag = true;
	if (x + size > 10 || y + size > 10)
		return false;
	for (int i = x;flag && i < x + size;++i) {
		for (int j = y;flag && j < y + size;++j) {
			if (!map[i][j])
				flag = false;
		}
	}
	return flag;
}

void color(int x, int y, int size, int color) {
	for (int i = x;i < x + size;++i)
		for (int j = y;j < y + size;++j)
			map[i][j] = color;
}

void rec(int colored, int acc, int row, int col) {
	if (colored == spaceCnt) {
		curmin = min(curmin, acc);
		return;
	}
	if (acc + ((spaceCnt - colored) / min(25, (10 - row) * (10 - row))) >= curmin) return;
	for (int i = row;i < 10;++i) {
		if (acc + ((spaceCnt - colored) / min(25, (10 - i) * (10 - i))) >= curmin) return;
		for (int j = 0;j < 10;++j) {
			if (acc + ((spaceCnt - colored) / min(25, (10 - i) * (10 - i))) >= curmin) return;
			if (!map[i][j]) continue;
			for (int k = 4;k >= 0;--k) {
				// 색종이 개수 확인할것
				if (!remain[k]) continue;
				if (canPut(i, j, k + 1)) {
					--remain[k];
					color(i, j, k + 1, 0);
					rec(colored + (k + 1) * (k + 1), acc + 1, i, j);
					color(i, j, k + 1, 1);
					++remain[k];
				}
			}
			return;
		}
	}

}

int main(void) {	
	for(int i=0;i<10;++i)
		for (int j = 0;j < 10;++j) {
			cin >> map[i][j];
			if (map[i][j])
				++spaceCnt;
		}
	if (!spaceCnt) {
		cout << 0;
		return 0;
	}
	fill(remain, remain + 5, 5);
	curmin = 1000;
	rec(0, 0, 0, 0);
	if (curmin == 1000)
		cout << -1;
	else
		cout << curmin;
	return 0;
}
