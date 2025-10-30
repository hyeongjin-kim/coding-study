#include <iostream>
#include <vector>
#include <string>

using namespace std;
int map[10][10];
bool vis[10][10];
vector<pair<int, int>>list;
bool found = 0;

bool check_row(int r, int c, int num)
{
	for (int i = 1; i <= 9;i++)
		if (map[r][i] == num)return 0;
	return 1;
}
bool check_col(int r, int c, int num)
{
	for (int i = 1; i <= 9;i++)
		if (map[i][c] == num)return 0;
	return 1;
}

bool check3_3(int r, int c, int num)
{
	if (r % 3 == 1)
	{
		for (int i = r; i < r + 3;i++)
		{
			if (c % 3 == 1)
				for (int j = c; j < c + 3;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}

			else if (c % 3 == 2)
				for (int j = c - 1; j < c + 2;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}
			else if (c % 3 == 0)
				for (int j = c - 2; j < c + 1;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}
		}
		return 1;
	}
	else if (r % 3 == 2)
	{
		for (int i = r - 1; i < r + 2;i++)
		{
			if (c % 3 == 1)
				for (int j = c; j < c + 3;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}

			else if (c % 3 == 2)
				for (int j = c - 1; j < c + 2;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}
			else if (c % 3 == 0)
				for (int j = c - 2; j < c + 1;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}
		}
		return 1;
	}
	else if (r % 3 == 0)
	{
		for (int i = r - 2; i < r + 1;i++)
		{
			if (c % 3 == 1)
				for (int j = c; j < c + 3;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}

			else if (c % 3 == 2)
				for (int j = c - 1; j < c + 2;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}
			else if (c % 3 == 0)
				for (int j = c - 2; j < c + 1;j++)
				{
					if (i == r && j == c) continue;
					if (map[i][j] == num)return 0;
				}
		}
		return 1;
	}
}

void print()
{
	for (int i = 1; i <= 9;i++)
	{
		for (int j = 1;j <= 9; j++)
			cout << map[i][j]<<" ";
		cout << "\n";
	}
}

void dfs(int lev)
{
	if (lev == (int)list.size())
	{
		found = 1;
		return;
	}

	int x = list[lev].first;
	int y = list[lev].second;

	for (int val = 1; val <= 9; ++val)
	{
		if (check_row(x, y, val) && check_col(x, y, val) && check3_3(x, y, val))
		{
			map[x][y] = val;
			dfs(lev + 1);
			if (found == 1) return;
			map[x][y] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9;j++)
		{
			int val;
			cin >> val;
			map[i][j] = val;

			if (map[i][j] == 0)
				list.push_back({ i,j });
		}
	}

	if (list.size() == 0)
	{
		print();
		return 0;
	}

	int n1 = list[0].first;
	int n2 = list[0].second;
	vis[n1][n2] = 1;
	dfs(0);

	print();

	return 0;
}
