#include <iostream>
#include <vector>
#include <set>
#include <memory.h>

using namespace std;

int n, m;
int num;
set<int> True;
vector<int> party[55];
int parent[55];

int find(int a) {
	if (a == parent[a]) return a;
	parent[a] = find(parent[a]);
	return find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	cin >> num;
	for (int i = 0; i < num; i++) {
		int truth;
		cin >> truth;
		True.insert(truth);
	}
	if (True.size() == 0) {
		cout << m;
		return 0;
	}

	for (int i = 0; i < m; i++) {
		int e;
		cin >> e;
		for (int j = 0; j < e; j++) {
			int idx;
			cin >> idx;
			party[i].push_back(idx);
		}
	}

	for (int i = 0; i < m; i++) {
		if (party[i].size() <= 1) continue;
		int base = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			Union(base, party[i][j]);
		}
	}
	
	int danger[55];
	memset(danger, 0, sizeof(danger));
	set<int>::iterator it;
	for (it = True.begin(); it != True.end(); it++) {
		int root = find(*it);
		danger[root] = 1;
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		bool flag = true;
		for (int j = 0; j < party[i].size(); j++) {
			int person = party[i][j];
			int root = find(person);
			if (danger[root] == 1) {
				flag = false;
				break;
			}
		}
		if (flag) ans++;
	}

	cout << ans;

	return 0;
}
