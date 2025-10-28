#include <iostream>
using namespace std;

int arr[105];
int N;

bool isRight(int a, int b) {

	for (int i = 1; i < N; i++) {
		if (arr[i] != arr[i - 1] * a + b) return false;
	}
	return true;

}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (N == 1) {
		cout << "A";
	}
	else if (N == 2) {
		if (arr[0] == arr[1]) cout << arr[0];
		else cout << "A";
	}
	else {
		int top = arr[2] - arr[1];
		int bottom = arr[1] - arr[0];

		if (bottom == 0) {
			if (top == 0) {
				bool flag = true;

				for (int i = 0; i < N; i++) {
					if (arr[i] != arr[0]) { 
						flag = false;
						break;
					}
				}

				if (flag) cout << arr[0];
				else cout << "B";
			}
			else {
				cout << "B";
			}
			return 0;
		}

		int a = top / bottom;
		int b = arr[1] - arr[0] * a;

		if (!isRight(a, b))cout << "B";
		else cout << arr[N - 1] * a + b;
		
	}

}
