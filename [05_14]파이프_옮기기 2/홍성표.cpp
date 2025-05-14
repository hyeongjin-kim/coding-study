#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
// 0: -, 1 : \, 2 : |
// value : cnt, -1 : 벽.
vector<vector<vector<long long>>> dp; 

void input_data() {
  cin >> N;
  dp.resize(3, vector<vector<long long>>(N, vector<long long>(N, 0)));

  int map;
  for(int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map;
      if(map == 1) {
        for(int k = 0; k < 3; k++)
          dp[k][i][j] = -1;
      }
    }
  }

  // start point
  if(dp[0][0][1] != -1)
    dp[0][0][1] = 1;
}

void get_dp(int i, int j){
  // 벽인 경우 return
  if(dp[0][i][j] == -1)
  return;
  
  int num[3] = {0, 0, 0};
  if(j-1 >= 0) {
    num[0] = dp[0][i][j-1] != -1 ? dp[0][i][j-1] : 0;
    num[1] = dp[1][i][j-1] != -1 ? dp[1][i][j-1] : 0;
    dp[0][i][j] = num[0] + num[1];
  }
  
  if(i-1 >= 0 && j-1 >= 0) {
    // 공간 처리.
    if(dp[0][i-1][j] != -1 && dp[0][i][j-1] != -1){
      num[0] = dp[0][i-1][j-1] != -1 ? dp[0][i-1][j-1] : 0;
      num[1] = dp[1][i-1][j-1] != -1 ? dp[1][i-1][j-1] : 0;
      num[2] = dp[2][i-1][j-1] != -1 ? dp[2][i-1][j-1] : 0;
      dp[1][i][j] = num[0] + num[1] + num[2];
    }
  }
  
  if(i-1 >= 0) {
    num[0] = dp[1][i-1][j] != -1 ? dp[1][i-1][j] : 0;
    num[1] = dp[2][i-1][j] != -1 ? dp[2][i-1][j] : 0;
    dp[2][i][j] = num[0] + num[1];
  }
}

void print_solution() {
  long long result = 0;
  for(int i = 0; i < 3; i++) {
    if(dp[i][N-1][N-1] != -1)
      result += dp[i][N-1][N-1];
  }
  cout << result;
}

void solution(){
  for(int sum = 2; sum < 2*N-1; sum++) {
    for(int i = 0; i <= sum; i++){
      int j = sum - i;
      if(i >= N || j >= N)
      continue;
      // cout << "i: " << i << " j: " << j << endl;
      get_dp(i, j);
      // cout << "dp[0][" << i << "][" << j << "] : " << dp[0][i][j] << " "
      //      << "dp[1][" << i << "][" << j << "] : " << dp[1][i][j] << " "
      //      << "dp[2][" << i << "][" << j << "] : " << dp[2][i][j] << endl;
    }
    // cout << "------------------\n";
  }

  print_solution();
}

int main(){
  input_data();
  solution();

  return 0;
}

