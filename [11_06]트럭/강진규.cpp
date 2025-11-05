#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, w, L;
	cin >> n >> w >> L;

	queue<int> trucks;
	for (int i = 0; i < n; ++i) {
		int inp;
		cin >> inp;
		trucks.push(inp);
	}

	int curWeight = 0;
	int curTime = 0;

	queue<int> bridge;
	for (int i = 0; i < w; ++i)
		bridge.push(0);

	while (!trucks.empty()) {
		++curTime;
		curWeight -= bridge.front();
		bridge.pop();
		int curTruck = trucks.front();
		if (curWeight + curTruck > L) {
			bridge.push(0);
			continue;
		}
		trucks.pop();
		bridge.push(curTruck);
		curWeight += curTruck;
	}

	cout << curTime + w;
	return 0;
}
