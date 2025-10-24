#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <memory.h>

using namespace std;

int n, m, k;
int ydir[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int xdir[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
struct node {
	int y;
	int x;
	int m;
	int s;
	int d;
};
struct edge {
	int y;
	int x;
	bool operator <(const edge& right) const {
		if (y != right.y) return y < right.y;
		return x < right.x;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<node> shark;
	vector<node> next;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		shark.push_back({ r, c, m, s, d });
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < shark.size(); j++) {
			int mv = shark[j].s % n;
			int d = shark[j].d;
			int ny = ((shark[j].y + ydir[shark[j].d] * mv - 1) % n + n) % n + 1;
			int nx = ((shark[j].x + xdir[shark[j].d] * mv - 1) % n + n) % n + 1;
			shark[j].y = ny;
			shark[j].x = nx;
		}
		map<edge, vector<node>> location;

		for (int j = 0; j < shark.size(); j++) {
			edge a = { shark[j].y, shark[j].x };
			location[a].push_back(shark[j]);
		}
		next.clear();

		map<edge, vector<node>> ::iterator it;
		for (it = location.begin(); it != location.end(); it++) {
			vector<node>& v = it->second;
			int cnt = v.size();

			if (cnt == 1) {
				next.push_back(v[0]);
			}
			else {
				int sum_m = 0;
				int sum_s = 0;
				int even_cnt = 0;
				int odd_cnt = 0;

				for (int j = 0; j < cnt; j++) {
					sum_m += v[j].m;
					sum_s += v[j].s;
					if (v[j].d % 2 == 0) even_cnt++;
					else odd_cnt++;
				}

				int nm = sum_m / 5;
				if (nm == 0) continue;
				int ns = sum_s / cnt;

				int dirs[4];
				if (even_cnt == cnt || odd_cnt == cnt) {
					dirs[0] = 0; dirs[1] = 2; dirs[2] = 4; dirs[3] = 6;
				}
				else {
					dirs[0] = 1; dirs[1] = 3; dirs[2] = 5; dirs[3] = 7;
				}

				for (int t = 0; t < 4; t++) {
					node ne;
					ne.y = it->first.y;
					ne.x = it->first.x;
					ne.m = nm;
					ne.s = ns;
					ne.d = dirs[t];
					next.push_back(ne);
				}
			}
		}
		shark.swap(next);
	}

	int ans = 0;
	for (int i = 0; i < shark.size(); i++) ans += shark[i].m;
	
	cout << ans;

	return 0;
}
