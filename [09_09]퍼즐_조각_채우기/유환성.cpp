#include <bits/stdc++.h>
using namespace std;

int N, M;
int piececnt;
int visited[55][55];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<pair<int,int>> pieces[1000];
vector<pair<int,int>> holes[1000];
int holecnt;

// 좌표 범위 확인
bool inRange(int x,int y){
    return 0<=x && x<N && 0<=y && y<M;
}

// 좌표 정규화: 최소 (x,y) 빼고 정렬
void normalize(vector<pair<int,int>>& v){
    int minx=1e9, miny=1e9;
    for(auto &p:v){
        minx = min(minx,p.first);
        miny = min(miny,p.second);
    }
    for(auto &p:v){
        p.first -= minx;
        p.second -= miny;
    }
    sort(v.begin(), v.end());
}

// 90도 회전
vector<pair<int,int>> rotate(vector<pair<int,int>> v){
    vector<pair<int,int>> ret;
    for(auto &p:v){
        int x=p.first, y=p.second;
        ret.push_back({y,-x});
    }
    normalize(ret);
    return ret;
}

// 두 도형이 같은지 확인
bool isSame(vector<pair<int,int>> a, vector<pair<int,int>> b){
    if(a.size()!=b.size()) return false;
    normalize(a); normalize(b);
    for(int r=0;r<4;r++){
        if(a==b) return true;
        a = rotate(a);
    }
    return false;
}

// BFS로 도형 추출
vector<pair<int,int>> bfs(vector<vector<int>>& board, int sx,int sy,int target){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    visited[sx][sy]=1;
    vector<pair<int,int>> shape;
    
    shape.push_back({sx,sy});
    while(!q.empty()){
        auto now=q.front(); q.pop();
        for(int d=0;d<4;d++){
            int nx=now.first+dx[d], ny=now.second+dy[d];
            if(!inRange(nx,ny) || visited[nx][ny]) continue;
            if(board[nx][ny]!=target) continue;
            visited[nx][ny]=1;
            q.push({nx,ny});
            shape.push_back({nx,ny});
        }
    }
    normalize(shape);
    return shape;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table){
    N = game_board.size();
    M = game_board[0].size();
    memset(visited,0,sizeof(visited));

    // 1. table에서 조각 추출 (1)
    piececnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && table[i][j]==1){
                pieces[piececnt++] = bfs(table,i,j,1);
            }
        }
    }

    // 2. game_board에서 빈칸 추출 (0)
    memset(visited,0,sizeof(visited));
    holecnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && game_board[i][j]==0){
                holes[holecnt++] = bfs(game_board,i,j,0);
            }
        }
    }

    // 3. 매칭 시도
    int answer=0;
    vector<int> used(piececnt,0);
    for(int h=0;h<holecnt;h++){
        for(int p=0;p<piececnt;p++){
            if(used[p]) continue;
            if(isSame(holes[h], pieces[p])){
                answer += holes[h].size();
                used[p]=1;
                break;
            }
        }
    }
    return answer;
}
