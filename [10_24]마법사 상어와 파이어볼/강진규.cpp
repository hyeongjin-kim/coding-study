#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

struct Fireball {
	int r, c;
	int m, s, d;
};

struct Coord {
	int first, second;

	bool operator<(const Coord& right) const {
		if (first == right.first)
			return second < right.second;
		return first < right.first;
	}
};

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

vector<Fireball> field[50][50];
//set<Coord> s;
unordered_set<int> s;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	queue<Fireball> q;
	for (int i = 0; i < M; ++i) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		q.push({ a - 1,b - 1,c,d,e });
	}

	while (K-- && !q.empty()) {
		int qSize = q.size() + 1;
		s.clear();
		while (--qSize) {
			Fireball cur = q.front(); q.pop();
			int nx = (cur.r + dx[cur.d] * cur.s + N * 1000) % N;
			int ny = (cur.c + dy[cur.d] * cur.s + N * 1000) % N;

			field[nx][ny].push_back({ nx,ny, cur.m,cur.s,cur.d });
			//s.insert({ nx,ny });
			s.insert(nx * N + ny);
		}

		for (auto it = s.begin(); it != s.end(); ++it) {
			/*int curx = it->first;
			int cury = it->second;*/
			int curx = *it / N;
			int cury = *it % N;
			int vSize = field[curx][cury].size();
			if (vSize == 1) {
				q.push(field[curx][cury][0]);
				field[curx][cury].resize(0);
				continue;
			}
			int dirSum = 0;
			int mSum = 0;
			int sSum = 0;
			for (auto it = field[curx][cury].begin(); it != field[curx][cury].end(); ++it) {
				dirSum += (it->d % 2);
				mSum += it->m;
				sSum += it->s;
			}
			field[curx][cury].resize(0);
			int newM = mSum / 5;
			int newS = sSum / vSize;
			if (!newM)
				continue;
			int newDir = ((dirSum == vSize || !dirSum) ? 0 : 1);
			for (; newDir < 8; newDir += 2) {
				q.push({ curx,cury,newM,newS,newDir });
			}
			

		}
	}
	int ans = 0;
	while (!q.empty()) {
		Fireball cur = q.front(); q.pop();
		ans += cur.m;
	}
	cout << ans;
	return 0;
}
