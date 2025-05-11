#include <iostream>
#include <algorithm>
using namespace std;

int N, M, door;
int sequence[20];
int opened[2];

int ans = 400;

void dp(int index, int sum) {
	//모든 벽장을 다 사용한 경우 정답 갱신
	if (index == M) {
		ans = min(ans, sum);
		return;
	}
	
	//사용하려는 벽장이 열려있는 경우 그대로 진행
	if (sequence[index] == opened[0] or sequence[index] == opened[1]) {
		dp(index + 1, sum);
	}
	//사용하려는 벽장이 열려있는 모든 벽장보다 앞에 있는 경우,
	//열려있는 벽장 중, 앞쪽 것을 닫으며 원하는 벽장을 열기
	else if (sequence[index] < opened[0]) {
		sum += opened[0] - sequence[index];
		int closed = opened[0];
		opened[0] = sequence[index];
		dp(index + 1, sum);
		opened[0] = closed;
		sum -= opened[0] - sequence[index];
	}
	//사용하려는 벽장이 열려있는 모든 벽장보다 뒤에 있는 경우,
	//열려있는 벽장 중, 뒷쪽 것을 닫으며 원하는 벽장을 열기
	else if (sequence[index] > opened[1]) {
		sum += sequence[index] - opened[1];
		int closed = opened[1];
		opened[1] = sequence[index];
		dp(index + 1, sum);
		opened[1] = closed;
		sum += sequence[index] - opened[1];
	}
	//사용하려는 벽장이 열려있는 두 벽장 사이에 있는 경우,
	//두가지 모두 시도함
	else {
		sum += sequence[index] - opened[0];
		int closed = opened[0];
		opened[0] = sequence[index];
		dp(index + 1, sum);
		opened[0] = closed;
		sum -= sequence[index] - opened[0];

		sum += opened[1] - sequence[index];
		closed = opened[1];
		opened[1] = sequence[index];
		dp(index + 1, sum);
		opened[1] = closed;
		sum -= opened[1] - sequence[index];
	}
}

int main() {
	cin >> N;

	cin >> opened[0] >> opened[1];

	if (opened[0] > opened[1]) swap(opened[0], opened[1]);

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> sequence[i];
	}
	dp(0, 0);

	cout << ans;
	return 0;
}