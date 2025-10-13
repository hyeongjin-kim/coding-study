#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	long long* arr = new long long[N];
	for (int i = 0;i < N;i++)
		cin >> arr[i];
	long long* left = arr, * right = arr + (N - 1);
	long long currmin = llabs(*right) * 2 + llabs(*left) * 2;
	long long* minleft = NULL, * minright = NULL;
	while (left < right) {
		if (llabs(*left + *right) < currmin) {
			minleft = left;
			minright = right;
			currmin = llabs(*left + *right);
		}
		if (*left + *right > 0)
			right--;
		else if (*left + *right == 0)
			break;
		else
			left++;
	}
	cout << *minleft << " " << *minright;

	return 0;
}
