#include <iostream>
#include <vector>

using namespace std;

int n, m, num;
int map[301][301];
pair<int, int> angle1;
pair<int, int> angle2;
pair<int, int> angle3;
pair<int, int> angle4;

void rotate()
{
	while (1)
	{
		if (angle1.second >= angle2.second || angle1.first >= angle3.first) return;
		int coner1 = map[angle1.first][angle1.second];
		int coner2 = map[angle2.first][angle2.second];
		int coner3 = map[angle3.first][angle3.second];
		int coner4 = map[angle4.first][angle4.second];

		for (int i = angle1.second; i < angle2.second; i++)
			map[angle1.first][i] = map[angle1.first][i + 1];

		for (int i = angle2.first; i < angle4.first; i++)
			map[i][angle2.second] = map[i + 1][angle2.second];

		for (int i = angle4.second; i > angle3.second; i--)
			map[angle3.first][i] = map[angle3.first][i - 1];

		for (int i = angle3.first; i > angle1.first; i--)
			map[i][angle1.second] = map[i - 1][angle1.second];

		map[angle1.first + 1][angle1.second] = coner1;
		map[angle2.first][angle2.second - 1] = coner2;
		map[angle3.first][angle3.second + 1] = coner3;
		map[angle4.first - 1][angle4.second] = coner4;

		angle1 = { angle1.first + 1, angle1.second + 1 };
		angle2 = { angle2.first + 1, angle2.second - 1 };
		angle3 = { angle3.first - 1, angle3.second + 1 };
		angle4 = { angle4.first - 1, angle4.second - 1 };
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> num;

	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			int val;
			cin >> val;
			map[i][j] = val;
		}
	}
	///1 2
	///3 4 순서임
	for (int i = 0; i < num;i++)
	{
		angle1 = { 0, 0 };
		angle2 = { 0, m - 1 };       // (0, n-1) -> (0, m-1)
		angle3 = { n - 1, 0 };       // (m-1, 0) -> (n-1, 0)
		angle4 = { n - 1, m - 1 };   // (m-1, n-1) -> (n-1, m-1)
		rotate();
	}


	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < m;j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << "\n";
	}

	return 0;
}
