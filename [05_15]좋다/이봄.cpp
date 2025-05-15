#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 2005

int n;
int num[MAX_N];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> num[i];

	sort(num + 1, num + n + 1);

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		int tar = num[i];
		int l = 1;
		int r = n;
		while (l < r) {
			int tmp = num[l] + num[r];
			if (tmp == tar) {
				if (i != l && i != r) {
					cnt++;
					break;
				} 
				else if (i == l)
					l++;
				else if (i == r)
					r--;
			} else {
				if (tmp > tar)
					r--;
				else
					l++;
			}

		}
	}

	cout << cnt;

	return 0;
}
