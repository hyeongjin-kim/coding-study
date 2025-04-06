#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

struct STEP {
    int step, remainBeer, remainDist, x, y;
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int n;
        cin >> n;
        int sx, sy;
        cin >> sx >> sy;
        queue<STEP> pq;
        int convs[101][3];
        pq.push({ 0, 20, 0, sx, sy });
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            convs[i][0] = x;
            convs[i][1] = y;
            convs[i][2] = 0;
        }
        int tx, ty;
        bool flag = false;
        cin >> tx >> ty;
        convs[0][0] = tx;
        convs[0][1] = ty;
        convs[0][2] = 0;
        while (!pq.empty()) {
            STEP cur = pq.front();
            pq.pop();

            if (cur.x == tx && cur.y == ty) {
                flag = true;
                break;
            }
            for (int i = 0; i <= n; i++) {
                if (convs[i][2])
                    continue;

                int dist = abs(cur.x - convs[i][0]) + abs(cur.y - convs[i][1]);
                if (dist <= 50 * cur.remainBeer + cur.remainDist) { //갈수있음
                    convs[i][2] = 1;
                    int tmp = (50 * cur.remainBeer + cur.remainDist - dist) % 50;
                    pq.push({ cur.step + 1, 20, tmp, convs[i][0], convs[i][1] });
                }
            }

        }
        if (flag)
            cout << "happy\n";
        else
            cout << "sad\n";

    }
    return 0;
}
