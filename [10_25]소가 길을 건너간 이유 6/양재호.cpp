#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, k, r;
struct node {
    int y;
    int x;
    bool operator <(const node& right) const {
        if (y != right.y) return y < right.y;
        return x < right.x;
    }
};
int visited[105][105];
int blocked[4][105][105];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int ans;
vector<node> cow;

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    queue<node> q;
    q.push({ y, x });
    visited[y][x] = 1;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
            if (blocked[i][now.y][now.x]) continue;
            if (visited[ny][nx] > 0) continue;
            visited[ny][nx] = 1;
            q.push({ ny, nx });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> r;

    for (int i = 0; i < r; i++) {
        int sy, sx, ex, ey;
        cin >> sy >> sx >> ey >> ex;

        if (sy == ey) {
            if (sx < ex) {

                blocked[3][sy][sx] = 1;
                blocked[2][ey][ex] = 1;
            }
            else {
                blocked[2][sy][sx] = 1;
                blocked[3][ey][ex] = 1;
            }
        }
        else {
            if (sy < ey) {
                blocked[1][sy][sx] = 1;
                blocked[0][ey][ex] = 1;
            }
            else {
                blocked[0][sy][sx] = 1;
                blocked[1][ey][ex] = 1;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int sy, sx;
        cin >> sy >> sx;
        cow.push_back({ sy, sx });
    }

    for (int i = 0; i < k; i++) {
        bfs(cow[i].y, cow[i].x);

        for (int j = i+1; j < k; j++) {
            if (visited[cow[j].y][cow[j].x] == 0) ans++;
        }
    }

    cout << ans;

    return 0;
}
