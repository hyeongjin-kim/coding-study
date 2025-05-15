#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int inp[2000];
	int N;
	cin >> N;
	for (int i = 0;i < N;++i)
		cin >> inp[i];
	sort(inp, inp + N);
	int GOOOOOOD = 0;

	for (int i = 0;i < N;++i) {
		int left = 0;
		int right = N - 1;
		while (left < right) {
			if (i == left) {
				++left;
				continue;
			}
			else if (i == right) {
				--right;
				continue;
			}
			int cur = inp[left] + inp[right];
			if (cur == inp[i]) {
				++GOOOOOOD;
				break;
			}
			else if (cur > inp[i])
				--right;
			else
				++left;
		}
	}
	cout << GOOOOOOD;
	return 0;
}
