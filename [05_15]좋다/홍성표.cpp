#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
vector<int> input_arr;
vector<pair<int, int>> arr;

void input_data(){
  cin >> N;
  input_arr.resize(N);

  for(int i = 0; i < N; i++) 
    cin >> input_arr[i];

  sort(input_arr.begin(), input_arr.end());

  for(int i = 0; i < N; i++){
    if(arr.empty()){
      arr.push_back({input_arr[i], 1});
      continue;
    }
    if(arr.back().first == input_arr[i]){
      arr.back().second++;
    } else {
      arr.push_back({input_arr[i], 1});
    }
  }

  // for(int i = 0; i < arr.size(); i++)
  //   cout << arr[i].first << " " << arr[i].second << "\n";
}

void calculate_cnt(int idx){
  int target = arr[idx].first;
  int left = 0;
  int right = arr.size() - 1;

  while(left <= right){
    if(arr[left].first + arr[right].first < target)
      left++;
    else if(arr[left].first + arr[right].first > target)
      right--;
    else {
      // cout << "idx: " << arr[idx].first << " left: " << arr[left].first << " right: " << arr[right].first << "\n";
      if(left == right) {
        if(arr[left].first == target) {
          if(arr[left].second >= 3) {
            cnt += arr[idx].second;
            break;
          }
        } else{
          if(arr[left].second >= 2){
            cnt += arr[idx].second;
            break;
          }
        }
      } else if (left == idx) {
        if(arr[left].second >= 2){
          cnt += arr[idx].second;
          break;
        }
      } else if (right == idx) {
        if(arr[right].second >= 2){
          cnt += arr[idx].second;
          break;
        }
      } else {
        cnt += arr[idx].second;
        break;
      }
      left++;
    }
  }
}

void solution(){
  for(int i = 0; i < arr.size(); i++)
    calculate_cnt(i);

  cout << cnt;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  input_data();
  solution();
  
  return 0;
}