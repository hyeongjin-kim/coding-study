#include <iostream>

using namespace std;

int arr[100000][3];

int main(void) {
	int N;
	cin >> N;
	
	arr[0][0] = arr[0][1] = arr[0][2] = 1;

	for (int i = 1;i < N;++i) {
		arr[i][0] = (arr[i - 1][1] + arr[i - 1][2]) % 9901;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
		arr[i][2] = (arr[i][0] + arr[i - 1][0]) % 9901;
	}
	cout << (arr[N - 1][0] + arr[N - 1][1] + arr[N - 1][2]) % 9901;
	return 0;
}
