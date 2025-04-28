#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[10000];
bool vis[10000];
int child[10000];

int rec(int cur) {
	int acc = 1;
	for (int i = 0;i < v[cur].size();++i) {
		if (vis[v[cur][i]]) continue;
		vis[v[cur][i]] = true;
		acc += rec(v[cur][i]);
	}
	return acc;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int curmax = 0;
	vector<int> maxv;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[b - 1].push_back(a - 1);
	}
	for (int i = 0;i < N;++i) {
		memset(vis, false, sizeof(vis));
		vis[i] = true;
		child[i] = rec(i);
		if (curmax < child[i]) {
			maxv.resize(0);
			maxv.push_back(i);
			curmax = child[i];
		}
		else if (curmax == child[i])
			maxv.push_back(i);
	}
	for (int i = 0;i < maxv.size();++i)
		cout << maxv[i] + 1 << " ";
	return 0;
}
