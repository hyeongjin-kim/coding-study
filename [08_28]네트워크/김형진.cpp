#include <string>
#include <vector>
#include <stack> //맨날 콜스텍으로만 하는거 같아서 스텍 만들어서 함 해봄 ㅎㅎ
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    stack<int> network_stack; //현재 네트워크를 담는 스텍
    
    bool visit[201] = {}; //방문 배열
    
    for(int i = 0; i < n; i++){
        if(visit[i]) continue; //이미 기존 네트워크에서 처리됐으면 지나감
        visit[i] = true; //네트워크에서 처리됐음을 표시
        network_stack.push(i); //스텍에 추가(네트워크의 시작점)
        answer++; //네트워크 개수 증가
        while(!network_stack.empty()){ //동일 네트워크의 컴퓨터 찾기
            int target = network_stack.top(); //네트워크에 가장 마지막에 추가된 컴퓨터 가져오기
            bool done = true; //이 컴퓨터에서 볼 수 있는 거를 다 봤는지 여부
            
            for(int j = 0; j < n; j++){
                if(visit[j] or computers[target][j] == false) continue; //이미 봤거나, 연결 안됐으면 지나감
                visit[j] = true; //방문 표시
                done = false; //아직 다 안봤음
                network_stack.push(j); //네트워크에 추가
                break;
            }
            if(done) network_stack.pop(); //다 봤으니 네트워크에서 제거
        }
    }
    
    return answer;
}
