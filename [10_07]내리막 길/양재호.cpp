#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int y;
    int x;
    int cost;
};
int arr[505][505];
long long dp[505][505];

int main() {
    int n, m;
    cin >> n >> m;

    vector<node> num;
    num.reserve(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j] = 0;
            num.push_back({ i, j, arr[i][j] });
        }
    }

    sort(num.begin(), num.end(), [](const node& a, const node& b) {
        if (a.cost != b.cost) return a.cost > b.cost;
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
        });

    dp[0][0] = 1;
    int ydir[] = { -1, 1 ,0, 0 };
    int xdir[] = { 0, 0, -1, 1 };

    for (int i = 0; i < num.size(); i++) {
        int y = num[i].y;
        int x = num[i].x;
        if (dp[y][x] == 0) continue;

        for (int j = 0; j < 4; j++) {
            int ny = y + ydir[j];
            int nx = x + xdir[j];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] < arr[y][x]) {
                dp[ny][nx] += dp[y][x];
            }
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}
