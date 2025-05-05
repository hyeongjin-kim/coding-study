#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

unordered_map<int, vector<vector<int>>> graph;

int dijkstra(int start, int end, vector<int> visited) {
    visited[start] = 0;
    
    priority_queue<int, vector<int>, greater<int>> time_pq;
    queue<pair<int,int>> q;
    q.push({start, 0});

    while (!q.empty()) {
        int sx   = q.front().first;
        int time = q.front().second;
        q.pop();

        if (sx == end) {
            time_pq.push(time);
        }

        for (auto& info : graph[sx]) {
            int nx        = info[0];
            int next_time = time + info[1];
            if (visited[nx] > next_time) {
                visited[nx] = next_time;
                q.push({nx, next_time});
            }
        }
    }

    return time_pq.empty() ? -1 : time_pq.top();
}

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> total_idx_time;
    for (int idx = 0; idx < M; idx++) {
        int A, B, T;
        cin >> A >> B >> T;
        graph[A].push_back({B, T});
    }
    for (int idx = 1; idx <= N; idx++) {
        vector<int> visited(N+1, 10000000);
        int toX   = dijkstra(idx, X, visited);
        int fromX = dijkstra(X, idx, visited);
        total_idx_time.push_back(toX + fromX);
    }

    sort(total_idx_time.begin(), total_idx_time.end());
    cout << total_idx_time[N-1];
    return 0;
}
