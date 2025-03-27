#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq; // step, curLoc
	bool vis[100001] = { false, };
	pq.push({ 0,N });
	vis[N] = true;
	while (!pq.empty()) {
		auto [step, curLoc] = pq.top(); pq.pop();
		if (curLoc == K) {
			cout << step;
			return 0;
		}
		if (curLoc * 2 <= 100000 && !vis[curLoc * 2]) {
			vis[curLoc * 2] = true;
			pq.push({ step, curLoc * 2 });
		}
		if (curLoc - 1 >= 0 && !vis[curLoc-1]) {
			vis[curLoc - 1] = true;
			pq.push({ step + 1, curLoc - 1 });
		}
		if (curLoc + 1 <= 100000 && !vis[curLoc+1]) {
			vis[curLoc + 1] = true;
			pq.push({ step + 1,curLoc + 1 });
		}

	}
	return 0;

}
