#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int curmax = 0;
	map<int, int> m;
	int* start , * end;
	start = end = arr;
	m[*start] = 1;
	while (start < arr + N) {
		if (end == arr + N - 1) {
			--m[*start];
			++start;
			if (end - start < curmax)
				break;
			continue;
		}
		++end;
		if (m.find(*end) == m.end()) {
			m[*end] = 1;
		}
		else {
			++m[*end];
			if (m[*end] > K)
				while (m[*end] > K) {
					--m[*start];
					++start;
				}
		}
		curmax = max(curmax, (int)(end - start));

	}
	cout << curmax + 1;
	return 0;

}
