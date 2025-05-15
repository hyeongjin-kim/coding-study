#include <iostream>
#include <algorithm>
using namespace std;

int arr[2000];
int N;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    
    // 숫자 정렬
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        int target = arr[i];
        int left = 0, right = N - 1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            //두 수를 조합해서 이 수를 만들 수 있는지 탐색
            int sum = arr[left] + arr[right];
            if (sum == target) {
                ans++;
                break;
            }
            //작으면 왼쪽을 한칸 오른쪽으로 옮기고
            else if (sum < target) left++;
            //크면 오른쪽을 한칸 왼쪽으로 옮김
            else right--;
        }
    }

    cout << ans;
    return 0;
}