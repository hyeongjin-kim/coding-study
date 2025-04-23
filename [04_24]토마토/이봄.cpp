#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_MNH 105


/*
시간 줄이기
1. tuple 대신에 struct 이용하기 
2. 안 익은 토마토 미리 개수 세기 
3. days 배열 쓰지 말고, queue에 저장하기 
*/

int m,n,h;
int box[MAX_MNH][MAX_MNH][MAX_MNH];
int days[MAX_MNH][MAX_MNH][MAX_MNH];

// 위 아래
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
int dz[6] = {1,-1,0,0,0,0};

int green_cnt = 0;

struct Pos{
    int z,x,y,day;
};

queue<Pos> q;

int ans = 0;


bool InRange(int x, int y, int z){
    return x>=0 && x < n && y >=0 && y<m && z >=0 && z < h;
}

bool CanGo(int x, int y, int z){
    if(InRange(x,y,z) == false)
        return false;
    if(box[z][x][y] == 1)
        return false;
    if(box[z][x][y] == -1)
        return false;
    return true;
}

void Print(){
    cout <<"\n\n";
    for(int z=0; z<h; z++){
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                cout << days[z][x][y] << " ";
            }
            cout << "\n";
        }
        cout <<"\n\n";
    }
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> n >> h;
    
    bool flag1 = true;
    
    for(int z=0; z<h; z++){
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                cin >> box[z][x][y];
                if(box[z][x][y] == 1){
                    q.push({z,x,y,0});
                    //days[z][x][y] = 1;
                }
                if(box[z][x][y] == 0){
                    flag1 = false;
                    green_cnt++;
                }
                
            }
        }
    }
    if(flag1){
        cout << 0;
        return 0;
    }
    
    while(q.empty() == false){

        auto [z,x,y,day] = q.front(); q.pop();
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(CanGo(nx,ny,nz)){
                box[nz][nx][ny] = 1;
                q.push({nz,nx,ny,day+1});
                green_cnt--;
                ans = max(ans, day+1);
            }
        }
    }
    
    
    if(green_cnt == 0)
        cout << ans;
    else
        cout << -1;
    
   
    
    
    /*
    bool flag2 = true;
    
    for(int z=0; z<h; z++){
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                if(days[z][x][y]==0 && box[z][x][y] != -1)
                    flag2 = false;
                ans = max(days[z][x][y], ans);
            }
        }
    }
     */
    
    //Print();
    
    /*
    if(flag2)
        cout << ans-1;
    else
        cout << -1;
    
    return 0;
     */
    
}

/*
 철수의 토마토 농장
 잘 익은 토마토
 아직 익지 않은 토마토
 보관 후 하루가 지나면
 익은 토마토들의 인접한 곳에 있는 토마토들은 익은 토마토의 영향을 받아 익게 된다
 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 6방향에 있는 토마토
 며칠이 지나면 토마토들이 모두 익는지
 "그 최소 일 수"를 구해라
 상자의 일부 칸에는 토마토가 없을 수도 있움..
 
 1 : 익은 토마토
 0 : 익지 않은 토마토
 -1 : 토마토가 들어있지 않은 칸
 */

