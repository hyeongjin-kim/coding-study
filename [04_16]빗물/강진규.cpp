#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int H, W;
	cin >> H >> W;
	int maxH = 0;
	int inp[500];
	for (int i = 0;i < W;++i) {
		cin >> inp[i];
		if (maxH < inp[i])
			maxH = inp[i];
	}
	int left,right;
	int cur = inp[0];
	int acc = 0;
	for (left = 0;left < W;++left) {
		if (inp[left] == maxH)
			break;
		if (inp[left] > cur) {
			cur = inp[left];
			continue;
		}
		if (cur == 0) continue;
		acc += (cur - inp[left]);
	}
	cur = inp[W - 1];
	for (right = W - 1;right >= 0;--right) {
		if (inp[right] == maxH) break;
		if (inp[right] > cur) {
			cur = inp[right];
			continue;
		}
		if (cur == 0)continue;
		acc += (cur - inp[right]);
	}
	for (int i = left;i < right;++i) {
		acc += maxH - inp[i];
	}
	cout << acc;
	return 0;
}
