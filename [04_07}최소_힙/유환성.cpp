#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty()) {
				cout << 0<<"\n";
				continue;
			}
			cout << pq.top()<<"\n";
			pq.pop();
		}
		else {
			pq.push(num);
		}
	}
}
