#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, a, b;
vector<int> arr;

void input_data() {
  cin >> N;
  arr.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
}

bool is_all_same() {
  for(int i = 0; i < N; ++i) {
    if(arr[i] != arr[0])
      return false;
  }
  return true;
}

void solution() {
  if(N == 1) {
    cout << "A";
    return;
  } else if(N == 2) {
    if(arr[0] == arr[1])
      cout << arr[0];
    else
      cout << "A";
    return;
  }
  
  int right = arr[2] - arr[1];
  int left = arr[1] - arr[0];

  int a;

  if(left == 0) {
    if(is_all_same())
      cout << arr[0];
    else
      cout << "B";
    return;
  }
  else if (right % left != 0) {
    cout << "B";
    return;
  } else {
    a = right / left;
  }
  int b = arr[1] - arr[0] * a;

  for(int i = 0; i < N - 1; ++i) {
    if(arr[i] * a + b != arr[i + 1]) {
      cout << "B";
      return;
    }
  }
  cout << arr[N - 1] * a + b;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input_data();
  solution();
  return 0;
}