#include <iostream>
#include <vector>

using namespace std;

int N, cnt = 0;
vector<bool> columns, cplusr, cminusr;

void nqueen(int idx) {
    if (idx == N) {
        cnt++;
        return;
    }

    for (int jdx = 0; jdx < N; jdx++) {
        if (columns[jdx] || cplusr[idx + jdx] || cminusr[jdx - idx + N - 1])
            continue;

        columns[jdx] = cplusr[idx + jdx] = cminusr[jdx - idx + N - 1] = true;
        nqueen(idx + 1);
        columns[jdx] = cplusr[idx + jdx] = cminusr[jdx - idx + N - 1] = false;
    }
}

int main() {
    cin >> N;
    columns.resize(N, false);
    cplusr.resize(2 * N - 1, false);
    cminusr.resize(2 * N - 1, false);

    nqueen(0);
    cout << cnt << endl;

    return 0;
}
