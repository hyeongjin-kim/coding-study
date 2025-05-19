#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int prev_max[3] = {0}, curr_max[3] = {0};
    int prev_min[3] = {0}, curr_min[3] = {0};

    for (int idx = 0; idx < N; idx++) {
        int left, center, right;
        cin >> left >> center >> right;

        if (idx == 0) {
            prev_max[0] = prev_min[0] = left;
            prev_max[1] = prev_min[1] = center;
            prev_max[2] = prev_min[2] = right;
        } else {
            curr_max[0] = max(prev_max[0], prev_max[1]) + left;
            curr_max[1] = max({prev_max[0], prev_max[1], prev_max[2]}) + center;
            curr_max[2] = max(prev_max[1], prev_max[2]) + right;

            curr_min[0] = min(prev_min[0], prev_min[1]) + left;
            curr_min[1] = min({prev_min[0], prev_min[1], prev_min[2]}) + center;
            curr_min[2] = min(prev_min[1], prev_min[2]) + right;

            for (int jdx = 0; jdx < 3; jdx++) {
                prev_max[jdx] = curr_max[jdx];
                prev_min[jdx] = curr_min[jdx];
            }
        }
    }

    int max_val = max({prev_max[0], prev_max[1], prev_max[2]});
    int min_val = min({prev_min[0], prev_min[1], prev_min[2]});

    cout << max_val << " " << min_val << '\n';

    return 0;
}
