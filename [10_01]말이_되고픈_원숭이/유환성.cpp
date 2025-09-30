#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N, M;
int K;
int ans;

enum obj { ROAD, BLOCK };

int board[205][205];
int visited[205][205];
struct monkey {
    int x;
    int y;
    int jump_cnt;
};

queue<monkey> Q;

int dx_normal[] = { 1,-1,0,0 };
int dy_normal[] = { 0,0,1,-1 };

int dx_knight[] = { -2,-2,2,2,-1,-1,1,1 };
int dy_knight[] = { -1,1,-1,1,2,-2,2,-2 };

bool in_range(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 21e8;
        }
    }
    while (!Q.empty())Q.pop();
}

void input() {

    cin >> K;
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

void solution() {
    Q.push({ 0,0,0 });
    visited[0][0] = 0;
    int size;

    while (!Q.empty()) {

        ans++;
        size = Q.size();

        for (int s = 0; s < size; s++) {

            auto now = Q.front(); Q.pop();

            //원숭이처럼 이동
            for (int dir = 0; dir < 4; dir++) {
                int nx = now.x + dx_normal[dir];
                int ny = now.y + dy_normal[dir];
                int nc = now.jump_cnt;

                if (!in_range(nx, ny))continue;
                if (board[nx][ny] == BLOCK) continue;
                if (visited[nx][ny] <= nc) continue;


                Q.push({ nx, ny, nc });
                visited[nx][ny] = nc;

                if (nx == N - 1 && ny == M - 1) {
                    return;
                }

            }
            
            if (now.jump_cnt == K) continue;
            //나이트처럼 이동
            for (int dir = 0; dir < 8; dir++) {
                int nx = now.x + dx_knight[dir];
                int ny = now.y + dy_knight[dir];
                int nc = now.jump_cnt + 1;

                if (!in_range(nx, ny))continue;
                if (board[nx][ny] == BLOCK) continue;
                if (visited[nx][ny] <= nc) continue;

                Q.push({ nx, ny, nc });
                visited[nx][ny] = nc;

                if (nx == N - 1 && ny == M - 1) {
                    return;
                }
                
            }

        }

    }
    if (N == 1 && M == 1) ans = 0;
    else ans = -1;

}
void output() {
   
    cout << ans;
}

int main() {

    input();
    init();
    solution();
    output();


    return 0;
}
