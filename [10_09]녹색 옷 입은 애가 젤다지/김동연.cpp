#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] ={{-1,0},{1,0},{0,1},{0,-1}};
int val;
int num = 1;
void bfs(vector<vector<int>>& d, vector<vector<int>>& m, vector<vector<int>>& v)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    v[0][0] = 1;
    d[0][0] = 0;
    
    while(!pq.empty())
    {
        int w = -pq.top().first;
        int cx = pq.top().second.first;
        int cy = pq.top().second.second;
        pq.pop();
        
        for(int i =0; i<4; i++)
        {
            int nx = cx + dir[i][0];
            int ny = cy + dir[i][1];

            if(nx < 0 || nx >= val || ny < 0 || ny >= val) continue;
            if(v[nx][ny] == 1)continue;
            
            int n_w = m[nx][ny];
            
            if(d[nx][ny] > w + n_w)
            {
                d[nx][ny] = w + n_w;//갱신
                pq.push({-d[nx][ny],{nx,ny}});
                v[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    while(1)
    {
        scanf("%d", &val);
        
        if(val == 0) return 0;
        
        vector<vector<int>> dist;
        vector<vector<int>> map;
        vector<vector<int>> vis;
        
        dist.resize(val,vector<int>(val,21e8));
        map.resize(val,vector<int>(val,0));
        vis.resize(val,vector<int>(val,0));
        
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i<val; i++)
            for(int j = 0; j<val; j++)
                scanf("%d", &map[i][j]);
            
        bfs(dist, map, vis);
        
        cout<<"Problem "<<num<<": "<<dist[val-1][val-1] + map[0][0]<<"\n";
        num++;
        
    }
    return 0;
}
