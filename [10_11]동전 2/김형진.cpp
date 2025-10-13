#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int cnt, value;
};

struct cmp {
	bool operator()(const Node& a, const Node& b) const {
		if (a.cnt != b.cnt) return a.cnt > b.cnt;
		return a.value < b.value;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;

	cin >> N >> K;

	set<int, greater<>> s;

	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		s.insert(num);
	}

	priority_queue<Node, vector<Node>, cmp> q;

	int visit[10001];

	fill(visit, visit + 10001, 1e9);

	q.push({ 0,0 });



	while (!q.empty()) {
		Node cur = q.top();
		q.pop();
		int value = cur.value, cnt = cur.cnt;

		if (visit[value] <= cnt) continue;
		visit[value] = cnt;
		if (value == K) break;

		for (int coin : s) {
			int next_value = coin + value;
			if (next_value > K) continue;
			if (visit[next_value] <= cnt + 1) continue;
			q.push({ cnt + 1, next_value });
		}

	}

	if (visit[K] == 1e9) {
		cout << -1;
	}
	else	cout << visit[K];
	return 0;

}
