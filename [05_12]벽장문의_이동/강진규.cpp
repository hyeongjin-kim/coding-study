#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>

using namespace std;

struct STEP {
	int left, right, idx, step;

	bool operator<(const STEP& r) const {
		if (left != r.left) return left < r.left;
		if (right != r.right) return right < r.right;
		return idx < r.idx;
	}
};

int main(void) {
	int n, m;
	int use[20];
	cin >> n;
	int left, right;
	cin >> left >> right;
	if (left > right)
		swap(left, right);
	cin >> m;
	for (int i = 0;i < m;++i)
		cin >> use[i];

	//queue<STEP> q;
	deque<STEP> q;
	set<STEP> vis;
	q.push_back({ left, right, 0, 0 });
	vis.insert({ left, right, 0, 0 });
	while (!q.empty()) {
		STEP cur = q.front(); q.pop_front();
		int curLeft = cur.left, curRight = cur.right;
		int curIdx = cur.idx, curStep = cur.step;
		if (curIdx >= m) {
			cout << curStep;
			return 0;
		}
		if (use[curIdx] == curLeft || use[curIdx] == curRight) {
			++curIdx;
			if (vis.find({ curLeft, curRight, curIdx, 0 }) != vis.end()) continue;
			vis.insert({ curLeft, curRight, curIdx, 0 });
			q.push_front({ curLeft,curRight,curIdx,curStep });
			continue;
		}
		if (use[curIdx] < curLeft) {
			int nextLeft = curLeft - 1;
			if (nextLeft < 1) continue;
			if (vis.find({ nextLeft, curRight, curIdx, 0 }) != vis.end()) continue;
			vis.insert({ nextLeft, curRight, curIdx, 0 });
			q.push_back({ nextLeft, curRight, curIdx, curStep + 1 });
		}
		else if (use[curIdx] > curLeft && use[curIdx] < curRight) {
			int nextLeft = curLeft + 1;
			int nextRight = curRight - 1;
			if (vis.find({ nextLeft, curRight, curIdx, 0 }) == vis.end()) {
				vis.insert({ nextLeft, curRight, curIdx, 0 });
				q.push_back({ nextLeft, curRight, curIdx, curStep + 1 });
			}

			if (vis.find({ curLeft, nextRight, curIdx, 0 }) == vis.end()) {
				vis.insert({ curLeft, nextRight, curIdx, 0 });
				q.push_back({ curLeft, nextRight, curIdx, curStep + 1 });
			}
		}
		else {
			int nextRight = curRight + 1;
			if (nextRight > n) continue;
			if (vis.find({ curLeft, nextRight, curIdx, 0 }) != vis.end()) continue;
			vis.insert({ curLeft, nextRight, curIdx, 0 });
			q.push_back({ curLeft, nextRight, curIdx, curStep + 1 });
		}
	}
	return 0;
}
