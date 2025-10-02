#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = n + 1;
    
    int a_row_b_col[121][121] = {};

    if(info[0][0] < n){
        a_row_b_col[info[0][0]][0] = 1;
    }
    if(info[0][1] < m){
        a_row_b_col[0][info[0][1]] = 1;
    }

    for(int idx = 1; idx < info.size(); idx++){
       int a_trail = info[idx][0], b_trail = info[idx][1];
        
        for(int r = 0; r <= n; r++){
            for(int c = 0; c <= m; c++){
                if(a_row_b_col[r][c] != idx) continue;
                 if(r + a_trail < n){
                    a_row_b_col[r + a_trail][c] 
                        = max(a_row_b_col[r + a_trail][c], a_row_b_col[r][c] + 1);
                }
                if(c + b_trail < m){
                    a_row_b_col[r][c + b_trail] 
                        = max(a_row_b_col[r][c + b_trail], a_row_b_col[r][c] + 1);
                }
            }
        }
    }
    
    for(int i = 0; i <=n; i++){
        for(int j = 0; j <= m; j++ ){
            if(a_row_b_col[i][j] == info.size()){
                answer = min(answer, i);
            }
        }
    }
    
    if(answer == n + 1) answer = -1;
    return answer;
}
