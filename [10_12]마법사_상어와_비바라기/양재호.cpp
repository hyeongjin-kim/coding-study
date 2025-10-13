#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
int yd[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int xd[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int ydir[] = { -1, -1, 1, 1 };
int xdir[] = { -1, 1, -1, 1 };
struct Cloud {
    int y;
    int x;
};
int arr[55][55];
vector<Cloud> cloud;
vector<Cloud> moved;
vector<Cloud> nextcloud;
bool beforecloud[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    cloud.push_back({ n, 1 });
    cloud.push_back({ n, 2 });
    cloud.push_back({ n - 1, 1 });
    cloud.push_back({ n - 1, 2 });

    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        s = s % n;

        memset(beforecloud, false, sizeof(beforecloud));
        moved.clear();
        int dy = yd[d];
        int dx = xd[d];
        for (int i = 0; i < cloud.size(); i++) {
            int y = cloud[i].y;
            int x = cloud[i].x;

            int ny = ((y - 1 + dy * s) % n + n) % n + 1;
            int nx = ((x - 1 + dx * s) % n + n) % n + 1;
            moved.push_back({ ny, nx });
        }
        cloud.clear();

        for (int i = 0; i < moved.size(); i++) {
            int y = moved[i].y;
            int x = moved[i].x;
            arr[y][x] += 1;
            beforecloud[y][x] = true;
        }

        for (int i = 0; i < moved.size(); i++) {
            int y = moved[i].y;
            int x = moved[i].x;
            int add = 0;
            for (int j = 0; j < 4; j++) {
                int ny = y + ydir[j];
                int nx = x + xdir[j];
                if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
                if (arr[ny][nx] > 0) add++;
            }
            arr[y][x] += add;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (beforecloud[i][j]) continue;
                if (arr[i][j] >= 2) {
                    arr[i][j] -= 2;
                    nextcloud.push_back({ i, j });
                }
            }
        }

        cloud.swap(nextcloud);
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans;

    return 0;
}
