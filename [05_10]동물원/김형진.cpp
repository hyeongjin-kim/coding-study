#include <iostream>

using namespace std;

//i번째 칸에 사자를 두지 않는 경우
int no_lion[100000] = { 1 };
//i번째 칸에 사자를 왼쪽 칸에 두는 경우
int left_lion[100000] = { 1 };
//i번째 칸에 사자를 오른쪽 칸에 두는 경우
int right_lion[100000] = { 1 };

int main() {

	int N;
	cin >> N;

	for (int i = 1; i < N; i++) {
		no_lion[i] = (no_lion[i - 1] + left_lion[i - 1] + right_lion[i - 1])%9901;
		left_lion[i] = (no_lion[i - 1] + right_lion[i - 1])%9901;
		right_lion[i] = (no_lion[i - 1] + left_lion[i - 1])%9901;
	}

	cout << (no_lion[N - 1] + left_lion[N - 1] + right_lion[N - 1])%9901;

	return 0;
}