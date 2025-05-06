#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_N 1005

struct edge{
    int node;
    int cost;
};

int n; // n개의 숫자로 구분된 마을
int m; // m개의 길
int x; // x번 마을에서 파티함
vector<edge> edges[MAX_N];
vector<edge> r_edges[MAX_N];
int dist1[MAX_N];
int dist2[MAX_N];

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;

void Print(){
    for(int i=1; i<=n; i++)
        cout << dist1[i] <<" ";
    cout <<"\n";
    for(int i=1; i<=n; i++)
        cout << dist2[i] <<" ";
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> x;
    for(int i=1; i<=m; i++){
        int s,e,c;
        cin >> s >> e >> c;
        edges[s].push_back({e,c});
        r_edges[e].push_back({s,c});
    }
    
    fill(dist1, dist1+n+1, INT_MAX);
    fill(dist2, dist2+n+1, INT_MAX);

    
    // x번에서 1~n번까지 가는 비용
    // 1~n번에서 x번까지 가는 비용 (입력된 정보들의 방향을 반대로 하고 x번에서 출발하기)
    
    pq.push({0,x});
    dist1[x] = 0;
    
    while(pq.empty()==false){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        
        if(dist1[cur] < cost) continue;
        
        for(int i=0; i<(int) edges[cur].size(); i++){
            int n_node,n_cost;
            n_node = edges[cur][i].node;
            n_cost = edges[cur][i].cost + cost;
            if(n_cost < dist1[n_node] ){
                dist1[n_node] = n_cost;
                pq.push({n_cost,n_node});
            }
        }
    }
    
    
    while(pq.empty() == false)
        pq.pop();
    
    pq.push({0,x});
    dist2[x] = 0;
    
    
    while(pq.empty()==false){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        
        if(dist2[cur] < cost) continue;
        
        for(int i=0; i<(int) r_edges[cur].size(); i++){
            int n_node,n_cost;
            n_node = r_edges[cur][i].node;
            n_cost = r_edges[cur][i].cost + cost;
            if(n_cost < dist2[n_node] ){
                dist2[n_node] = n_cost;
                pq.push({n_cost,n_node});
            }
        }
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dist1[i]+dist2[i]);
    }
    cout << ans;
    return 0;
}

/*
 n개의 숫자로 구분된 각각의 마을에 1명의 학생 살고 있다
 n명의 학생이 x번 마을에 모여서 파티를 벌인다
 m개의 단방향 도로들이 있고
 i번째 길을 지남
 Ti 의 시간 소비
 
 n명의 학생들 중 가장 많은 시간을 소비하는 학생을 구하여라... 훔...
 다익스트라??
 */

