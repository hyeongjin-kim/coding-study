#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool prime[4000001];
int main(void) {
	int N;
	cin >> N;
	fill(prime, prime + 4000001, true);
	for (int i = 2;i < 4000001;++i) {
		if (prime[i])
			for (int j = i * 2;j < 4000001;j += i)
				prime[j] = false;
	}
	int left = 2, right = 1;
	int curAcc = 0;
	while (curAcc < N) {
		++right;
		if (prime[right])
			curAcc += right;
	}
	int cnt = 0;
	while (left<=right) {
		if (curAcc == N) {
			++cnt;
			while (right < 4000001 && !prime[++right]);
			if (right >= 4000001)
				break;
			curAcc += right;
			curAcc -= left;
			while (!prime[++left]);
		}
		else if (curAcc < N) {
			while (right < 4000001 && !prime[++right]);
			if (right >= 4000001)
				break;
			curAcc += right;
		}
		else if (curAcc > N) {
			curAcc -= left;
			while (!prime[++left]);
		}
		
	}
	cout << cnt;
	return 0;

}
