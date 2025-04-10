#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[1001];

int main()
{
	int n;
	cin >> n;
	int max_val = 0;
	int min_val = 1001;//시작과 끝점 결정
	int max_h = 0;
	int min_h = 1001;
	//vector <pair<int, int>> vec;
 
	for (int i = 0; i < n; i++)
	{
		int num;
		int h;
		cin >> num >> h;

		if (num > max_val)
			max_val = num;
		if (num < min_val)
			min_val = num;

		if (h > max_h)
			max_h = h;
		if (h < min_h)
			min_h = h;


		//vec.push_back({ num, h });
		board[num] = h;
	}

	for (int i = 0; i <= max_val; i++)
	{
		if (board[i] > 0) continue;

		else 
			board[i] = 0;
	}

	//cout << board[4] << " " << board[0] << ' ' << board[8];

	int result = 0;
	int now = board[min_val];

	int up_cnt = 0;
	int down_cnt = 0;
	for (int i = min_val; i <= max_val; i++)
	{
		if (board[i] == max_h)
		{
			up_cnt = i;
			break;
		}

		if (board[i] >= now)
		{
			now = board[i];
			result += now;
		}
		else if (board[i] < now)
			result += now;
	}

	now = board[max_val];

	for (int i = max_val; i >= min_val; i--)
	{
		if (board[i] == max_h)
		{
			down_cnt = i;
			break;
		}

		if (board[i] <= now)
		{
			result += now;
		}
		else if (board[i] > now)
		{
			now = board[i];
			result += now;
		}
	}

	//cout << up_cnt << " " << down_cnt << "\n";

	for (int i = up_cnt; i <= down_cnt;i++)
		result += max_h;


	cout << result;


	return 0;
}
