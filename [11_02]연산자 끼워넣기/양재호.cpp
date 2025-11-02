#include <iostream>
#include <climits>

using namespace std;

int n;
int num[15];
int ans_min = INT_MAX;
int ans_max = INT_MIN;
int use[4];
int ret;

void dfs(int depth, int idx) {
    if (depth == n - 1) {

        if (ret > ans_max) ans_max = ret;
        if (ret < ans_min) ans_min = ret;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (use[i] == 0) continue;
        else {
            use[i]--;
            int backup = ret;
            if (i == 0) ret += num[depth + 1];
            else if (i == 1) ret -= num[depth + 1];
            else if (i == 2) ret *= num[depth + 1];
            else ret /= num[depth + 1];
            dfs(depth + 1, i);

            ret = backup;
            use[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> use[i];
    }
    ret = num[0];
    dfs(0, -1);

    cout << ans_max << "\n" << ans_min;

    return 0;
}
