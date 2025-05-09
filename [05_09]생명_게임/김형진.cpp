#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

char current_board[100][100]; //현재 보드 현황
char next_board[100][100]; //한시간 뒤의 보드 현황

int current_cnt[100][100]; //각 열의 누적합 배열

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, T, K, a, b;

	cin >> N >> M >> T >> K >> a >> b;

	char c;

	for (int i = 0; i < N; i++) {
		//가장 첫번째 꺼는 그냥 받아오고 누적합은 첫번째 칸에 생명이 있는지
		cin >> current_board[i][0];
		current_cnt[i][0] = current_board[i][0] == '*';
		//두번째 칸부터는 그 전까지의 누적합과 현재 칸의 생명 유무로 저장
		for (int j = 1; j < M; j++) {
			cin >> current_board[i][j];
			current_cnt[i][j] = current_cnt[i][j - 1] + (current_board[i][j] == '*');
		}
	}
	
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//상하좌우로 K칸 간 것을 min, max를 통해 바둑판 내로 범위 제한
				int top = max(0, i - K);
				int bottom = min(N - 1, i + K);
				int left = max(0, j - K);
				int right = min(M - 1, j + K);

				//현재 칸은 제외해야 하므로 합에서 빼줌
				int sum = -(current_board[i][j] == '*');
				
				//누적합을 구하는데, b를 넘으면 이미 운명이 결정되므로 조기 중단
				for (int row = top; row <= bottom; row++) {
					sum += current_cnt[row][right] - current_cnt[row][left] + (current_board[row][left] == '*');
					if (sum > b) break;
				}
				//지금 칸에 생명이 있는 경우
				if (current_board[i][j] == '*') {
					if (a <= sum and sum <= b) next_board[i][j] = '*';
					else next_board[i][j] = '.';
				}
				//지금 칸에 생명이 없는 경우
				else {
					if (a < sum and sum <= b) next_board[i][j] = '*';
					else next_board[i][j] = '.';
				}
			}
		}
		for (int i = 0; i < N; i++) {
			//1시간 뒤의 보드 현황 불러오기 
			memcpy(current_board[i], next_board[i], sizeof(current_board[i]));
			
			//다시 누적합 구하기
			current_cnt[i][0] = current_board[i][0] == '*';
			for (int j = 1; j < M; j++) {
				current_cnt[i][j] = current_cnt[i][j - 1] + (current_board[i][j] == '*');
			}
		}
		
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << (current_board[i][j]);
		}
		cout << '\n';
	}

	return 0;
}
