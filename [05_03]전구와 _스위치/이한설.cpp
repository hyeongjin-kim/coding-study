#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;

int switch(const string& s, const string& t, bool first) {
    int score = first; // true 면 1부터 false면 0부터
    vector<bool> cur(n), tgt(n);
    for (int i = 0; i < N; ++i) {
        cur[i] = (s[i] == '1');
        tgt[i] = (t[i] == '1');
    }
    if (first) cur[0] = !cur[0], cur[1] = !cur[1];
  
    for (int idx = 0; idx < N; idx++) {
        if (cur[idx] != tgt[idx]) {
            if (idx + 2 < N)
                for (int jdx = idx; jdx < idx + 3; jdx++) cur[jdx] = !cur[jdx];
            else if (idx + 1 < N)
                cur[idx] = !cur[idx], cur[idx + 1] = !cur[idx + 1];
            score++;
        }
    }
  
    return cur == tgt ? score : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> N >> s >> t;

    int a = switch(s, t, false);
    int b = switch(s, t, true);
    int ans;
  
    if (a < 0 && b < 0) ans = -1;
    else if (a < 0) ans = b;
    else if (b < 0) ans = a;
    else ans = min(a, b);

    cout << ans;
    return 0;
}
