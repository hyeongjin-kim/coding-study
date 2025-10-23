#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
int map[501][501];
int dist[501][501];
int vis[501][501];
int n, m;
int sx, sy;
int peak, px, py;
int move_hw, move_lw, max_move;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> sx >> sy;
	cin >> move_hw >> move_lw >> max_move;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1;j <= m;j++)
		{
			int val;
			cin >> val;
			map[i][j] = val;
			dist[i][j] = 21e8;
			if (map[i][j] > peak)
			{
				peak = map[i][j];
				px = i;
				py = j;
			}
		}
	}

	int nx = sx;
	int ny = sy;
	priority_queue<pair<int, pair<int, int>>> pq; //w, sn, en
	pq.push({ 0,{sx, sy} });
	dist[nx][ny] = 0;
	vis[nx][ny] = 1;

	while (!pq.empty())
	{
		int cost = -pq.top().first; //pq정렬을 위해 음수 넣음 기본이 max힙이라 min힙처럼 사용하기 위해서
		int cx = pq.top().second.first;
		int cy = pq.top().second.second;
		pq.pop();

		for (int j = 0; j < 4; j++)
		{
			int nx = cx + dir[j][0];
			int ny = cy + dir[j][1];
			int w = 0;
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (abs(map[nx][ny] - map[cx][cy]) > max_move) continue;//클때 못움직임

			if (map[nx][ny] > map[cx][cy])
			{
				int diff = map[nx][ny] - map[cx][cy];
				w = move_hw * diff;
			}
			if (map[nx][ny] < map[cx][cy])
			{
				int diff = map[cx][cy] - map[nx][ny];
				w = move_lw * diff;
			}
			if (map[nx][ny] == map[cx][cy])
			{
				int diff = 0;
				w = 1;
			}


			if (dist[nx][ny] > cost + w)
			{
				dist[nx][ny] = cost + w;//갱신
				pq.push({ -dist[nx][ny],{nx,ny} });
			}
		}
	}
	if (dist[px][py] == 21e8)
		cout << -1;
	else
		cout << dist[px][py];
    
	return 0;
}
