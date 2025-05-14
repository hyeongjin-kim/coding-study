#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

struct Pipe {
    int x1, y1, x2, y2;
};

bool in_bounds(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int idx = 0; idx < N; idx++)
        for (int jdx = 0; jdx < N; jdx++)
            cin >> board[idx][jdx];

    queue<Pipe> q;
    q.push({ 0, 0, 0, 1 });

    long long paths = 0;
    int head = 0;


    while (!q.empty()) {
        auto cur = q.front();
        int x1 = cur.x1, y1 = cur.y1;
        int x2 = cur.x2, y2 = cur.y2;
        q.pop();

        if (x2 == N - 1 && y2 == N - 1) {
            paths++;
            continue;
        }


        if (x1 == x2) {

            if (in_bounds(x2, y2 + 1) && board[x2][y2 + 1] == 0)
                q.push({ x2, y2, x2, y2 + 1 });

            if (in_bounds(x2 + 1, y2 + 1) && board[x2][y2 + 1] == 0 && board[x2 + 1][y2] == 0 && board[x2 + 1][y2 + 1] == 0)
                q.push({ x2, y2, x2 + 1, y2 + 1 });
        }

        else if (y1 == y2) {

            if (in_bounds(x2 + 1, y2) && board[x2 + 1][y2] == 0)
                q.push({ x2, y2, x2 + 1, y2 });

            if (in_bounds(x2 + 1, y2 + 1) && board[x2][y2 + 1] == 0 && board[x2 + 1][y2] == 0 && board[x2 + 1][y2 + 1] == 0)
                q.push({ x2, y2, x2 + 1, y2 + 1 });
        }

        else {

            if (in_bounds(x2, y2 + 1) && board[x2][y2 + 1] == 0)
                q.push({ x2, y2, x2, y2 + 1 });

            if (in_bounds(x2 + 1, y2) && board[x2 + 1][y2] == 0)
                q.push({ x2, y2, x2 + 1, y2 });

            if (in_bounds(x2 + 1, y2 + 1) && board[x2][y2 + 1] == 0 && board[x2 + 1][y2] == 0 && board[x2 + 1][y2 + 1] == 0)
                q.push({ x2, y2, x2 + 1, y2 + 1 });
        }
    }

    cout << paths << "\n";
    return 0;
}
