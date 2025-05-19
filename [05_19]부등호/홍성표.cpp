#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string opt_str, max_str, min_str;

void input_data() {
  cin >> N;
  
  for(int i = 0; i < N; i++){
    string s;
    cin >> s;
   opt_str += s;
  }
}

bool is_valid_sequence(char left, char right, char opt){
  if(opt == '<'){
    if(left > right)
      return false;
  }
  else if(opt == '>'){
    if(left < right)
      return false;
  }
  return true;
}

void solution() {
  for(int i = 0; i <= N; i++) {
    max_str += (char)('9' - i);
    min_str += (char)('0' + i);
  };

  while(true) {
    bool flag = true;
    for(int i = 0; i < N; i++) {
      if(!is_valid_sequence(max_str[i], max_str[i + 1], opt_str[i])) {
        flag = false;
        break;
      }
    }
    if(flag) break;
    prev_permutation(max_str.begin(), max_str.end());
  }

  while(true) {
    bool flag = true;
    for(int i = 0; i < N; i++) {
      if(!is_valid_sequence(min_str[i], min_str[i + 1], opt_str[i])) {
        flag = false;
        break;
      }
    }
    if(flag) break;
    next_permutation(min_str.begin(), min_str.end());
  }

  cout << max_str << "\n" << min_str;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input_data();
  solution();

  return 0;
}