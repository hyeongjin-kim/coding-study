#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_N 105

int t,n;
int hx,hy; // 상근이네 집
int fx,fy; // 페스티벌
int cx[MAX_N]; // 편의점
int cy[MAX_N];
bool visited[MAX_N];
queue<tuple<int,int,int> > q;

int Distance(int x1,int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

bool Solution(){
    q.push({hx,hy,20});
    while(q.empty() == false){
        int x,y,b;
        tie(x,y,b) = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            int nx = cx[i];
            int ny = cy[i];
            int dist = Distance(x,y,nx,ny);
            if(dist <= 50*b && visited[i] == false){ // 편의점에 갈 수 있으면..
                visited[i] = true;
                q.push({nx,ny,20});
            }
        }
        int dist2 = Distance(x,y,fx,fy);
        if(dist2<= 50*b){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t ;
    
    for(int tc =1; tc<=t; tc++){
        cin >> n; // 테케마다 n 입력 안 받아서 틀림 ㅜ.,ㅜ
        memset(cx,0,sizeof(cx));
        memset(cy,0,sizeof(cy));
        memset(visited,false,sizeof(visited));
        while(q.empty()==false)
            q.pop();
        cin >> hx >> hy;
        for(int i=0; i<n; i++){
            cin >> cx[i] >> cy[i];
        }
        cin >> fx >> fy;
        bool flag = Solution();
        if(flag)
            cout <<"happy\n";
        else
            cout <<"sad\n";
    }
    return 0;
}


/*
 상근이네 집에서 출발
 맥주 1박스 (20개)
 맥주 50m 가기 직전에 맥주 한병씩
 한 박스에 20병 넘길 수 없음..
 집 -> 편의점 -> 페스티벌
 */
