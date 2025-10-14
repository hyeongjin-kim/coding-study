#include <iostream>
#include <algorithm>
using namespace std;

int N, M, door;
int sequence[20];
int opened[2];

int ans = 400;

void dp(int index, int sum) {
	if (index == M) {
		ans = min(ans, sum);
		return;
	}
	
	if (sequence[index] == opened[0] or sequence[index] == opened[1]) {
		dp(index + 1, sum);
	}
	else if (sequence[index] < opened[0]) {
		sum += opened[0] - sequence[index];
		int closed = opened[0];
		opened[0] = sequence[index];
		dp(index + 1, sum);
		opened[0] = closed;
		sum -= opened[0] - sequence[index];
	}
	else if (sequence[index] > opened[1]) {
		sum += sequence[index] - opened[1];
		int closed = opened[1];
		opened[1] = sequence[index];
		dp(index + 1, sum);
		opened[1] = closed;
		sum += sequence[index] - opened[1];
	}
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
