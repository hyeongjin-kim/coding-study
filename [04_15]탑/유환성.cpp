#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int val;
	int idx;
};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	stack<Node> stk;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		if (stk.empty()) {	// stk.empty()
			stk.push({ num, i });
			cout << 0 << " ";
			continue;
		}

		while (stk.top().val <= num) {
			stk.pop();

			if (stk.empty()) break;
		}

		if (stk.empty()) {	// stk.empty()
			stk.push({num, i});
			cout << 0 << " ";
		}
		else {				// stk.top().val > num
			cout << stk.top().idx << " ";
			stk.push({ num,i });
		}

	}

	

	return 0;
}
