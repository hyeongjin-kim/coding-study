#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[30][30];
int vis[30][30];
int dir[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };

vector<int> like[500];
vector<int> manlist;
int val, n;

int check_range(int x, int y)
{
	if (x < 1 || y < 1 || x > n || y > n) return 0;
	return 1;
}

// 조건1: 좋아하는 학생이 인접한 칸에 몇 명 있는지
int func1(int cx, int cy, int man_n)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dir[i][0];
		int ny = cy + dir[i][1];

		if (check_range(nx, ny) == 0) continue;

		int cord = map[nx][ny];
		for (int j = 0; j < 4; j++)
		{
			if (cord == like[man_n][j])
			{
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

// 조건2: 인접한 비어있는 칸 개수
int empty(int cx, int cy)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = cx + dir[i][0];
		int ny = cy + dir[i][1];

		if (check_range(nx, ny) && map[nx][ny] == 0)
			cnt++;
	}
	return cnt;
}

int main()
{
	cin >> n;
	val = n * n;

	for (int i = 1; i <= val; i++)
	{
		int man_num;
		cin >> man_num;
		manlist.push_back(man_num);
		for (int j = 0; j < 4; j++)
		{
			int n;
			cin >> n;
			like[man_num].push_back(n);
		}
	}

	for (int k = 0; k < val; k++)//사람 하나씩 체크해보기
	{
		int max_like = -1, max_empty = -1;
		int final_x = 0;
		int final_y = 0;
		int man = manlist[k];

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] != 0) continue;

				int like_cnt = func1(i, j, man);
				int empty_cnt = empty(i, j);

				// 조건1 > 조건2 > 조건3
				if (like_cnt > max_like ||
					(like_cnt == max_like && empty_cnt > max_empty) ||
					(like_cnt == max_like && empty_cnt == max_empty && 
					(i < final_x || (i == final_x && j < final_y))))
				{
					max_like = like_cnt;
					max_empty = empty_cnt;
					final_x = i;
					final_y = j;
				}
			}
		}
		map[final_x][final_y] = man;
	}

	int total_score = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int man = map[i][j];
			int cnt = 0;

			for (int d = 0; d < 4; d++)
			{
				int ni = i + dir[d][0];
				int nj = j + dir[d][1];

				if (check_range(ni, nj) == 0) continue;

				for (int l = 0; l < 4; l++)
				{
					if (map[ni][nj] == like[man][l])
					{
						cnt++;
						break;
					}
				}
			}

			if (cnt == 1) total_score += 1;
			else if (cnt == 2) total_score += 10;
			else if (cnt == 3) total_score += 100;
			else if (cnt == 4) total_score += 1000;
		}
	}

	cout << total_score;

	return 0;
}
