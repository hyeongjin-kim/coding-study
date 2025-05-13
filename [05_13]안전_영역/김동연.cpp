#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int map[105][105][2];
int s;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

vector<int> list;
vector<pair<int, int>> cord;
int vis[105][105];
bool check_range(int X, int Y)
{
    return X > 0 && X <= s && Y > 0 && Y <= s;
}

void h_check(int v)
{
    cord.clear();

    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= s; j++)
        {
            if (map[i][j][0] <= v)
                map[i][j][1] = -1;  // 물에 잠긴 영역
            else
                map[i][j][1] = 0;   // 초기화 필요
        }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    vis[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if (!check_range(nx, ny) || vis[nx][ny] || map[nx][ny][1] == -1) continue;

            vis[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    cin >> s;
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= s; j++)
            cin >> map[i][j][0];

    int result = 0;

    for (int h = 0; h <= 100; h++)  // 모든 비 높이에 대해 검사
    {
        h_check(h);
        memset(vis, 0, sizeof(vis));

        int cnt = 0;

        for (int i = 1; i <= s; i++)
            for (int j = 1; j <= s; j++)
            {
                if (!vis[i][j] && map[i][j][1] != -1)
                {
                    bfs(i, j);
                    cnt++;  // 안전 영역 개수 증가
                }
            }

        result = max(result, cnt);
    }

    cout << result;
    return 0;
}
