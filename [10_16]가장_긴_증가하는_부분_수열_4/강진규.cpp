#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int seq[1000];
int save[1000]; // beforeIdx
int lis[1000];
int lisIdx[1000];

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> seq[i];

	int lisLen = 1;
	save[0] = -1;
	lis[0] = seq[0];
	lisIdx[0] = 0;
	int maxLength = -1;
	int maxIndex = 0;

	for (int i = 1; i < N; ++i) {
		int cur = seq[i];
		auto upper = lower_bound(lis, lis + lisLen, cur);
		int upperIdx = upper - lis;

		if (upperIdx == lisLen) { // 제일 큼
			save[i] = lisIdx[lisLen - 1];
			lis[lisLen] = cur;
			lisIdx[lisLen++] = i;
		}
		else {
			int target = max(0, upperIdx);
			save[i] = (target == 0 ? -1 : lisIdx[target - 1]);
			lis[target] = cur;
			lisIdx[target] = i;
		}
	}

	string ans = "";

	cout << lisLen << "\n";
	for (int i = lisIdx[lisLen - 1]; i >= 0;) {
		ans = to_string(seq[i]) + " " + ans;
		i = save[i];
	}
	cout << ans;
	return 0;
}
