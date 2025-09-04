#include <string>
#include <vector>
#include <queue>

using namespace std;

bool board[101][101];
bool vis[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    for (int r = 0; r < rectangle.size(); ++r) {
        int sx = rectangle[r][0] * 2, sy = rectangle[r][1] * 2;
        int ex = rectangle[r][2] * 2, ey = rectangle[r][3] * 2;

        for (int i = sx; i <= ex; ++i) {
            board[i][sy] = true;
            board[i][ey] = true;
        }
        for (int j = sy; j <= ey; ++j) {
            board[sx][j] = true;
            board[ex][j] = true;
        }
    }
    for (int r = 0; r < rectangle.size(); ++r) {
        int sx = rectangle[r][0] * 2, sy = rectangle[r][1] * 2;
        int ex = rectangle[r][2] * 2, ey = rectangle[r][3] * 2;
        for (int i = sx + 1; i < ex; ++i)
            for (int j = sy + 1; j < ey; ++j)
                board[i][j] = false;
    }

    queue<pair<int, int>> q;
    q.push({ characterX, characterY });
    vis[characterX][characterY] = true;

    while (!q.empty()) {
        int curIt = q.size() + 1;
        while (--curIt) {
            int curX = q.front().first;
            int curY = q.front().second;
            q.pop();
            if (curX == itemX && curY == itemY)
                return answer / 2;
            for (int d = 0; d < 4; ++d) {
                int nx = curX + dx[d];
                int ny = curY + dy[d];
                if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
                if (vis[nx][ny] || !board[nx][ny]) continue;
                q.push({ nx,ny });
                vis[nx][ny] = true;
            }
        }
        ++answer;
    }


    return 0;
}
