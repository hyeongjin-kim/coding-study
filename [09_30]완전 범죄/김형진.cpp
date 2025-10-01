#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int M , N, result;


//어떻게 정렬하느냐가 속도를 좌우함
// a가 높은 쪽을 먼저 시도하면 가지치기가 빨리 발생해서 더 빨라짐
bool cmp(const vector<int> a, const vector<int> b) {
    if(a[1] != b[1]) return a[1] > b[1];
    return a[0] > b[0];

}

void backtrack(vector<vector<int>> & info, int idx, int a, int b){
    if(idx == info.size()){
        result = min(result, a);
        return;
    }
    if(b  + info[idx][1] < M ){
        backtrack(info, idx + 1, a, b + info[idx][1]);
    }
    if(a + info[idx][0] < N  and a < result){
        backtrack(info, idx + 1, a + info[idx][0], b);
    }
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    N = n;
    M = m;
    result = n + 1;
    
    sort(info.begin(), info.end(), cmp);
    
    backtrack(info, 0, 0, 0);
    
    answer = result;
    
    if(result == n + 1) return -1;
    
    return answer;
}
