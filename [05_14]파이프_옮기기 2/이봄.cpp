#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_N 20

int board[MAX_N][MAX_N]; // 빈 칸은 0, 벽은 1
int n;
int ans;
vector<pair<int,int> > path;

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
void DFS(int opt, int x, int y){
    
    if(x==n && y==n){
        ans++;
        //cout <<ans <<" : " << x << " " << y <<"\n";
        //Print();
        return;
    }
    // 가로
    if(opt == 1 || opt == 3){
        if(InRange(x,y+1) && board[x][y+1] == 0){
            DFS(1,x,y+1);
        }
    }
    // 세로
    if(opt == 2 || opt == 3){
        if(InRange(x+1,y) && board[x+1][y] == 0){
            DFS(2,x+1,y);
        }
    }
    // 대각선
    if(opt == 1 || opt == 2 || opt == 3){
        if(InRange(x+1,y+1) && Check(x+1,y+1)){
            DFS(3,x+1,y+1);
        }
    }
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
    
    DFS(1,1,2);
    
    cout << ans;
    
    return 0;
}

/*
 새 집의 크기는 n*n 크기의 격자판
 행과 열의 번호는 1부터 시작한다
 */
