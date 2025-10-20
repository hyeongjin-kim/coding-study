#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x) {
        int len = x * 10000000;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        int left = 0;
        int right = n - 1;
        bool ans = false;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == len) {
                cout << "yes " << arr[left] << " " << arr[right] << "\n";
                ans = true;
                break;
            }

            if (sum > len) right--;
            else left++;
        }

        if (ans) continue;
        else {
            cout << "danger" << "\n";
        }
    }

    return 0;
}
