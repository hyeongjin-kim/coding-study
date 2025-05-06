#include <iostream>

using namespace std;

#define MAX_N 40

int n;
bool col[MAX_N];
bool d1[MAX_N]; // 대각선 r-c;
bool d2[MAX_N]; // 대각선 r+c;
int ans = 0;

void Backtracking(int row){
    if(row == n+1){
        ans++;
        return;
    }
    
    for(int i=1; i<=n; i++){
        if(col[i] || d1[row-i+n] || d2[row+i])
            continue;
        col[i] = true;
        d1[row-i+n] = true;
        d2[row+i] = true;
        Backtracking(row+1);
        col[i] = false;
        d1[row-i+n] = false;
        d2[row+i] = false;
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    Backtracking(1);
    
    cout << ans;
    
    return 0;
}

/*
      (1,1) (1,2) (1,3) (1,4)
합 2  (2,1) (2,2) (2,3) (2,4) 차 -3 + 4 1
합 3  (3,1) (3,2) (3,3) (3,4) 차 -2 2
합 4  (4,1) (4,2) (4,3) (4,4) 차 -1 3
합 5        합 6   합 7    합8    차 0 4
       차 3 7    차 2 6   차 1 5
*/

