#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_N2 405
#define MAX_N 25

int n;
int student_like[MAX_N2][4];
vector<int> order;
int classroom[MAX_N][MAX_N];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void Print(){
    
    cout << "\n";
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << classroom[i][j] <<" ";
        }
        cout <<"\n";
    }
    
    cout << "\n";
}
bool InRange(int x, int y){
    return x>=0 && x <n && y>=0 && y < n;
}

pair<int,int> Count(int x, int y,int num){
    int cnt_like = 0;
    int cnt_empty = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny)){
            // 2. 인접한 칸 중 비어있는 칸 세기
            if(classroom[nx][ny] == 0){
                cnt_empty++;
                continue;
            }
            // 1. 인접한 칸 중 좋아하는 학생 수 세기
            for(int j = 0; j < 4; j++){
                if(classroom[nx][ny] == student_like[num][j]){
                    cnt_like++;
                    break;
                }
            }
        }
    }
    return {cnt_like, cnt_empty};
}

pair<int,int> Solution(int num){
    int cnt_like = 0;
    int cnt_empty = 0;
    int fr = n;
    int fc = n;
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            if(classroom[r][c] == 0){
                int tmp_like, tmp_empty = 0;
                tie(tmp_like, tmp_empty)= Count(r,c,num);
                // 좋아하는 학생 수 같을 때 빈자리 수 비교 
                if(tmp_like == cnt_like && tmp_empty > cnt_empty){
                    cnt_empty = tmp_empty;
                    fr = r;
                    fc = c;
                }
                // 좋아하는 학생 수가 더 큰 경우
                else if(tmp_like > cnt_like ){
                    cnt_like = tmp_like;
                    cnt_empty = tmp_empty;
                    fr = r;
                    fc = c;
                }
                // 이도 저도 아닌 경우 행, 열 비교 
                else if (classroom[r][c] == 0 && tmp_like == cnt_like && tmp_empty == cnt_empty && fr >= r && fc > c ){
                    fr = r;
                    fc = c;
                }
            }
        }
    }    
    return {fr, fc};
}

// 인접한 칸 중 좋아하는 학생 수 세기
int CountCnt(int x, int y){
    int cnt = 0;
    int num = classroom[x][y];
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx, ny)){
            for(int j = 0; j < 4; j++){
                if(classroom[nx][ny] == student_like[num][j]){
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}
// 만족도 계산 
int Cal(){
    int val = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp = CountCnt(i,j);
            if(tmp == 1)
                val += 1;
            else if(tmp == 2)
                val += 10;
            else if(tmp == 3)
                val += 100;
            else if(tmp == 4)
                val += 1000;
        }
    }
    return val;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n*n; i++){
        int num;
        cin >> num;
        order.push_back(num);
        for(int j=0; j<4; j++){
            cin >> student_like[num][j];
        }
    }
    
    for(int i=0; i<n*n; i++){
        int x,y;
        tie(x,y) = Solution(order[i]);
        classroom[x][y] = order[i];
    }
    

    
    int ans = Cal();
    
    cout << ans;
    
    return 0;
}



