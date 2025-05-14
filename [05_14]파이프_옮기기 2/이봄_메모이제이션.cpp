#include <iostream>
#include <vector>
#include <tuple>
#include <memory.h>

using namespace std;

#define MAX_N 37

int board[MAX_N][MAX_N]; // 빈 칸은 0, 벽은 1
int n;
long long ans;
vector<pair<int,int> > path;
long long dp[MAX_N][MAX_N][3];

bool InRange(int x, int y){
    return x >= 1 && x <=n && y >= 1 && y <=n;
}

void Print(){
    for(int i=0; i<path.size(); i++){
        cout << path[i].first <<" " << path[i].second <<"\n";
    }
    cout << "\n";
    return ;
}

bool Check(int x, int y){
    if(InRange(x-1,y) && board[x-1][y] != 0)
        return false;
    if(InRange(x,y-1) && board[x][y-1] != 0)
        return false;
    if(InRange(x,y) && board[x][y] != 0)
        return false;
    return true;
}

// opt : 1(가로), 2(세로), 3(대각선)
long long DFS(int opt, int x, int y){
    
    if(x==n && y==n){
        return 1;
    }
    
    long long tmp = dp[x][y][opt-1];
    
    if(tmp != -1)
        return tmp;
    
    tmp = 0;
    // 가로
    if(opt == 1 || opt == 3){
        if(InRange(x,y+1) && board[x][y+1] == 0){
            tmp += DFS(1,x,y+1);
        }
    }
    // 세로
    if(opt == 2 || opt == 3){
        if(InRange(x+1,y) && board[x+1][y] == 0){
            tmp += DFS(2, x+1, y);
        }
    }
    // 대각선
    if(opt == 1 || opt == 2 || opt == 3){
        if(InRange(x+1,y+1) && Check(x+1,y+1)){
            tmp += DFS(3, x+1, y+1);
        }
    }
    dp[x][y][opt-1] = tmp;
    return tmp;
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    
    memset(dp,-1,sizeof(dp));
    
    ans = DFS(1,1,2);
    
    cout << ans;
    
    return 0;
}

/*
 새 집의 크기는 n*n 크기의 격자판
 행과 열의 번호는 1부터 시작한다
 */



//---------------------------
// DP 풀이  


#include <iostream>

using namespace std;

#define MAX_N 37

int board[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N][3];
int n;

bool InRange(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y<= n;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    
    // dp[x][y][0] : 가로, dp[x][y][1] : 세로, dp[x][y][2] : 대각선
    
    dp[1][2][0] = 1; // (1,1) ~ (1,2) 가로로 왔을 때 까지 경우의 수
    
    for(int i=1; i<=n; i++){
        for(int j=3; j<=n; j++){
            
            if(board[i][j] == 1){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                dp[i][j][2] = 0;
                continue;
            }
                
            if(InRange(i,j-1))
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
            if(InRange(i-1,j))
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
            if(InRange(i-1,j-1) && board[i-1][j] == 0 && board[i][j-1] == 0)
                dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
        }
    }
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    
    return 0;
}

