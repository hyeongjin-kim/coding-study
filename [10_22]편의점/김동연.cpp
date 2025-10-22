#include <iostream>
#include <vector>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;
int n, m, p, q;

vector<pair<int, int>> map[5001];
long long dist[5001];
vector<int> home;
vector<int> store;

void init()
{

	//cin >> n >> m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)//init
		dist[i] = 21e8;

	for (int i = 0; i < m; i++)
	{
		int n1, n2, w;
		scanf("%d %d %d", &n1, &n2, &w);
		map[n2].push_back({ n1,w });
		map[n1].push_back({ n2,w });
	}

	//cin >> p >> q;//p_home, q_store
	scanf("%d %d", &p, &q);

	for (int i = 0; i < p; i++)
	{
		int h;
		scanf("%d", &h);
		home.push_back(h);
	}

	for (int i = 0; i < q; i++)
	{
		int s;
		scanf("%d", &s);
		store.push_back(s);
	}
}

int main()
{
	init();
	int min_node = 10000;
	int min_dist = 21e8;
	for (int i = 0; i < store.size(); i++)
	{
		//for (int k = 0; k <= n; k++)//init
			//dist[k] = 21e8;

		int now = store[i];
		priority_queue<pair<int,int>> pq; //w, sn, en
		pq.push({ 0,now });
		dist[now] = 0;

		while (!pq.empty())
		{
			int cost = -pq.top().first; //pq정렬을 위해 음수 넣음 기본이 max힙이라 min힙처럼 사용하기 위해서
			int cur = pq.top().second;
			pq.pop();

			for (int j = 0; j < map[cur].size(); j++)
			{
				int next = map[cur][j].first;
				int n_cost = map[cur][j].second;

				if (dist[next] > cost + n_cost)
				{
					dist[next] = cost + n_cost;//갱신
					pq.push({ -dist[next],next });
				}
			}
		}

		for (int j = 0; j <home.size();j++)
		{
			int cur_node = home[j];
			if (dist[cur_node] < min_dist)
			{
				min_node = cur_node;
				min_dist = dist[cur_node];
			}
		}
	}

	cout << min_node;

	return 0;
}
