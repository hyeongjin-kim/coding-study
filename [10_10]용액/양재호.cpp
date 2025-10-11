#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int arr[100010];
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0;
    int right = n -1;
    int min = 2100000000;
    int a = arr[left], b = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < min) {
            min = abs(sum);
            a = arr[left];
            b = arr[right];

        }

        if (sum < 0) left++;
        else right--;
    }

    cout << a << " " << b;

    return 0;
}
