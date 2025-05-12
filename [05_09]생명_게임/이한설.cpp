#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, T;
    cin >> N >> M >> T;
    int K, a, b;
    cin >> K >> a >> b;

    vector<vector<int>> board(N, vector<int>(M));
    for (int idx = 0; idx < N; idx++) {
        string s; cin >> s;
        for (int jdx = 0; jdx < M; jdx++) {
            board[idx][jdx] = (s[jdx] == '*');
        }
    }

    vector<vector<int>> ps(N+1, vector<int>(M+1));
    vector<vector<int>> nextb(N, vector<int>(M));

    while (T-- > 0) {
        for (int idx = 0; idx <= N; idx++) {
            fill(ps[idx].begin(), ps[idx].end(), 0);
        }
        for (int idx = 0; idx < N; idx++) {
            int row_sum = 0;
            for (int jdx = 0; jdx < M; j++) {
                row_sum += board[idx][jdx];
                ps[idx+1][jdx+1] = ps[idx][jdx+1] + row_sum;
            }
        }

        for (int idx = 0; idx < N; ++idx) {
            for (int jdx = 0; jdx < M; ++jdx) {
                int r1 = max(0, idx - K);
                int c1 = max(0, jdx - K);
                int r2 = min(N-1, idx + K);
                int c2 = min(M-1, jdx + K);
                
                int sum = ps[r2+1][c2+1]
                        - ps[r1][c2+1]
                        - ps[r2+1][c1]
                        + ps[r1][c1]
                        - board[idx][jdx];  // 자기 자신 제외

                if (board[idx][jdx]) {
                    nextb[idx][jdx] = (a <= sum && sum <= b);
                } else {
                    nextb[idx][jdx] = (a < sum && sum <= b);
                }
            }
        }
        board.swap(nextb);
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << (board[i][j] ? '*' : '.');
        }
        cout << '\n';
    }
    return 0;
}
