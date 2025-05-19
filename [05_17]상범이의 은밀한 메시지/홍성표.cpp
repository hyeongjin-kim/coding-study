#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string encrypt_str, str_part;
vector<int> key;

void input_data() {
  cin >> encrypt_str;
  cin >> str_part;
}

// return -1 : no cycle
// return n : cycle length
int check_cycle(const vector<int>& key_arr) {
  int n = key_arr.size();
  for (int len = n / 2; len >= 1; len--) {
    bool is_cycle = true;
    for (int i = 0; i < n; i++) {
      if (key_arr[i] != key_arr[i % len]) {
        is_cycle = false;
        break;
      }
    }
    if (is_cycle) return len;
  }
  return -1;
}


bool is_valid_key(int idx) {
  vector<int> key_arr;

  for(int i = 0; i < str_part.size(); i++) {
    int temp = encrypt_str[idx + i] - str_part[i];
    if(temp < 0) temp += 26;
    key_arr.push_back(temp);
  }
  int result = check_cycle(key_arr);

  if(result == -1) return false;

  int st_idx = (result - (idx % result));

  for(int i = 0; i < result; i++) {
    key.push_back((key_arr[(st_idx + i) % result]));
  }
  return true;
}

void print_original_str() {
  int idx = 0;
  char ch;
  for(int i = 0; i < encrypt_str.size(); i++) {
    ch = encrypt_str[i] - key[idx];
    
    if(ch < 'a') ch += 26;
    
    cout << ch;
    idx = (idx + 1) % key.size();
  }
}

void solution() {
  for(int i = 0; i <= encrypt_str.size() - str_part.size(); i++){
    if(is_valid_key(i)) break;
  }

  
  print_original_str();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input_data();
  solution();

  return 0;
}