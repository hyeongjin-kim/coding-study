#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

struct step {
	int loc;
	int hop;
};

//unordered_set<int> smallStones;
bool vis[10001][150];
bool smallStones[10001];

int main(void) {
	int N, M;
	cin >> N >> M;

	while (M--) {
		int small;
		cin >> small;
		//smallStones.insert(small);
		smallStones[small] = true;
	}

	queue<step> q;
	q.push({ 1,0 });
	int ans = 0;

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i) {
			step cur = q.front(); q.pop();
			int curLoc = cur.loc;
			int curHop = cur.hop;
			if (curLoc == N) {
				cout << ans;
				return 0;
			}

			for (int nHop = curHop + 1; nHop > 0 && nHop > curHop - 2; --nHop) {
				int nLoc = curLoc + nHop;
				if (nLoc > N || smallStones[nLoc]/*smallStones.find(nLoc) != smallStones.end()*/)
					continue;
				if (vis[nLoc][nHop])
					continue;

				vis[nLoc][nHop] = true;
				q.push({ nLoc, nHop });
			}
		}
		++ans;
	}
	cout << -1;
	return 0;
}
