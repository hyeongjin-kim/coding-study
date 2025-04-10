#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main(void) {
	int arr[1000];
	memset(arr, 0, 1000 * sizeof(int));
	int N;
	int maxH = 0;
	cin >> N;
	for (int i = 0;i < N;i++) {
		int L, H;
		cin >> L >> H;
		arr[L - 1] = H;
		maxH = max(maxH, H);
	}
	int res = 0;
	int curH = 0;
	int left, right;
	for(left = 0;left < 1000;left++) {
		curH = max(curH, arr[left]);
		if (curH == maxH)
			break;
		res += curH;
	}
	curH = 0;
	for (right = 999;right >= 0;right--) {
		curH = max(curH, arr[right]);
		if (curH == maxH)
			break;
		res += curH;
	}
	res += (right - left + 1) * maxH;
	cout << res;
	return 0;
}
