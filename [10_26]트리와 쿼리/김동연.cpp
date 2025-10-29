#include <iostream>
#include <vector>

using namespace std;
int n, root, q;
vector<int> tree[100001];
int memo[100001];
bool vis[100001];

int dfs(int str_node)
{
	int now = str_node;
	vis[now] = 1;
	int cnt = 1;

	for (int i = 0; i < tree[now].size(); i++)
	{
		int next = tree[now][i];
		if (vis[next] == 1) continue;

		cnt += dfs(next);
	}
	memo[str_node] = cnt;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> root >> q;

	for (int i = 0; i < n-1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	dfs(root);

	for (int i = 0; i < q;i++)
	{
		int val;
		cin >> val;
		cout << memo[val] << "\n";
	}

	return 0;
}
