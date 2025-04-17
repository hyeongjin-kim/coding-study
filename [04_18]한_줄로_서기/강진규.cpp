#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int arr[10];
	bool occ[10];
	memset(occ, false, 10);
	for (int i = 0;i < N;++i) {
		int inp;
		cin >> inp;
		for (int j = 0;j < 10;++j) {
			if (occ[j]) continue;
			if (inp == 0) {
				arr[j] = i + 1;
				occ[j] = true;
				break;
			}
			--inp;
		}
	}
	for (int i = 0;i < N;++i)
		cout << arr[i] << " ";
	return 0;
}
