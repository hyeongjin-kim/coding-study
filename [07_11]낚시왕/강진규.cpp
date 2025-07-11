#include <iostream>
#include <algorithm>

using namespace std;

struct shark {
	int r, c, s, d, z;
	bool alive;
};

int R, C, M;
shark s[10001];
int field[100][100];
int newField[100][100];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;

	int ans = 0;
	int alive = M;

	for (int m = 1; m <= M; ++m) {
		cin >> s[m].r >> s[m].c >> s[m].s >> s[m].d >> s[m].z;
		--s[m].r;
		--s[m].c;
		s[m].alive = true;
		field[s[m].r][s[m].c] = m;
	}

	for (int curCol = 0; curCol < C && alive; ++curCol) {
		for (int curRow = 0; curRow < R; ++curRow) {
			if (field[curRow][curCol]) {
				ans += s[field[curRow][curCol]].z;
				s[field[curRow][curCol]].alive = false;
				//field[curRow][curCol] = 0;
				--alive;
				break;
			}
		}
		fill(&newField[0][0], &newField[99][100], 0);
		for (int m = 1; m <= M; ++m) {
			if (!s[m].alive) continue;
			if (s[m].d < 3) {
				int dividend = s[m].s;
				if(s[m].d == 2)
					dividend += s[m].r;
				else
					dividend += (R - 1 - s[m].r + R - 1);
				if ((dividend / (R - 1)) % 2 == 0) {
					s[m].d = 2;
					s[m].r = dividend % (R - 1);
				}
				else {
					s[m].d = 1;
					s[m].r = (R - 1) - dividend % (R - 1);
				}
			}
			else {
				int dividend = s[m].s;
				if(s[m].d == 3)
					dividend += s[m].c;
				else
					dividend += (C - 1 - s[m].c + C - 1);
				if ((dividend / (C - 1)) % 2 == 0) {
					s[m].d = 3;
					s[m].c = dividend % (C - 1);
				}
				else {
					s[m].d = 4;
					s[m].c = (C - 1) - dividend % (C - 1);
				}
			}
			if (newField[s[m].r][s[m].c]) {
				int original = newField[s[m].r][s[m].c];
				//shark original = s[newField[s[m].r][s[m].c]];
				if (s[original].z > s[m].z)
					s[m].alive = false;
				else {
					newField[s[m].r][s[m].c] = m;
					s[original].alive = false;
				}
				--alive;
			}
			else
				newField[s[m].r][s[m].c] = m;
		}
		swap(newField, field);

	}

	cout << ans;

	return 0;
}
