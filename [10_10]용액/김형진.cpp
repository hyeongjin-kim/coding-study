#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	int arr[100001];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result[2];

	result[0] = arr[0];
	result[1] = arr[N - 1];

	int f = 0, e = N - 1;

	while (f < e) {
		int value = arr[f] + arr[e];
		
		if (abs(value) < abs(result[0] + result[1])) {
			result[0] = arr[f];
			result[1] = arr[e];
		}

		if (value > 0) {
			e--;
		}
		else if (value < 0) {
			f++;
		}
		else {
			break;
		}


	}

	cout << result[0]<< ' ' << result[1];

	return 0;

}
