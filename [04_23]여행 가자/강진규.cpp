#include <iostream>
#include <algorithm>

using namespace std;

int parent[200];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int xRoot = find(x);
	int yRoot = find(y);
	if (xRoot == yRoot) return;
	parent[xRoot] = yRoot;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;++i)
		parent[i] = i;
	for (int i = 0;i < N;++i) 
		for (int j = 0;j < N;++j) {
			int inp;
			cin >> inp;
			if (inp) Union(i, j);
		}
	int prev = -1, cur;
	bool flag = true;
	for (int i = 0;i < M;++i) {
		cin >> cur;
		if (prev != -1 && find(prev - 1) != find(cur - 1)) {
			flag = false;
			break;
		}
		prev = cur;
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
