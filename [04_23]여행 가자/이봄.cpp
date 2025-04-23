#include <iostream>

using namespace std;

#define MAX_N 205

int n,m;

int uf[MAX_N];

int Find(int x) {
	if (uf[x] == x)
		return x;
	return Find(uf[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	uf[y] = x;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		uf[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) {
				Union(i, j);
			}
		}
	}

	int s = 0;
	cin >> s;
	bool flag = true;
	for (int i = 1; i < m; i++) {
		int e;
		cin >> e;
		
		if (Find(s) != Find(e))
			flag = false;
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}
