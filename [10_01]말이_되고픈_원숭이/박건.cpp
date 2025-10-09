#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

#define endl '\n'

#define LIM 987654321

using namespace std;

struct stat{
    int y;
    int x;
    int j;
};

int k, w, h;
int board[200][200];
int dist[31][200][200];

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int hy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int hx[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isRange(int y, int x){
    return y >= 0 && y < h && x >= 0 && x < w && board[y][x] == 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dist, -1, sizeof(dist));

    int res = LIM;
    deque<stat> dq;

    cin >> k >> w >> h;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }

    dq.push_back({0, 0, k});
    dist[k][0][0] = 0;
    
    while(!dq.empty()){
        stat cur = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            int nj = cur.j;
            if (!isRange(ny, nx)) continue;
            if (dist[nj][ny][nx] != -1) continue;

            dist[nj][ny][nx] = dist[cur.j][cur.y][cur.x] + 1;
            dq.push_back({ny, nx, nj});
        }
        
        if(cur.j > 0){
            for (int i = 0; i < 8; i++){
                int ny = cur.y + hy[i];
                int nx = cur.x + hx[i];
                int nj = cur.j - 1;
                if (!isRange(ny, nx)) continue;
                if (dist[nj][ny][nx] != -1) continue;

                dist[nj][ny][nx] = dist[cur.j][cur.y][cur.x] + 1;
                dq.push_back({ny, nx, nj});
            }
        }
        
    }

    for (int i = 0; i <= k; i++){
        if(dist[i][h-1][w-1] != -1){
            res = min(res, dist[i][h - 1][w - 1]);
        }
    }
    
    if(res == LIM)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}
