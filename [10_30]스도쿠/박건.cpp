#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

#define endl '\n'

#define LIM 987654321

using namespace std;

int board[10][10];
vector<pair<int, int>> blanks;
int blankCnt;

bool checkCol(int y, int x){
    int val = board[y][x];
    for (int i = 0; i < 9; i++){
        if(y == i)
            continue;
        if(board[i][x] == val)
            return false;
    }
    return true;
}

bool checkRow(int y, int x){
    int val = board[y][x];
    for (int i = 0; i < 9; i++){
        if(x == i)
            continue;
        if(board[y][i] == val)
            return false;
    }
    return true;
}

bool checkBox(int y, int x){
    int val = board[y][x];
    int sy = (y / 3) * 3;
    int sx = (x / 3) * 3;

    for (int i = sy; i < sy + 3; i++){
        for (int j = sx; j < sx + 3; j++){
            if(y == i && x == j)
                continue;
            if(board[i][j] == val)
                return false;
        }
    }
    return true;
}

bool check(int y, int x){
    if(!checkCol(y, x))
        return false;
    if(!checkRow(y, x))
        return false;
    if(!checkBox(y, x))
        return false;
    return true;
}

bool dfs(int blankIdx){
    if(blankIdx == blankCnt){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        return true;
    }
        
    int y = blanks[blankIdx].first;
    int x = blanks[blankIdx].second;

    for (int i = 1; i <= 9; i++){
        board[y][x] = i;
        if(!check(y, x))
            continue;
            
        if(dfs(blankIdx + 1)){
            return true;
        }
    }
    board[y][x] = 0;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == 0)
                blanks.push_back({i, j});
        }
    }
    blankCnt = blanks.size();
    
   
    dfs(0);

    return 0;
}
