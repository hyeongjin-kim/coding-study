#include <iostream>
#include <string>
#include <set>
#include <tuple>
#include <memory.h>

using namespace std;

#define MAX_N 105

int n,m; // n - 세로 길이, m - 가로 길이
int t; // 준표가 관찰하는 시간
int k; // 주위의 기준
int a,b; //


int new_board[MAX_N][MAX_N];
int board[MAX_N][MAX_N];

int val[MAX_N][MAX_N];

void Simul1(int x, int y){
    return;
}

void Simul2(int x, int y){
    new_board[x][y] = 0;
    return;
}

void Simul3(int x, int y){
    new_board[x][y] = 0;
    return;
}

void Simul4(int x, int y){
    new_board[x][y] = 1;
    return;
}

bool InRange(int x, int y){
    return x>=1 && x <= n && y >=1 && y <= m;
}

int Check(int x, int y){
    int x1 = x-k;
    int y1 = y-k;
    int x2 = min(x+k,n);
    int y2 = min(y+k,m);
    
    int cnt = val[x2][y2]
    - (x1 > 1 ? val[x1-1][y2] : 0)
    - (y1 > 1 ? val[x2][y1-1] : 0)
    + (x1 > 1 && y1 > 1 ? val[x1-1][y1-1] : 0)
    - board[x][y];
    
    /*
    for(int row = x-k; row <= x+k; row++){
        for(int col = y-k; col <= y+k; col++){
            if(row == x && col == y)
                continue;
            if(InRange(row,col) && board[row][col]!=0){
                cnt++;
            }
        }
    }
    */
    
    if(board[x][y]!=0){
        if(cnt >= a && cnt <= b){
            return 1;
        }
        else if(cnt < a){
            return 2;
        }
        else if(cnt > b){
            return 3;
        }
    }
    else{
        if(cnt > a && cnt <= b)
            return 4;
    }
    return 0;
}

void Copy1(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            new_board[i][j] = board[i][j];
        }
    }
}

void Copy2(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            board[i][j] = new_board[i][j];
        }
    }
}

void CalSum(){
    memset(val, 0, sizeof(val));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
                val[i][j] = val[i - 1][j] + val[i][j - 1]
                          - val[i - 1][j - 1] + board[i][j];
        }
    }
}
void Solution(){

    Copy1();
    CalSum();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int num = Check(i,j);
            if(num == 1)
                Simul1(i,j);
            else if(num == 2)
                Simul2(i,j);
            else if(num == 3)
                Simul3(i,j);
            else if(num == 4)
                Simul4(i,j);
        }
    }
    Copy2();
}


void Print(){
    //cout <<"\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(board[i][j] == 0)
                cout <<'.';
            else
                cout <<'*';
        }
        cout <<"\n";
    }
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> t;
    cin >> k >> a >> b;
    
    for(int i=1; i<=n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<m; j++){
            if(tmp[j] == '*'){
                board[i][j+1] = 1;
            }
            else{
                board[i][j+1] = 0;
            }
        }
    }
    
    while(t--){
        Solution();
        //Print();
    }
    
    Print();
    return 0;
}


/*
 바둑판은 각 칸은 주위의 영향을 받는다
 주위 2k+1, 정사각형에서 현재칸을 제외한 영역..
 그냥 (x-k, y-k) ~ (x+k, y+k)
 1. 생존 - 현재 생명있고, 주위에 a이상 b이하의 생명이 있는 경우
 2. 고독 - 현재 생명있고, 주위 a 미만 있는 경우
 3. 과밀 - 현재 생명있고, 주위에 b개 초과의 생명
 4. 탄생 - 현재 생명없고, a 초과 b 이하
 
 n*m 크기의 바둑판에 생명을 뿌리고, T시간 뒤의 생명을 관찰하고자 한다
 */

