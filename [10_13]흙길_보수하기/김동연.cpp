#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, l;

int main()
{
	scanf("%d %d", &n, &l);

	vector<pair<int, int>> list;

	for (int i = 0; i < n; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);

		list.push_back({ n1,n2 });
	}
	sort(list.begin(), list.end());
	int cnt = 0;
	int c = 0;
	for (int i = 0; i < list.size(); i++)
	{
		int len;
		int nf = list[i].first;
		int nb = list[i].second;

		if (c <= nf)
		{
			len = nb - nf;
			if (len % l != 0)
			{
				cnt += (len / l + 1);
				c = nf + (len / l + 1) * l;
				//change = true;
			}
			else if (len % l == 0)
			{
				cnt += (len / l);
				c = nb;
				//change = true;
			}
		}

		else if(c > nf)
		{
			len = nb - c;
			if(len <= 0)continue;
			if (len % l != 0)
			{
				cnt += (len / l + 1);
				c = c + (len / l + 1) * l;
			}
			else if (len % l == 0)
			{
				cnt += (len / l);
				c = nb;
			}	 
		}	
	}
	cout << cnt;
	return 0;
}
