#include <iostream>
#include <vector>
#include <queue>



using namespace std;
int dir[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
int board[102][102][102];
int vis[102][102][102];
//int board[5][3][2];
//int vis[5][3][2];
int n, m, h;

bool check(int z, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h) return 0;
    return 1;
}


int main()
{

    cin >> m >> n >> h;
    queue<pair<int, pair<int, int>>>q;

    for (int i = 0;i < h;i++)
    {
        for (int j = 0;j < n;j++)
        {
            for (int k = 0;k < m;k++)
            {
                int val;
                cin >> val;
                board[i][j][k] = val;

                if (val == 1)
                    q.push({ i,{j,k} });
            }
        }
    }

    int day = 0;
    int cnt = 0;

    for (int i = 0;i < h;i++)
        for (int j = 0;j < n;j++)
            for (int k = 0;k < m;k++)
                if (board[i][j][k] != 0)
                {
                    cnt++;
                }

    if (cnt == m * n * h)
    {
        cout << 0;
        return 0;
    }

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0;i < size;i++)
        {
            int cz = q.front().first;
            int cx = q.front().second.first;
            int cy = q.front().second.second;

            vis[cz][cx][cy] = 1;
            q.pop();

            for (int i = 0;i < 6;i++)
            {
                int nx = cx + dir[i][0];
                int ny = cy + dir[i][1];
                int nz = cz + dir[i][2];
                if (check(nz, nx, ny) == 0 || vis[nz][nx][ny] > 0 || board[nz][nx][ny] == -1) continue;

                vis[nz][nx][ny] = 1;
                board[nz][nx][ny] = 1;
                q.push({ nz,{nx,ny} });
            }
        
        }
        day++;
    }


    for (int i = 0;i < h;i++)
        for (int j = 0;j < n;j++)
            for (int k = 0;k < m;k++)
                if (board[i][j][k] == 0)
                {
                    day = -1;
                    cout << day;
                    return 0;
                }
    cout << day-1;


    return 0;
}
