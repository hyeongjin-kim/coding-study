#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
struct node {
    int y;
    int x;
    int cost;
    bool operator < (node right) const {
        return cost > right.cost;
    }
};
int visited[130][130];
int arr[130][130];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

void dijkstra(int y, int x, int num) {
    priority_queue<node> pq;
    pq.push({ y, x, num });
    visited[y][x] = num;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();

        if (visited[now.y][now.x] != -1 && visited[now.y][now.x] < now.cost) continue;

        for (int i = 0; i < 4; i++) {
            int ny = now.y + ydir[i];
            int nx = now.x + xdir[i];
            int nextcost = now.cost + arr[ny][nx];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

            if (visited[ny][nx] != -1 && visited[ny][nx] <= nextcost) continue;
            if (visited[ny][nx] > -1) continue;
            visited[ny][nx] = nextcost;
            pq.push({ ny, nx, nextcost });
        }
    }
}

int main() {
    int t = 1;
    while (cin >> n) {
        if (n == 0) break;
        memset(arr, 0, sizeof(arr));
        memset(visited, -1, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        dijkstra(0, 0, arr[0][0]);

        cout << "Problem " << t << ": " << visited[n - 1][n - 1] << "\n";
        t++;
    }

    return 0;
}
