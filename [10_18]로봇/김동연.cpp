#include <iostream>
#include <queue>

using namespace std;

int sx, sy, sd; // 시작 (x, y, 방향)
int ex, ey, ed; // 도착 (x, y, 방향)
int n, m;
int map[101][101];
int min_ord[101][101][5]; // min_ord[x][y][d]

int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };

struct Node { int x, y, d; }; // cost 멤버 제거

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= 4; k++) // 1~4 방향
                min_ord[i][j][k] = 2147483647; // 21e8 대신 int 최대값

    queue<Node> q;

    min_ord[sx][sy][sd] = 0;
    q.push({ sx, sy, sd }); // cost 없이 push

    int answer = 21e8;

    while (!q.empty())
    {
        Node cur = q.front(); q.pop();
        int cx = cur.x, cy = cur.y, cd = cur.d;

        int w = min_ord[cx][cy][cd];

        if (cx == ex && cy == ey)
        {
            int add_turn = 0;
            if (cd != ed)
            {
                if ((cd == 1 && ed == 2) || (cd == 2 && ed == 1) || (cd == 3 && ed == 4) || (cd == 4 && ed == 3)) add_turn = 2;
                else add_turn = 1;
            }
            answer = min(answer, w + add_turn);
        }

        for (int nd = 1; nd <= 4; nd++) // nd: Next Direction
        {
            int turn_cost = 0;
            if (cd != nd)
            {
                if ((cd == 1 && nd == 2) || (cd == 2 && nd == 1) || (cd == 3 && nd == 4) || (cd == 4 && nd == 3)) turn_cost = 2; // 180도
                else turn_cost = 1; // 90도
            }

            int nx = cx, ny = cy;
            for (int k = 1; k <= 3; k++) // k: 1, 2, 3칸 이동
            {
                nx += dx[nd];
                ny += dy[nd];

                if (nx<1 || nx>n || ny<1 || ny>m) break;
                if (map[nx][ny] == 1) break;

                int nw = w + turn_cost + 1;

                if (min_ord[nx][ny][nd] > nw)
                {
                    min_ord[nx][ny][nd] = nw;
                    q.push({ nx, ny, nd }); // cost 없이 push
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
