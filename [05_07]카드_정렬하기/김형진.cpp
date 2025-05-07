#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<> > pq;

	int deck;
	for (int i = 0; i < N; i++) {
		cin >> deck;
		pq.push(deck);
	}

	int ans = 0;
	
	//카드가 A개 있는 묶음과 B개 있는 묶음을 합치면 A + B개가 됨
	// 이를 위해 A + B번의 비교를 하게 됨
	// 이를 다시 카드가 C개 있는 묶음과 합치면 A + B + C번의 비교가 필요함
	// 즉, 카드를 합칠 수록 비교에 많이 사용하게 됨
	// 따라서, 카드 묶음이 1개가 될 때 까지 제일 작은 두 카드 묶음을 합칩
	while (pq.size() > 1) {
		int A = pq.top();
		pq.pop();
		int B = pq.top();
		pq.pop();

		ans += A + B;
		pq.push(A + B);
	}

	cout << ans;

	return 0;
}
