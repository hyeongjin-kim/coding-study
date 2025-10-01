#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Step{
	int count;
	int horse;
	int r;
	int c;
};

int drhorse[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dchorse[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int visit[31][201][201];
int map[201][201]; 

int K, W, H;

bool isOutOfBound(int r, int c) {
	return (r < 0 or r >= H or c < 0 or c >= W);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> K >> W >> H;
	const int MAX_VALUE = 100000000;
	fill(&visit[0][0][0], &visit[0][0][0] + 31 * 201 * 201, MAX_VALUE);

	visit[0][0][0] = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	queue<Step> q;

	q.push({ 0,0,0,0 });
	visit[0][0][0] = 0;
	while (!q.empty()) {

		Step cur = q.front();
		q.pop();

		int count = cur.count, r = cur.r, c = cur.c, horse = cur.horse;
		
		if (visit[horse][r][c] < count) continue;
		if (r == H - 1 and c == W - 1) break;
		//cout << "r: " << r << " c: " << c << " count: " << count << " horse: " << horse << endl;
		if (horse < K) {
			for (int dir = 0; dir < 8; dir++) {
				int nr = r + drhorse[dir], nc = c + dchorse[dir];
				if (isOutOfBound(nr, nc)) continue;
				if (map[nr][nc] == 1) continue;
				if (visit[horse + 1][nr][nc] <= (count + 1)) continue;
				visit[horse + 1][nr][nc] = count + 1;
				q.push({ count + 1, horse + 1, nr, nc });
			}
		}
		
		for (int dir = 0; dir < 4; dir++) {
			int nr = r + dr[dir], nc = c + dc[dir];
			if (isOutOfBound(nr, nc)) continue;
			if (map[nr][nc] == 1) continue;
			if (visit[horse][nr][nc] <= (count + 1)) continue;
			visit[horse][nr][nc] = count + 1;
			q.push({ count + 1, horse, nr, nc });
		}
	}
	int result = MAX_VALUE;

	for (int i = 0; i <= K; i++) {
		if (result > visit[i][H - 1][W - 1]) result = visit[i][H - 1][W - 1];
	}
	
	if ( result == MAX_VALUE) result = -1;
	
	cout << result;

	return 0;
}
