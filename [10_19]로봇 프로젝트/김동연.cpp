#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
double h;
int n;


int main()
{
    while(cin >> h)
    {
        //cin >> n;
        scanf("%d", &n);

        vector<int> list;
        vector<pair<int, int>> res;

        for (int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            list.push_back(val);
        }

        sort(list.begin(), list.end());

        int c1 = 0;int c2 = list.size() - 1;

        for (;;)
        {
            if (c1 >= c2) break;
            int len1 = list[c1];
            int len2 = list[c2];

            double tmp = (len1 + len2) / 1e7;

            if (tmp == h)
            {
                res.push_back({ list[c1],list[c2] });
                c1++;
                c2--;
            }

            if (tmp > h)
                c2--;
            if (tmp < h)
                c1++;
        }

        if (res.size() == 0)
        {
            cout << "danger"<<"\n";
        }
        else if (res.size() > 0)
        {
            cout << "yes" << " ";
            cout << res[0].first << " " << res[0].second<<"\n";
        }
    }

    return 0;
}
