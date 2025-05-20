#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int order[51][10];      // order[이닝][타자]
int inn_order[10];      // 실제 타순 [1~9]
int vis[10];       // DFS에서 사용
int n;                  // 총 이닝 수
int max_score = 0;

void simulate_game() 
{
    int score = 0;
    int cur = 1; // 현재 타자 번호 (1~9)

    for (int inning = 1; inning <= n; inning++) 
    {
        int out_count = 0;
        int base[4] = {}; // 1루, 2루, 3루

        while (out_count < 3) 
        {
            int hitter = inn_order[cur];
            int result = order[inning][hitter];

            cur++;

            if (cur > 9)
            {
                cur = 1;
            }

            if (result == 0) 
            {
                out_count++;
                continue;
            }

            // 타자 진루
            base[0] = 1;
            for (int i = 3; i >= 0; i--) 
            {
                if (base[i] == 0) continue;

                int new_pos = i + result;
                base[i] = 0;

                if (new_pos >= 4) score++;
                else base[new_pos] = true;
            }
        }
    }

    max_score = max(max_score, score);
}

void dfs(int depth) 
{
    if (depth == 10) 
    {
        simulate_game();
        return;
    }

    if (depth == 4) {
        inn_order[4] = 1; // 1번 타자 고정
        dfs(depth + 1);
        return;
    }

    for (int i = 2; i <= 9; i++) 
    {
        if (vis[i] == 0) 
        {
            vis[i] = 1;
            inn_order[depth] = i;
            dfs(depth + 1);
            vis[i] = 0;
        }
    }
}

int main() 
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 9; j++)
            cin >> order[i][j];

    dfs(1); // 1번은 4번 타순 고정

    cout << max_score << '\n';
    return 0;
}
