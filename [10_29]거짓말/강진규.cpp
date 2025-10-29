#include <iostream>
#include <algorithm>

using namespace std;

long long truth;
long long ex;
long long participants[50];
int N, M;
int curMax;

void dfs(int depth, int party) {

	if (depth == M) {
		curMax = max(curMax, party);
		return;
	}
	if (curMax > party + (M - depth))
		return;

	long long cur = participants[depth];
	long long knowTruth = cur & truth;
	long long knowEx = cur & ex;

	if (knowTruth & knowEx)
		return;

	if (!knowEx) {
		long long tmp = truth;
		truth |= cur;
		dfs(depth + 1, party);
		truth = tmp;
	}
	if (!knowTruth) {
		long long tmp = ex;
		ex |= cur;
		dfs(depth + 1, party + 1);
		ex = tmp;
	}
	return;
}

int main(void) {
	
	cin >> N >> M;

	int initTruthN;
	cin >> initTruthN;
	while (initTruthN--) {
		int inp;
		cin >> inp;
		long long mask = 1;
		mask <<= inp;
		truth |= mask;
	}

	long long tmp = 1;
	for (int i = 0; i < M; ++i) {
		int truthN;
		cin >> truthN;
		long long mask = 0;
		while (truthN--) {
			int inp;
			cin >> inp;
			mask |= (tmp << inp);
		}
		participants[i] = mask;
	}
	dfs(0, 0);
	cout << curMax;
	return 0;
}
