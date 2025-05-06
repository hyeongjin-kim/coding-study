#include <iostream>
#include <queue>
using namespace std;
int N;
long long int ans;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (pq.size() != 1) {
		long long int num1 = pq.top(); pq.pop();
		long long int num2 = pq.top(); pq.pop();

		ans += num1 + num2;
		pq.push(num1 + num2);
	}

	cout << ans;
	return 0;
}
