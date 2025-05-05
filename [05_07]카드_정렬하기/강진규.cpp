#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	priority_queue<long long, vector<long long>, greater<>> pq;
	for (int i = 0;i < N;++i) {
		int inp;
		cin >> inp;
		pq.push(inp);
	}
	long long cnt = 0;
	while (pq.size() > 1) {
		long long first = pq.top(); pq.pop();
		long long second = pq.top(); pq.pop();
		long long newDeck = first + second;
		cnt += newDeck;
		pq.push(newDeck);
	}
	cout << cnt;
	return 0;
}
