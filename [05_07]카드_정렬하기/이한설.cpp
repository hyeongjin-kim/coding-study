#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	int score = 0;
	for (int idx = 0; idx < N; idx++) {
		int nums; cin >> nums;
		pq.push(nums);
	}

	while (pq.size() > 1) {
		int x1 = pq.top();
		pq.pop();
		int x2 = pq.top();
		pq.pop();
		int sum_x = x1 + x2;
		score += sum_x;
		pq.push(sum_x);
	}

	cout << score;
	return 0;
}
