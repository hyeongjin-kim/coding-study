#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> input_arr(3, 0);
vector<pair<int, int>> prev_dp(3, {0, 0});
vector<pair<int, int>> dp(3, {0, 0});

void solution() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for(int j = 0; j < 3; j++)
      cin >> input_arr[j];
    
    dp[0].first = max(prev_dp[0].first, prev_dp[1].first) + input_arr[0];
    dp[0].second = min(prev_dp[0].second, prev_dp[1].second) + input_arr[0];

    dp[1].first = max({prev_dp[0].first, prev_dp[1].first, prev_dp[2].first}) + input_arr[1];
    dp[1].second = min({prev_dp[0].second, prev_dp[1].second, prev_dp[2].second}) + input_arr[1];

    dp[2].first = max(prev_dp[1].first, prev_dp[2].first) + input_arr[2];
    dp[2].second = min(prev_dp[1].second, prev_dp[2].second) + input_arr[2];

    for(int j = 0; j < 3; j++)
      prev_dp[j] = dp[j];
  }

  int max_result = max({dp[0].first, dp[1].first, dp[2].first});
  int min_result = min({dp[0].second, dp[1].second, dp[2].second});

  cout << max_result << " " << min_result << "\n";
}

int main (){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  solution();

  return 0;
}