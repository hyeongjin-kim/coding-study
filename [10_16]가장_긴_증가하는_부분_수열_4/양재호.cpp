#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n;
int arr[1010];
int visited[1010];
int back_arr[1010];
vector<int> num;
struct node {
    int num;
    int idx;
    int cost;
    bool operator<(node right) const {
        return cost < right.cost;
    }
};
priority_queue<node> pq;

void bfs() {

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (visited[now.idx] > now.cost) continue;

        for (int i = now.idx + 1; i < n; i++) {
            int nextnum = arr[i];
            int nextidx = i;
            int nextcost = now.cost + 1;
            if (nextnum <= now.num) continue;
            if (visited[nextidx] >= nextcost) continue;
            visited[nextidx] = nextcost;
            back_arr[nextidx] = now.idx;
            pq.push({ nextnum, nextidx, nextcost });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    fill(visited, visited + n + 1, 0);
    memset(back_arr, -1, sizeof(arr));
    int a = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] <= a) {
            a = arr[i];
            visited[i] = 1;
            pq.push({ arr[i], i, 1 });
        }
    }

    bfs();

    int max = 0;
    int max_idx;

    for (int i = 0; i < n; i++) {
        if (visited[i] > max) {
            max = visited[i];
            max_idx = i;
        }
    }
    
    for (int i = max_idx; i != -1; i = back_arr[i]) {
        num.push_back(arr[i]);
    }

    cout << max << "\n";

    for (int i = num.size() - 1; i >= 0; i--) {
        cout << num[i] << " ";
    }

    return 0;
}
