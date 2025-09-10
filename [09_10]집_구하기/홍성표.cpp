#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 4e18;
int V, E;
long long min_dist = INF;
int M, m_dist, S, s_dist;
vector<unordered_map<int, int>> graph; // (to, weight)
vector<long long> m_dijkstra;
vector<long long> s_dijkstra;
vector<int> node, m_node, s_node;
bool debug = false;

void input_data(){
  cin >> V >> E;

  int u, v, w;

  graph.resize(V + 1);

  for(int i = 0; i < E; i++) {
    cin >> u >> v >> w;

    // 작은 값으로 최신화.
    if(graph[u].find(v) == graph[u].end()) {
      graph[u][v] = w;
      graph[v][u] = w;
    }
    else {
      graph[u][v] = min(graph[u][v], w);
      graph[v][u] = min(graph[v][u], w);
    }
  }

  node.resize(V + 1, 0);
  // 맥도날드 정보 저장
  cin >> M >> m_dist;
  m_node.resize(M);
  for(int i = 0; i < M; i++) {
    cin >> u;
    node[u] = 1; // 맥도날드
    m_node[i] = u;
  }

  // 스타벅스 정보 저장
  cin >> S >> s_dist;
  s_node.resize(S);
  for(int i = 0; i < S; i++) {
    cin >> u;
    node[u] = 2; // 스타벅스
    s_node[i] = u;
  }
}

vector<long long> dijkstra(vector<int> &src, int limit) {
  vector<long long> dist(V + 1, INF);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // (dist, node)

  for(int s : src) {
    dist[s] = 0;
    pq.push({0, s});
  }

  while(!pq.empty()) {
    pair<long long, int> cur = pq.top();  // (dist, node)
    pq.pop();

    if(cur.first != dist[cur.second]) continue;
    if(cur.first > limit) continue;

    for(auto next : graph[cur.second]) { // (to, weight)
      if(cur.first + next.second < dist[next.first] && cur.first + next.second <= limit) {
        dist[next.first] = cur.first + next.second;
        pq.push({dist[next.first], next.first});
      }
    }
  }

  return dist;
}

void solution() {
  m_dijkstra = dijkstra(m_node, m_dist);
  s_dijkstra = dijkstra(s_node, s_dist);

  for(int i = 1; i <= V; i++) {
    if(node[i] != 0) continue; // 집이 아닌 곳
    if(m_dijkstra[i] == INF || s_dijkstra[i] == INF) continue; // 둘 중 하나라도 갈 수 없는 곳

    min_dist = min(min_dist, m_dijkstra[i] + s_dijkstra[i]);
  }
}

void print_answer() {
  if(min_dist == INF) cout << -1;
  else cout << min_dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input_data();
  solution();
  print_answer();

  return 0;
}