#include <iostream>
#include <vector>
using namespace std;

int parent[201];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int idx = 1; idx <= N; idx++) {
        parent[idx] = idx;
    }

    for (int idx = 1; idx <= N; idx++) {
        for (int jdx = 1; jdx <= N; jdx++) {
            int x;
            cin >> x;
            if (x == 1) {
                Union(idx, jdx);
            }
        }
    }

    vector<int> graph(M);
    for (int idx = 0; idx < M; idx++) {
        cin >> graph[idx];
    }

    int start = find(graph[0]);
    for (int idx = 1; idx < M; idx++) {
        if (find(graph[idx]) != start) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
