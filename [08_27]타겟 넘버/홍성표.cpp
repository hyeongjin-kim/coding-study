#include <iostream>
#include <string>
#include <vector>

using namespace std;

int target, cnt;

vector<int> arr;

void copy_arr(vector<int> &src) {
    for(int i = 0; i < src.size(); i++)
        arr.push_back(src[i]);
}

void calculate_data(int cur_idx, int cur_val){
    if(cur_idx >= arr.size()){
        if(cur_val == target)
            cnt++;
        return;
    }
    
    calculate_data(cur_idx + 1, cur_val + arr[cur_idx]);
    calculate_data(cur_idx + 1, cur_val - arr[cur_idx]);
}

int solution(vector<int> numbers, int t) {
    
    target = t;
    copy_arr(numbers);
    
    calculate_data(0, 0);
    
    return cnt;
}