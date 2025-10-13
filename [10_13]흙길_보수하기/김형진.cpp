#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, L;

struct Hole {
	int s, e;

	bool operator<(const Hole& operand) const {
		return s < operand.s;
	}
};

Hole arr[10001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	int cnt = 0;
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		arr[cnt++] = { s, e };
	}

	sort(arr, arr + N);

	int last = 0;

	for (int i = 0; i < N; i++) {
		int s = arr[i].s, e = arr[i].e;
		if (last > e) {
			continue;
		}
		if (last > s) s = last;
		int num = (e - s) / L + (((e - s ) % L) != 0);
		ans += num;
		last = max(e,  s + L * num);
	}
	cout << ans;
	return 0;

}
