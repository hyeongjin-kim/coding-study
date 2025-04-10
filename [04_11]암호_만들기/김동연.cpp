#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
char path[20];
vector<char> vec;
int vis[300];
int mo = 0;
int ja = 0;

void dfs(int level)
{
    //cout << "test1" << "\n";
    if (level == n)
    {
        mo = 0;
        ja = 0;
        for (int k = 0; k < n; k++)
        {
            int i = path[k];
            if (i == 97 || i == 101 || i == 105 || i == 111 || i == 117)
                mo++;
            else
                ja++;
        }

        if (mo < 1 || ja < 2) return;

        for (int i = 0; i < n;i++)
        {
            cout << path[i];
        }
        cout << "\n";
        //cout << "val:" << mo << " " << ja << "\n";
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (vis[vec[i]] == 1) continue;

        if (level > 0 && path[level - 1] > vec[i]) continue;


        path[level] = vec[i];
        vis[vec[i]] = 1;

        dfs(level + 1);

        path[level] = 0;
        vis[vec[i]] = 0;
    }
}

int main()
{
    string in;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        char val;
        cin >> val;
        in += val;
    }

    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == ' ') continue;

        vec.push_back(in[i]);
    }

    sort(vec.begin(), vec.end());
    dfs(0);
    
    return 0;
}
