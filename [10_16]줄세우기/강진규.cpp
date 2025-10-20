#include <iostream>
#include <algorithm>

using namespace std;

int mixed[200];
int lis[200];

int main(void) {
	int N;
	cin >> N;

	int lisIdx = 0;

	for (int i = 0; i < N; ++i) {
		cin >> mixed[i];
	}

	lis[0] = mixed[0];

	for (int i = 1; i < N; ++i) {
		int cur = mixed[i];

		if (lis[lisIdx] < cur) {
			lis[++lisIdx] = cur;
		}
		else {
			int* idx = lower_bound(lis, lis + lisIdx + 1, cur);
			*idx = cur;
		}
	}

	cout << N - lisIdx - 1;
	return 0;
}
