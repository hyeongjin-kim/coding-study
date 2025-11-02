#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <memory.h>

using namespace std;

int n, m;
int arr[10][10];
int ydir1[] = { 0, -1, 0, 1 };
int xdir1[] = { -1, 0, 1, 0 };
int ydir2[2][2] = { {0, 0}, {-1, 1} };
int xdir2[2][2] = { {-1, 1}, {0, 0} };
int ydir3[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
int xdir3[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int ydir4[4][3] = { {0, -1, 0}, {-1, 0, 1}, {0, 1, 0}, {1, 0, -1} };
int xdir4[4][3] = { {-1, 0, 1}, {0, 1, 0}, {1, 0, -1}, {0, -1, 0} };
struct node {
    int y;
    int x;
    int size;
    bool operator <(const node& right) {
        if (size != right.size) return size > right.size;
        return false;
    }
};
int emptycnt;
int ans = INT_MAX;
vector<node> cctv;
int visit[10][10];

void apply_line(int sy, int sx, int dy, int dx, int delta) {
    int y = sy + dy;
    int x = sx + dx;
    while (y >= 0 && x >= 0 && y < n && x < m && arr[y][x] != 6) {
        if (arr[y][x] == 0) {
            if (delta == 1) {
                if (visit[y][x] == 0) emptycnt--;
                visit[y][x] += 1;
            }
            else {
                visit[y][x] -= 1;
                if (visit[y][x] == 0) emptycnt++;
            }
        }
        y += dy;
        x += dx;
    }
}
void apply_type(int y, int x, int t, int i, int delta) {
    if (t == 1) {
        apply_line(y, x, ydir1[i], xdir1[i], delta);
    }
    else if (t == 2) {
        for (int j = 0; j < 2; j++) {
            apply_line(y, x, ydir2[i][j], xdir2[i][j], delta);
        }
    }
    else if (t == 3) {
        for (int j = 0; j < 2; j++) {
            apply_line(y, x, ydir3[i][j], xdir3[i][j], delta);
        }
    }
    else if (t == 4) {
        for (int j = 0; j < 3; j++) {
            apply_line(y, x, ydir4[i][j], xdir4[i][j], delta);
        }
    }
    else if (t == 5) {
        for (int j = 0; j < 4; j++) {
            apply_line(y, x, ydir1[j], xdir1[j], delta);
        }
    }
}

void dfs(int num) {
    if (num == cctv.size()) {
        if (emptycnt < ans) ans = emptycnt;
        return;
    }

    int y = cctv[num].y;
    int x = cctv[num].x;
    int t = arr[y][x];

    if (t == 1) {
        for (int i = 0; i < 4; i++) {
            apply_type(y, x, t, i, 1);
            dfs(num + 1);
            apply_type(y, x, t, i, -1);
        }
    }
    else if (t == 2) {
        for (int i = 0; i < 2; i++) {
            apply_type(y, x, t, i, 1);
            dfs(num + 1);
            apply_type(y, x, t, i, -1);
        }
    }
    else if (t == 3 || t == 4) {
        for (int i = 0; i < 4; i++) {
            apply_type(y, x, t, i, 1);
            dfs(num + 1);
            apply_type(y, x, t, i, -1);
        }
    }
    else if (t == 5) {
        apply_type(y, x, t, 0, 1);
        dfs(num + 1);
        apply_type(y, x, t, 0, -1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) emptycnt++;
            else if (arr[i][j] == 6) continue;
            else cctv.push_back({ i, j, arr[i][j]});
        }
    }

    sort(cctv.begin(), cctv.end());

    dfs(0);

    cout << ans;

    return 0;
}
