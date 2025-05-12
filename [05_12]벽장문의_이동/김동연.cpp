#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int>  wall;
int min_move = 21e8;

void dfs(int idx, int open1, int open2, int move_cnt) {
    if (idx == wall.size()) {
        min_move = min(min_move, move_cnt);
        return;
    }

    int target = wall[idx];
    // 현재 target 벽장을 open1 또는 open2로 열 수 있는 경우 2가지
    // open1을 target으로 이동
    dfs(idx + 1, target, open2, move_cnt + abs(open1 - target));
    // open2를 target으로 이동
    dfs(idx + 1, open1, target, move_cnt + abs(open2 - target));
}

int main() {
    cin >> n;

    int d1, d2;
    cin >> d1 >> d2;

    int t;
    cin >> t;
    wall.resize(t);
    for (int i = 0; i < t; i++) {
        cin >> wall[i];
    }

    dfs(0, d1, d2, 0);

    cout << min_move << "\n";

    return 0;
}
