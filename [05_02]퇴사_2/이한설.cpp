#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> need_day(N + 2), money(N + 2);
    for (int idx = 1; idx <= N; idx++) {
        cin >> need_day[idx] >> money[idx];
    }

    vector<int> money_list(N + 2, 0);

    for (int day = 1; day <= N + 1; day++) {

        money_list[day] = max(money_list[day], money_list[day - 1]);
        // 끝나는 날에 이익 반영
        if (day <= N) {
            int finish = day + need_day[day];
            if (finish <= N + 1) {
                money_list[finish] = max(money_list[finish], money_list[day] + money[day]);
            }
        }
    }

    cout << money_list[N + 1] << "\n";
    return 0;
}
