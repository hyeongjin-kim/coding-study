#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int dijkstra(int start, int end, const vector<vector<pair<int,int>>>& graph) {
    int n = graph.size() - 1;
    const int INF = 1000000;
    vector<int> dist(n+1, INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;      
        if (u == end) return d;             
        
        for (auto& [v, w] : graph[u]) {
            int nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist[end];
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<pair<int,int>>> graph(N+1);
    for (int idx = 0; idx < M; idx++) {
        int A, B, T;
        cin >> A >> B >> T;
        graph[A].push_back({B, T});
    }

    int answer = 0;
    for (int idx = 1; idx <= N; idx++) {
        int toX   = dijkstra(idx, X, graph);
        int fromX = dijkstra(X, idx, graph);
        answer = max(answer, toX + fromX);
    }

    cout << answer << "\n";
    return 0;
}
