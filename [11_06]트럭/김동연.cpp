#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int len, w, n;
queue<int>list;
vector<int>bridge;

int check_sum()
{
	int t = 0;
	for (int i = 0; i < bridge.size();i++)
	{
		t += bridge[i];
	}
	return t;
}

bool check_brg()
{
	for (int i = 0; i < bridge.size();i++)
		if (bridge[i] != 0)return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> len >> w;

	for (int i = 0; i < n;i++)
	{
		int val;
		cin >> val;
		list.push(val);
	}

	bridge.push_back(0);
	int time = 0;
	bridge.resize(len, 0);
	while (!list.empty())
	{
		if (bridge.size() == len)
			bridge.erase(bridge.begin());
		int sum = check_sum();
		int cur = list.front();

		if (sum + cur <= w && list.size() > 0)
		{
			bridge.push_back(cur);
			list.pop();

			time++;
		}

		else
		{
			bridge.push_back(0);
			time++;
		}
	}
	cout << time+len;

	return 0;
}
