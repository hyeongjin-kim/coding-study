#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int rec(int N, int r, int c) {
	if (!N)
		return 0;
	int half = pow(2, N - 1);
	if (r < half) {
		if (c < half)
			return rec(N - 1, r, c);
		else
			return half*half + rec(N - 1, r, c - half);
	}
	else {
		if (c < half)
			return half * half * 2 + rec(N - 1, r - half, c);
		else
			return half * half * 3 + rec(N - 1, r - half, c - half);
	}
}

int main(void) {
	int N, r, c;
	cin >> N >> r >> c;
	cout << rec(N, r, c);
	// 4등분해서 쪼개들어가기
	return 0;
}
