#include <iostream>

using namespace std;

int height[100001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, a, b;
	cin >> N >> a >> b;

	int maxH = a > b ? a : b;

	if (N < a + b - 1) {
		cout << -1;
		return 0;
	}

	for (int i = 1; i < a; ++i) {
		height[i] = height[i - 1] + 1;
	}
	for (int i = a + b - 3; i >= a - 1; --i) {
		height[i] = height[i + 1] + 1;
	}
	height[a - 1] = maxH - 1;

	if (!height[0])
		for (int i = 0; i < N - (a + b - 1); ++i)
			cout << 1 << " ";

	for (int i = 0; i < a; ++i)
		cout << height[i] + 1 << " ";

	if (height[0])
		for (int i = 0; i < N - (a + b - 1); ++i)
			cout << 1 << " ";

	for (int i = a; i < a + b - 1; ++i)
		cout << height[i] + 1 << " ";

	
	return 0;
}
