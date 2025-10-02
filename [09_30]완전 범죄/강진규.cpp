#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int sack[121][41];

int solution(vector<vector<int>> info, int n, int m) {
    for (int i = 0; i <= m; ++i) {
        sack[i][0] = (i <= info[0][1] ? info[0][0] : 0);
    }

    for (int j = 1; j < info.size(); ++j) {
        int curA = info[j][0];
        int curB = info[j][1];
        sack[0][j] = sack[0][j - 1] + curA;
        for (int i = 1; i <= m; ++i) {
            int curmin = 100000;
            if (i - curB - 1 >= 0) {
                curmin = min(curmin, sack[i - curB][j - 1]);
            }
            curmin = min(curmin, sack[i][j - 1] + curA);
            sack[i][j] = curmin;
        }
    }

    return (sack[m][info.size() - 1] < n ? sack[m][info.size() - 1] : -1);
}
