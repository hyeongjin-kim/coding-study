#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>

using namespace std;

#define MAX2N 205

int n,k;
deque<int> belt;
deque<int> robot_on;
unordered_map<int, int> rnum2on; // 인덱스 - 로봇 번호 , value - 로봇 벨트 위에 있는지
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >pq;
// first - robotnum, second - dq에서 위치

void MoveRobot(){
    // 가장 먼저 올라간 로봇부터 이동시키기 위해 pq에 담기
    for(int i=0; i<2*n; i++){
        if(robot_on[i] != 0){
            pq.push({robot_on[i], i});
        }
    }
    //이동가능한지 판단 후 이동시키기
    while(pq.empty() == false){
        int num,pos;
        tie(num,pos) = pq.top();
        pq.pop();
        if(pos == 2*n - 1){
            if(robot_on[0] == 0 && belt[0] >= 1){
                robot_on[0] = num;
                belt[0]--;
                robot_on[pos] = 0;
            }
        }
        else if(pos == n-2){
            if(robot_on[n-1]== 0 && belt[n-1] >= 1){
                robot_on[n-1] = 0; // 즉시 내림
                belt[n-1]--;
                robot_on[pos] = 0;
            }
        }
        else{
            if(robot_on[pos+1]==0 && belt[pos+1] >= 1){
                robot_on[pos] = 0;
                robot_on[pos+1] = num;
                belt[pos+1]--;
            }
        }
        
    }
}
void Print(){
    for(int i=0; i<2*n; i++){
        cout << "i : " << i <<" " << belt[i] << " " << robot_on[i] <<" \n";
    }
    cout <<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<2*n; i++){
        int x;
        cin >> x;
        belt.push_back(x);
        robot_on.push_back(0);
    }
    
    int ans = 1;
    // 참고 벨트는 0~n-1, n~2n-1 까지 있음
    int robot_num = 1;
    while(true){
        // 1. 회전
        int x = belt.back();
        belt.pop_back();
        belt.push_front(x);
        int r = robot_on.back();
        robot_on.pop_back();
        robot_on.push_front(r);
        // 내리는 칸에 도착한 로봇 내리기
        if(robot_on[n-1] != 0)
            robot_on[n-1] = 0;
        cout <<"after Rotate\n";
        //Print();
        //2. 로봇 이동
        MoveRobot();
        cout <<"after Move\n";
        //Print();
        //3. 올리는 위치에 있는 칸 내구도가 0이 아니라면 로봇 올리기
        if(belt[0] >= 1 && robot_on[0] == 0){
            belt[0]--;
            robot_on[0] = robot_num++;
        }
        //4. 내구도가 0인 칸의 개수가 k개 이상이면 종료.
        int cnt =0;
        for(int i=0; i<2*n; i++){
            if(belt[i] == 0)
                cnt++;
        }
        if(cnt >= k)
            break;
        cout <<"While end\n";
        //Print();
        ans++;
        
    }
    cout << ans;
    return 0;
}

/*
 길이가 n인 컨베이어 벨트
 벨트 길이 2n, 회전함..
 i번 칸의 내구도 Ai
 올리는 위치 - 1번 칸
 내리는 위치 - n번 칸
 로봇이 올라온 칸 내구도 1만큼 즉시 감소
 
 1. 벨트가 각 칸위에 있는 로봇과 함께 한칸 회전
 2. 가장 먼저 올라간 로봇부터, 벨트가 회전하는 방향으로 한칸 이동할 수 있다면 이동, 이동할 수 없다면 가만히 있는다
 이동 가능한 조건 : 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1이상 남아 있어야 한다
 3. 올리는 위치에 칸 내구도가 0이 아니면 올리는 위치에 로봇 올린다
 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료
 
 훔.. 컨베이어 벨트 뭘로 구현하지.. deque?
 */
