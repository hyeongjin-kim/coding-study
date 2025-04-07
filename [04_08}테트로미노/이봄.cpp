#include <iostream>

using namespace std;
#define MAX_NM 505

int n,m;
int arr[MAX_NM][MAX_NM];


// 인덱스 3번부터 4회전 필요함..
int dx[7][4] = {
    {0,0,0,0},
    {0,1,2,3},
    {0,0,1,1},
    {0,1,2,2},
    {0,0,-1,-2},
    {0,1,1,2},
    {0,1,0,-1}
};

int dy[7][4] = {
    {0,1,2,3},
    {0,0,0,0},
    {0,1,0,1},
    {0,0,0,1},
    {0,1,1,1},
    {0,0,1,1},
    {0,0,1,1}
};
// ㅗ ㅓ ㅏ ㅜ
int dx2[4][4] = {
    {0,0,0,-1},
    {0,-1,0,1},
    {-1,0,1,0},
    {0,0,0,1}
};

int dy2[4][4] = {
    {0,1,2,1},
    {0,1,1,1},
    {0,0,0,1},
    {0,1,2,1}
};

bool InRange(int x, int y){
    return x>=0 && x < n && y >=0 && y<m;
}

int Solution(int x, int y){
    
    int val = 0;
    
    for(int i=0; i<7; i++){
        int tmp = 0;
        bool flag = true;
        for(int j=0; j<4; j++){
            int nx = x + dx[i][j];
            int ny = y + dy[i][j];
            if(InRange(nx,ny))
                tmp += arr[nx][ny];
            else
                flag = false;
        }
        if(flag)
            val = max(val, tmp);
        tmp = 0;
        flag = true;
        
        if(i >= 3){
            // 90도 회전
            // (x,y) -> (y,-x)
            for(int j=0; j<4; j++){
                int nx = x + dy[i][j];
                int ny = y - dx[i][j];
                if(InRange(nx,ny))
                    tmp += arr[nx][ny];
                else
                    flag = false;
            }
            
            if(flag)
                val = max(val, tmp);
            tmp = 0;
            flag = true;
            // 180도 회전
            // (x,y) -> (-x,-y)
            
            for(int j=0; j<4; j++){
                int nx = x - dx[i][j];
                int ny = y - dy[i][j];
                if(InRange(nx,ny))
                    tmp += arr[nx][ny];
                else
                    flag = false;
            }
            if(flag)
                val = max(val, tmp);
            tmp = 0;
            flag = true;
            
            // 270도 회전
            // (x,y) -> (-y,x)
            for(int j=0; j<4; j++){
                int nx = x - dy[i][j];
                int ny = y + dx[i][j];
                if(InRange(nx,ny))
                    tmp += arr[nx][ny];
                else
                    flag = false;
            }
            if(flag)
                val = max(val, tmp);
            tmp = 0;
            flag = true;
        }
    }
    
    // ㅗ ㅓ ㅏ ㅜ
    for(int i=0; i<4; i++){
        bool flag = true;
        int tmp = 0;
        for(int j=0; j<4; j++){
            int nx = x + dx2[i][j];
            int ny = y + dy2[i][j];
            if(InRange(nx,ny))
                tmp += arr[nx][ny];
            else
                flag = false;
        }
        if(flag)
            val = max(val, tmp);
    }
    
    return val;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp = Solution(i,j);
            ans = max(ans, tmp);
        }
    }
    
    cout << ans;
    
    return 0;
}


/*
 폴리오미노 - 1*1 정사각형을 여러개 이어서 붙인 도형
 정사각형은 서로 겹치면 안된다
 도형은 모두 연결되어있어야 한다
 정사각형의 변끼리 연결되어있어야 한다.
 회전이나 대칭을 시켜도 된다.
 구하는 것 - 테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여있는 수들의 합을 최대로 하는 프로그램
 */

/*
// 가장위, 가장 왼쪽 칸이 시작점
// 가로 4칸
int dx1[4] = {0,0,0,0};
int dy1[4] = {0,1,2,3};
// 세로 4칸
int dx2[4] = {0,1,2,3};
int dy2[4] = {0,0,0,0};
// 네모네모
int dx3[4] = {0,0,1,1};
int dy3[4] = {0,1,0,1};

// L 모양
int dx4[4] = {0,1,2,2};
int dy4[4] = {0,0,0,1};

// L 대칭
int dx5[4] = {0,0,-1,-2};
int dy5[4] = {0,1,1,1};

// Z 모양
int dx6[4] = {0,1,1,2};
int dy6[4] = {0,0,1,1};

// Z 대칭
int dx7[4] = {0,1,0,-1};
int dy7[4] = {0,0,1,1};

*/
