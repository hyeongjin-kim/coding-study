#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, greater<>> pq;
	int N, inp;
	cin >> N;
	while (N--) {
		cin >> inp;
		if (!inp) {
			if (pq.empty()) {
				cout << "0\n";
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
			continue;
		}
		pq.push(inp);
	}

	return 0;
}
