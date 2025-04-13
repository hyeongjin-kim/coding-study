#include <iostream>

using namespace std;

#define MAX_RC 25

int r,c;
bool visited[30];
int board[MAX_RC][MAX_RC];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cnt[MAX_RC][MAX_RC];
int ans = 0;

bool InRange(int x, int y){
    return x>=0 && x < r && y >=0 && y <c;
}

bool CanGo(int x, int y){
    if(InRange(x,y)==false)
        return false;
    if(visited[board[x][y]])
        return false;
    return true;
}

void DFS(int x, int y){
    
    ans = max(ans, cnt[x][y]);
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(CanGo(nx,ny)){
            visited[board[nx][ny]] = true;
            cnt[nx][ny] = cnt[x][y] + 1;
            DFS(nx,ny);
            visited[board[nx][ny]] = false;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0;j <c; j++){
            char c;
            cin >> c;
            board[i][j] = c - 'A' + 1;
        }
    }
    
    cnt[0][0] = 1;
    visited[board[0][0]] = true;
    DFS(0,0);
    cout << ans;
    return 0;
}
