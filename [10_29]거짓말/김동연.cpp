#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int node, party_num;
int know;
vector<int> truth;
int map[51][51];
vector<vector<int>> party;
bool vis[51];

void dfs(int cur)
{
	vis[cur] = 1;
	map[cur][0] = -1;
	for (int i = 1; i < 51; i++)
	{
		if (map[cur][i] == 1)
		{
			int nex = i;
			if (vis[nex] == 1)continue;
			map[0][nex] = -1;
			vis[i] = 1;
			dfs(i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> node >> party_num;
	cin >> know;
	if (know == 0)
	{
		for (int j=0;j< party_num; j++)
		{
			int t1;
			cin >> t1;
			for (int k = 0; k < t1; k++)
			{
				int v;
				cin >> v;
			}
		}
		cout << party_num;
		return 0;
	}

	else if (know != 0)//아는 사람 처리
	{
		for (int i = 0; i < know; i++)
		{
			int val;
			cin >> val;
			truth.push_back(val);
			//map[val][0] = -1;
		}
	}
	
	for (int i = 0; i < party_num; i++)//파티 처리
	{
		int mans;
		cin >> mans;
		vector<int> list;

		for (int j = 0; j < mans; j++)
		{
			int man;
			cin >> man;
			list.push_back(man);
		}
		party.push_back(list);//파티안에 리스트로 파티 참여 인원 넣기

		for (int j = 0; j < list.size(); j++) // 지도에 표시
		{
			for (int k = 0; k < list.size(); k++)
			{
				int now = list[j];
				int next = list[k];
				map[now][next] = 1;
			}
		}
	}

	for (int i = 0; i < truth.size(); i++)
	{
		int tmp = truth[i];
        memset(vis, 0, sizeof(vis));
		dfs(tmp);
	}
	int cnt = 0;

	for (int i = 0; i < party.size(); i++)
	{
		int flag = 0;

		for (int j = 0; j < party[i].size(); j++)
		{
			int now = party[i][j];
			if (map[now][0] == -1)
			{
				flag = 1;
				break;
			}
		}
		//cout << i << "\n";
		if (flag == 0) 
			cnt += 1;
	}

	cout << cnt;
	return 0;	
}
