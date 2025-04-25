#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	priority_queue<int, vector<int>, greater<>> res;
	for (int i = 0;i < N;++i) {
		priority_queue<int> pq;
		int p, l;
		cin >> p >> l;
		for (int i = 0;i < p;++i) {
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}
		for (int i = 0;i < l - 1 && !pq.empty();++i) pq.pop();
		if (pq.empty())
			res.push(1);
		else
			res.push(pq.top());
	}
	int cur = 0, cnt = 0;
	while (!res.empty()) {
		if (cur + res.top() > M)
			break;
		cur += res.top();
		res.pop();
		++cnt;
	}
	cout << cnt;
	return 0;
}
