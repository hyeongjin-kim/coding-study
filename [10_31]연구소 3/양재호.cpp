#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int n, m;
int arr[52][52];
int visited[52][52];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
    int y;
    int x;
};
vector<node> virus;
vector<node> use_virus;
queue<node> q;
int ans = 3000;
int Max;

void bfs() {
    Max = 0;
    while (!q.empty()) {
        node now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (arr[ny][nx] == 1) continue;
            if (visited[ny][nx] > -1) continue;
            visited[ny][nx] = visited[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0 && visited[i][j] == -1) {
                Max = -1;
                return;
            }
            else if (arr[i][j] == 0 && visited[i][j] > Max) Max = visited[i][j];
        }
    }
}

void dfs(int num, int idx) {
    if (num == m) {
        memset(visited, -1, sizeof(visited));
        for (int i = 0; i < use_virus.size(); i++) {
            q.push(use_virus[i]);
            visited[use_virus[i].y][use_virus[i].x] = 0;
        }
        bfs();

        if (Max != -1 && Max < ans) ans = Max;
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        use_virus.push_back(virus[i]);
        dfs(num + 1, i + 1);
        use_virus.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({ i, j });
        }
    }
    dfs(0, 0);

    if (ans == 3000) cout << -1;
    else cout << ans;

    return 0;
}
