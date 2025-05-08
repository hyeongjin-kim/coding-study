#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> crane(N);
    for (int idx = 0; idx < N; idx++) {
        cin >> crane[idx];
    }

    int M;
    cin >> M;
    map<int, int> boxCount;
    for (int idx = 0; idx < M; idx++) {
        int w;  
        cin >> w;
        boxCount[w]++;
    }

    sort(crane.begin(), crane.end(), greater<int>());

    if (crane[0] < boxCount.rbegin()->first) {
        cout << -1;
        return 0;
    }

    int time = 0;
    while (!boxCount.empty()) {
        for (int c : crane) {
            auto it = boxCount.upper_bound(c);
            if (it == boxCount.begin()) continue;
            --it;

            int weight = (*it).first;

            if (--boxCount[weight] == 0) {
                boxCount.erase(weight);
            }

            if (boxCount.empty()) break;
        }
        time++;
    }

    cout << time;
    return 0;
}
