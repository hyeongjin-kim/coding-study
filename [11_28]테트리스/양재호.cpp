#include <iostream>

using namespace std;

int c, p;
int arr[105][105];
int fill_list[101];
struct node {
    int y;
    int x;
};
int block[8][4][4][2] =
{
    {},
    {
        {{0,0},{0,1},{0,2},{0,3}},
        {{0,0},{1,0},{2,0},{3,0}},
        {{0,0},{0,1},{0,2},{0,3}},
        {{0,0},{1,0},{2,0},{3,0}}
    },
    {
        {{0,0},{0,1},{1,0},{1,1}},
        {{0,0},{0,1},{1,0},{1,1}},
        {{0,0},{0,1},{1,0},{1,1}},
        {{0,0},{0,1},{1,0},{1,1}}
    },
    {
        {{0,1},{0,2},{1,0},{1,1}},
        {{0,0},{1,0},{1,1},{2,1}},
        {{0,1},{0,2},{1,0},{1,1}},
        {{0,0},{1,0},{1,1},{2,1}}
    },
    {
        {{0,0},{0,1},{1,1},{1,2}},
        {{0,1},{1,0},{1,1},{2,0}},
        {{0,0},{0,1},{1,1},{1,2}},
        {{0,1},{1,0},{1,1},{2,0}}
    },
    {
        {{0,0},{0,1},{0,2},{1,1}},
        {{0,1},{1,0},{1,1},{2,1}},
        {{1,1},{2,0},{2,1},{2,2}}, 
        {{0,0},{1,0},{1,1},{2,0}}
    },
    {
        {{0,2},{1,0},{1,1},{1,2}},
        {{0,0},{0,1},{1,1},{2,1}},
        {{1,0},{1,1},{1,2},{2,0}},
        {{0,0},{1,0},{2,0},{2,1}}
    },
    {
        {{0,0},{1,0},{1,1},{1,2}},
        {{0,0},{1,0},{2,0},{2,1}},
        {{1,0},{1,1},{1,2},{2,2}},
        {{0,0},{0,1},{1,0},{2,0}}
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> c >> p;

    for (int i = 0; i < c; i++) cin >> fill_list[i];

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < fill_list[i]; j++) {
            arr[i][j] = 1;
        }
    }
    int ans = 0;

    for (int rot = 0; rot < 4; rot++) {
        int minX = 1000;
        int maxX = -1000;
        for (int k = 0; k < 4; k++) {
            int lx = block[p][rot][k][1];
            if (lx < minX) minX = lx;
            if (lx > maxX) maxX = lx;
        }
        int width = maxX - minX + 1;

        int bottom[4];

        for (int i = 0; i < 4; i++) bottom[i] = -1;

        for (int k = 0; k < 4; k++) {
            int lx = block[p][rot][k][1] - minX;
            int ly = block[p][rot][k][0];
            if (bottom[lx] < ly) bottom[lx] = ly;
        }

        int pattern[4];
        int base = bottom[0];
        for (int t = 0; t < width; t++) {
            pattern[t] = bottom[t] - base;
        }

        bool dup = false;

        for (int prev = 0; prev < rot; prev++) {
            int maxX2 = -1000;
            int minX2 = 1000;

            for (int k = 0; k < 4; k++) {
                int lx = block[p][prev][k][1];
                if (lx > maxX2) maxX2 = lx;
                if (lx < minX2) minX2 = lx;
            }
            int width2 = maxX2 - minX2 + 1;
            if (width2 != width) continue;

            int bottom2[4];

            for (int i = 0; i < 4; i++) bottom2[i] = -1;

            for (int k = 0; k < 4; k++) {
                int lx2 = block[p][prev][k][1] - minX2;
                int ly2 = block[p][prev][k][0];
                if (bottom2[lx2] < ly2) bottom2[lx2] = ly2;
            }

            int base2 = bottom2[0];
            bool same = true;
            for (int t = 0; t < width; t++) {
                if (bottom2[t] - base2 != pattern[t]) {
                    same = false;
                    break;
                }
            }

            if (same) {
                dup = true;
                break;
            }
        }

        if (dup) continue;

        for (int start = 0; start + width <= c; start++) {
            bool ok = true;
            for (int t = 0; t < width; t++) {
                if (fill_list[start] - fill_list[start + t] != pattern[t]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }

    cout << ans;

	return 0;
}
