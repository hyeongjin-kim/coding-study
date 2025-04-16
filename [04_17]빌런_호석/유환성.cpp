#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int N, K, P, X;
int ans;

int changeCost[10][10] =
{
    {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
};

void FindNOC(int tF, string S) {
    string TF = to_string(tF);
    if (TF == S) return;
    while (TF.size()<K) {
        TF.insert(TF.begin(), '0');
    }
    while (S.size() < K) {
        S.insert(S.begin(), '0');
    }
    int Reqcost = P;
    for (int i = K - 1; i >= 0; i--) {
        Reqcost -= changeCost[TF[i]-'0'][S[i]-'0'];
        if (Reqcost < 0) return;
    }

    ans++;
    return;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> P >> X;

    string S = to_string(X);

    for (int targetFloor = 1; targetFloor <= N; targetFloor++) {
        FindNOC(targetFloor, S);
    }
    cout << ans;
    return 0;
}
