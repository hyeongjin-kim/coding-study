#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_L 305

int tc;
int dist[MAX_L][MAX_L];
int l;
int sx,sy;
int ex,ey;
int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};

struct pos{
    int x,y;
};

queue<pos> q;

bool InRange(int x, int y){
    return x>= 0 && x <l && y>=0 && y<l;
}

bool CanGo(int x, int y){
    if(InRange(x,y) == false)
        return false;
    if(dist[x][y] != 0)
        return false;
    return true;
}


void Solution(){
    
    q.push({sx,sy});
    dist[sx][sy] = 1;
    
    while(q.empty()==false){
        int x = q.front().x;
        int y = q.front().y;
        if(x == ex && y == ey)
            break;
        q.pop();
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(CanGo(nx,ny)){
                q.push({nx,ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> tc;
    
    for(int i=0; i<tc; i++){
        int ans = 0;
        memset(dist, 0, sizeof(dist));
        while(q.empty() == false)
            q.pop();
        cin >> l;
        cin >> sx >> sy;
        cin >> ex >> ey;
        Solution();
        ans = dist[ex][ey]-1;
        cout << ans <<"\n";
    }
    return 0;
}

/*
 테스트 케이스의 개수
 체스판 한변의 길이
 나이트가 현재 있는칸
 이동하려는 칸
 
 각 테케마다 나이트가 최소 몇번만에 이동할 수 있는지 출력
 
 1
 100
 0 0
 30 50
 
 */
