#include <iostream>
#include <vector>

using namespace std;

int n, r, q;
vector<int> tree[100010];
int visited[100010];
int dp[100010];

int dfs(int num) {
    visited[num] = 1;
    int cnt = 1;
    for (int i = 0; i < tree[num].size(); i++) {
        int next = tree[num][i];
        if (!visited[next]) {
            cnt += dfs(next);
        }
    }
    dp[num] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(r);

    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }

    return 0;
}
