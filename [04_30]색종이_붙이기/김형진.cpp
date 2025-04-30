#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[10][10];
int paper[6] = {0, 5,5,5,5,5};

int ans = 26;
int cell_to_cover = 0;
int used_paper = 0;
//r, c를 왼쪽 위 모서리로 해서 size * size 색종이를 붙일 수 있는가?
bool can_put_paper(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (arr[i][j] == false) return false;
		}
	}
	return true;
}

void backtracking(int r, int c) {
	if (cell_to_cover == 0){
    //더이상 붙일 종이가 없다면 최소값 정하고 리턴
		ans = min(ans, used_paper); 
		return;
	}
  if(ans < used_paper) return; //이미 최소값을 넘었다면 리턴
	for (int row = r; row < 10; row++) {
		for (int col = 0; col < 10; col++) {
			if (arr[row][col] == true) { //1을 찾았으면 여기서부터 idx * idx 색종이를 붙여봄
				for (int idx = 5; idx > 0; idx--) { 
          //남은 공간이 r, c를 왼쪽 위 모서리로 해서 idx * idx 색종이를 붙일 수 있고
          //그 색종이가 남아있다면 시도
					if (row <= 10 - idx and col <= 10 - idx and paper[idx] > 0) { 
						//해당 영역에 붙일 수 있다면
            if (can_put_paper(row, col, idx)) {
							//종이 사용
              paper[idx]--;
              //종이 붙임표시 및 커버할 칸 수 줄이기
							for (int i = row; i < row + idx; i++) {
								for (int j = col; j < col + idx; j++) {
									arr[i][j] = 0;
									cell_to_cover--;
								}
							}
              //사용한 종이 수 증가
							used_paper++;
              //이 상태를 가지고 다시 탐색
							backtracking(row , col);
              //복구
							for (int i = row; i < row + idx; i++) {
								for (int j = col; j < col + idx; j++) {
									arr[i][j] = 1;
									cell_to_cover++;
								}
							}
							paper[idx]++;
							used_paper--;
						}
					}
				}
				return;
			}
			
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
			cell_to_cover += arr[i][j];
		}
	}

	backtracking(0, 0);

	cout << (ans == 26? -1 : ans);
	
	return 0;
}
