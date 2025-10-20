#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int ydir[] = { 0, 0, 1, -1 };
int xdir[] = { 1, -1, 0, 0 };
int Left[] = { 3, 2, 0, 1 };
int Right[] = {2, 3, 1, 0};
int n, m;
int arr[105][105];
int visited[4][105][105];
struct node {
    int y;
    int x;
    int dir;
};
int sy, sx, sdir;
int ey, ex, edir;


void bfs(int y, int x, int dir) {
    queue<node> q;
    q.push({ y, x, dir -1 });
    visited[dir - 1][y][x] = 0;

    while (!q.empty()) {
        node now = q.front(); q.pop();

        int ndir = Left[now.dir];
        bool flag = false;

        if (visited[ndir][now.y][now.x] == -1) {
            visited[ndir][now.y][now.x] = visited[now.dir][now.y][now.x] + 1;
            q.push({ now.y, now.x, ndir });
        }

        ndir = Right[now.dir];

        if (visited[ndir][now.y][now.x] == -1) {
            visited[ndir][now.y][now.x] = visited[now.dir][now.y][now.x] + 1;
            q.push({ now.y, now.x, ndir });
        }

        for (int i = 1; i <= 3; i++) {
            int ny = now.y + ydir[now.dir] * i;
            int nx = now.x + xdir[now.dir] * i;
            if (ny < 1 || nx < 1 || ny > n || nx > m) break;
            if (arr[ny][nx] == 1) break;
            if (visited[now.dir][ny][nx] == -1) {
                visited[now.dir][ny][nx] = visited[now.dir][now.y][now.x] + 1;
                q.push({ ny, nx, now.dir });
            }
        }
        
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(visited, -1, sizeof(visited));

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> sy >> sx >> sdir >> ey >> ex >> edir;

    bfs(sy, sx, sdir);

    cout << visited[edir - 1][ey][ex];

    return 0;
}
