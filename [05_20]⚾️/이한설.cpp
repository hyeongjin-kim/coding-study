#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> board;

// 주어진 타순으로 N 이닝을 시뮬레이션하고 득점 리턴
int game(const vector<int>& lineup) {
    int score = 0;
    int batter_idx = 0;  // 다음에 타석에 설 타자 인덱스 (0~8)

    for (int inning = 0; inning < N; ++inning) {
        int outs = 0;
        int bases[3] = { 0, 0, 0 };  // bases[0]=1루, bases[1]=2루, bases[2]=3루

        while (outs < 3) {
            int player = lineup[batter_idx];
            int res = board[inning][player - 1];

            if (res == 0) {
                // 아웃
                ++outs;
            }
            else if (res == 1) {
                // 안타: 모든 주자 1루씩, 타자 1루
                score += bases[2];
                bases[2] = bases[1];
                bases[1] = bases[0];
                bases[0] = 1;
            }
            else if (res == 2) {
                // 2루타: 모든 주자 2루씩, 타자 2루
                score += bases[2] + bases[1];
                bases[2] = bases[0];
                bases[1] = 1;
                bases[0] = 0;
            }
            else if (res == 3) {
                // 3루타: 모든 주자 3루씩, 타자 3루
                score += bases[2] + bases[1] + bases[0];
                bases[2] = 1;
                bases[1] = bases[0] = 0;
            }
            else if (res == 4) {
                // 홈런: 모든 주자 홈인, 타자 홈인
                score += 1 + bases[2] + bases[1] + bases[0];
                bases[0] = bases[1] = bases[2] = 0;
            }

            batter_idx = (batter_idx + 1) % 9;
        }
    }

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    board.assign(N, vector<int>(9));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> board[i][j];

    vector<int> perm;
    for (int p = 2; p <= 9; ++p)
        perm.push_back(p);

    int maxScore = 0;

    
    vector<int> lineup(9);
    int i = 0;
    for (int pos = 0; pos < 9; ++pos) {
        if (pos == 3)
            lineup[pos] = 1;      
        else
            lineup[pos] = perm[i++];
        
    maxScore = max(maxScore, game(lineup));
    

    // 나머지 순열들 처리
    while (next_permutation(perm.begin(), perm.end())) {
        vector<int> lineup(9);
        int idx = 0;
        for (int pos = 0; pos < 9; ++pos) {
            if (pos == 3)
                lineup[pos] = 1;
            else
                lineup[pos] = perm[idx++];
        }
        maxScore = max(maxScore, game(lineup));
    }

    cout << maxScore << "\n";
    return 0;
}
