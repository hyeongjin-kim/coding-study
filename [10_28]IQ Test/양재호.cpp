#include <iostream>

using namespace std;

int n;
int arr[52];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	if (n == 1) {
		cout << "A";
		return 0;
	}
	if (n == 2) {
		if (arr[0] == arr[1]) {
			cout << arr[0];
			return 0;
		}
		else {
			cout << 'A';
			return 0;
		}
	}

	bool same = true;

	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[0]) {
			same = false;
			break;
		}
	}
	if (same) {
		cout << arr[0];
		return 0;
	}

	int x = arr[1] - arr[0];
	int y = arr[2] - arr[1];

	if (x == 0) {
		cout << "B";
		return 0;
	}

	if (y % x != 0) {
		cout << "B";
		return 0;
	}

	int a = y / x;
	int b = arr[1] - a * arr[0];

	for (int i = 0; i < n - 1; i++) {
		int next = a * arr[i] + b;
		if (next != arr[i + 1]) {
			cout << "B";
			return 0;
		}
	}

	int next = a * arr[n - 1] + b;
	cout << next;

	return 0;
}
