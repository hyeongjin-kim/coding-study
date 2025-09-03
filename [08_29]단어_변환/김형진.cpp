#include <string>
#include <vector>
#include <queue>

using namespace std;

bool compare_word(string a, string b){ //두 단어가 한 글자 차이인지 확인하는 함수
    bool flag = false;
    for(int i = 0; i < a.length(); i++){ //단어간 글자 수가 같으므로 for문으로 순회
        if(a[i] == b[i]) continue; //같으면 상관 없음
        if(flag){ //이미 다른 글자가 있는 경우 실패
            flag = false;  
            break;
        }
        flag = true; //처음 다른 글자가 나온 경우 플래그 활성화
    }
    return flag;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    vector<vector<int>> adj(words.size() + 1, vector<int>()); //인접 리스트
    
    for(int i = 0; i < words.size(); i++){
        if(compare_word(words[i], begin)){ //시작 단어(인덱스로 words의 가장 마지막 + 1 사용)와 다른 단어들 비교해서 한 글자 차이면 간선 연결
                adj[i].push_back(words.size());
                adj[words.size()].push_back(i);
            }
        for(int j = i + 1; j < words.size(); j++){ //각 단어들 끼리 비교해서 한 글자 차이면 간선 연결
            if(compare_word(words[i], words[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    bool visit[50] = {};
    queue<int> q;
    q.push(words.size()); //시작단어 인덱스 넣기
    int cur;
    while(!q.empty()){
        int n = q.size(); //시작할 때 q에 있는 개수만큼만 돌기 => depth 계산을 쉽게 하기 위해
        for(int i = 0; i < n; i++){
            cur = q.front();
            q.pop();

            if(words[cur] == target) return answer; //찾으면 그대로 종료
            if(visit[cur]) continue; //이미 방문한거면 넘어가기
            visit[cur] = true; //방문 표시

            for(int next : adj[cur]){ //연결된 단어들 중 방문 안한 것들 순회
                if(visit[next]) continue;
                q.push(next);
            }
        }
        answer++;
    }
    if(words[cur] != target) answer = 0; //만약 최종 결과가 target이 아니면 불가능 표시
    return answer;
}
