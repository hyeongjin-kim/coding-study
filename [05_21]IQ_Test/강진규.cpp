#include <iostream>

using namespace std;
int arr[50];

int main(void) {
	int N;
	cin >> N;
	for (int i = 0;i < N;++i)
		cin >> arr[i];
	if (N == 1) {
		cout << 'A';
		return 0;
	}
	else if (N == 2) {
		if (arr[0] == arr[1])
			cout << arr[0];
		else
			cout << 'A';
		return 0;
	}
	int a, b;
	int boonja = arr[2] - arr[1];
	int boonmo = arr[1] - arr[0];
	if (boonmo == 0) {
		a = 0;
		b = arr[1];
	}
	else if (boonja % boonmo == 0) {
		a = boonja / boonmo;
		b = arr[1] - arr[0] * a;
	}
	else {
		cout << 'B';
		return 0;
	}
	int flag = true;
	for (int i = 2;i < N;++i) {
		if (arr[i] != arr[i - 1] * a + b) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << arr[N - 1] * a + b;
	else
		cout << 'B';

	return 0;
}
