#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
vector<int>vec[100];
vector<int>manlist;

int main()
{
	int T, mile;
	cin >> T >> mile;

	for (int i = 0; i < T; i++)
	{
		int mannum,sugangnum;
		cin >> mannum >> sugangnum;

		if (sugangnum > mannum)
			manlist.push_back(-1);
		else
		manlist.push_back(sugangnum);

		for (int j = 0; j < mannum; j++)
		{
			int val;
			cin >> val;
			vec[i].push_back(val);
		}
	}

	vector<int> minlist;//미니멈 값 저장

	for (int i = 0; i < T; i++)
	{
		sort(vec[i].begin(), vec[i].end(), greater<int>());

		if(manlist[i]==-1) 
			minlist.push_back(1);
		else
		{
			int idx = manlist[i] - 1;
			minlist.push_back(vec[i][idx]);
        }
	}
    
	sort(minlist.begin(), minlist.end());
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < minlist.size(); i++)
	{
		if (sum + minlist[i] <= mile)
		{
			sum += minlist[i];
			cnt++;
		}
	}
	cout<<cnt;
    
	return 0;
}
