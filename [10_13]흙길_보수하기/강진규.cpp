#include <iostream>
#include <algorithm>
#include <set>

struct oong {
	int start;
	int end;

	bool operator<(const oong& right) const {
		return end < right.end;
	}
};

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;
	set<oong> s;

	for (int i = 0; i < N; ++i) {
		int start, end;
		cin >> start >> end;
		s.insert({ start, end });
	}

	int ans = 0;
	int coverEnd = s.begin()->start;

	for (auto it = s.begin(); it != s.end(); it = s.upper_bound({ 0,coverEnd })) {
		coverEnd = max(coverEnd, it->start);
		int length = it->end - coverEnd;
		int cnt = length / L;
		if (length % L)
			++cnt;
		ans += cnt;
		//coverEnd = max(coverEnd, it->start);
		coverEnd += L * cnt;
	}

	cout << ans;
	return 0;
}
