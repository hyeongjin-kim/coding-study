#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int s;
    int l;
};

bool cmp(node a, node b) {
    if (a.l != b.l) return a.l < b.l;
    return a.s < b.s;
}
node arr[105];
int dp[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= b) arr[i] = { a, b };
        else arr[i] = { b, a };
    }

    sort(arr, arr + n, cmp);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j].l <= arr[i].l && arr[j].s <= arr[i].s) {
                if (max < dp[j]) max = dp[j];
            }
        }

        dp[i] = max + 1;
        if (ans < dp[i]) ans = dp[i];
    }

    cout << ans;

    return 0;
}
