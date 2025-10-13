#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> liquid;

struct item {
	int dif;
	int l1;
	int l2;
};

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		liquid.push_back(val);
	}
	sort(liquid.begin(), liquid.end());
}
void solution() {
	
	item ans;
	ans.dif = 21e8;

	int sp = 0;
	int ep = N - 1;

	while (sp < ep) {
		if (ans.dif == 0) break;

		int dif = liquid[sp] + liquid[ep];

		if (ans.dif > abs(dif)) {
			ans.dif = abs(dif);
			ans.l1 = liquid[sp];
			ans.l2 = liquid[ep];
		}

		if (dif < 0) sp++;
		else if (dif > 0) ep--;
	}

	cout << ans.l1 << " " << ans.l2;
}

int main() {

	input();
	solution();

	return 0;
}
