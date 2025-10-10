#include <iostream>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { -1,0,1,0 };
int N;
int board[500][500];
int sx;
int sy;
int sand_var[10];
int ans;
bool in_range(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    sx = N / 2;
    sy = N / 2;
}

void set_sand_ratio(int dir) {

    
    //모래 정리하기

    int dir_p1 = (dir + 1 +4) % 4;
    int dir_m1 = (dir - 1 +4) % 4;
    int dir_p2 = (dir + 2 +4) % 4;
    int to_x = sx + dx[dir];
    int to_y = sy + dy[dir];

    int temp_sand = board[to_x][to_y];

    sand_var[0] = temp_sand * 0.07;
    sand_var[1] = temp_sand * 0.07;

    sand_var[2] = temp_sand * 0.02;
    sand_var[3] = temp_sand * 0.02;

    sand_var[4] = temp_sand * 0.1;
    sand_var[5] = temp_sand * 0.1;

    sand_var[6] = temp_sand * 0.01;
    sand_var[7] = temp_sand * 0.01;

    sand_var[8] = temp_sand * 0.05;
    int t = 0;
    for (int i = 0; i < 9; i++) {
        t += sand_var[i];
    }
    sand_var[9] = board[to_x][to_y] - t;

    if (in_range(to_x + dx[dir_p1], to_y + dy[dir_p1])) {
        board[to_x + dx[dir_p1]][to_y + dy[dir_p1]] += sand_var[0];
    }
    else ans += sand_var[0];

    if (in_range(to_x + dx[dir_m1], to_y + dy[dir_m1])) {
        board[to_x + dx[dir_m1]][to_y + dy[dir_m1]] += sand_var[1];
    }
    else ans += sand_var[1];

    if (in_range(to_x + dx[dir_p1] * 2, to_y + dy[dir_p1] * 2)) {
        board[to_x + dx[dir_p1] * 2][to_y + dy[dir_p1] * 2] += sand_var[2];
    }
    else ans += sand_var[2];

    if (in_range(to_x + dx[dir_m1] * 2, to_y + dy[dir_m1] * 2)) {
        board[to_x + dx[dir_m1] * 2][to_y + dy[dir_m1] * 2] += sand_var[3];
    }
    else ans += sand_var[3];

    if (in_range(to_x + dx[dir_p1] + dx[dir], to_y + dy[dir_p1] + dy[dir])) {

        board[to_x + dx[dir_p1] + dx[dir]][to_y + dy[dir_p1] + dy[dir]] += sand_var[4];
    }
    else ans += sand_var[4];

    if (in_range(to_x + dx[dir_m1] + dx[dir], to_y + dy[dir_m1] + dy[dir])) {
        board[to_x + dx[dir_m1] + dx[dir]][to_y + dy[dir_m1] + dy[dir]] += sand_var[5];
    }
    else ans += sand_var[5];

    if (in_range(to_x + dx[dir_p1] + dx[dir_p2], to_y + dy[dir_p1] + dy[dir_p2])) {
        board[to_x + dx[dir_p1] + dx[dir_p2]][to_y + dy[dir_p1] + dy[dir_p2]] += sand_var[6];
    }
    else ans += sand_var[6];
    
    if (in_range(to_x + dx[dir_m1] + dx[dir_p2], to_y + dy[dir_m1] + dy[dir_p2])) {
        board[to_x + dx[dir_m1] + dx[dir_p2]][to_y + dy[dir_m1] + dy[dir_p2]] += sand_var[7];
    }
    else ans += sand_var[7];

    if (in_range(to_x + dx[dir] * 2, to_y + dy[dir] * 2)) {
        board[to_x + dx[dir] * 2][to_y + dy[dir] * 2] += sand_var[8];
    }
    else ans += sand_var[8];

    if (in_range(to_x + dx[dir], to_y + dy[dir])) {
        board[to_x + dx[dir]][to_y + dy[dir]] += sand_var[9];
    }
    else ans += sand_var[9];

}

void process_move(int dir) {

    //모래 정리하기
    set_sand_ratio(dir);
    
    //이동하기
    sx = sx + dx[dir];
    sy = sy + dy[dir];
}
void solution() {
    int dir = 0;

    for (int length = 1; length < N; length++) {

        if (length < N - 1) {
            for (int r = 0; r < 2; r++) {
                for (int l = 0; l < length; l++) {
                    process_move(dir);
                }
                dir = (dir+1)%4;
            }
        }
        else {
            for (int r = 0; r < 3; r++) {
                for (int l = 0; l < length; l++) {
                    process_move(dir);
                }
                dir = (dir + 1) % 4;
            }
        }

    }
}
void output() {
    cout << ans;
}

int main() {

    input();
    solution();
    output();
    return 0;
}
