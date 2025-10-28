#include <iostream>
using namespace std;

int N;
int board[205];
int length[205];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
}
void solution() {
	//본인보다 작은 것 중 제일 큰 것의 카운트 +1

	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (board[j] >= board[i])continue;
			if (max < length[j])max = length[j];
		}
		length[i] = max + 1;
	}
	int max=0;
	for (int i = 0; i < N; i++) {
		if (max < length[i])max = length[i];
	}
	cout << N - max;

}

int main() {
	input();
	solution();

	return 0;
}
