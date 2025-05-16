#include <iostream>
#include <algorithm>

using namespace std;

int arr[20][20]; // self, nearN, near1, 2, 3, 4
int like[401][4];

int xpos[] = { 0,0,-1,1 };
int ypos[] = { -1,1,0,0 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int l = 0;l < N * N;++l) {
        int curStu;
        cin >> curStu;
        for (int f = 0;f < 4;++f)
            cin >> like[curStu][f];
        int nearVacant = -1;
        int nearLike = -1;
        int curX, curY;
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                if (arr[i][j]) continue;
                int curNearLike = 0;
                int curNearVacant = 0;
                for (int d = 0;d < 4;++d) {
                    int nx = i + xpos[d];
                    int ny = j + ypos[d];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (!arr[nx][ny]) {
                        ++curNearVacant;
                        continue;
                    }
                    int near = arr[nx][ny];
                    for (int f = 0;f < 4;++f) {
                        if (like[curStu][f] == near) {
                            ++curNearLike;
                            break;
                        }
                    }
                }
                if (curNearLike > nearLike || (curNearLike == nearLike && nearVacant < curNearVacant)) {
                    curX = i;
                    curY = j;
                    nearLike = curNearLike;
                    nearVacant = curNearVacant;
                }
            }
        }

        arr[curX][curY] = curStu;
    }

    int curNearLike = 0;
    for (int i = 0;i < N;++i) {
        for (int j = 0;j < N;++j) {
            int cur = 0;
            for (int d = 0;d < 4;++d) {
                int nx = i + xpos[d];
                int ny = j + ypos[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                for (int f = 0;f < 4;++f) {
                    if (like[arr[i][j]][f] == arr[nx][ny]) {
                        ++cur;
                        break;
                    }
                }
            }
            if (cur == 0)
                continue;
            int plus = 1;
            for (int d = 1;d < cur;++d)
                plus *= 10;
            curNearLike += plus;
        }
    }
    cout << curNearLike;
    return 0;
}
