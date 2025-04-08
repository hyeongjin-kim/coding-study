#include <iostream>
#include <string>
#include <deque>

using namespace std;

string org_str;
string new_str = "";
int n,a_cnt, b_cnt;
int b_start, b_end;
deque<char> dq;
int ans1, ans2;
int ans = 2000;

bool OK(){

    int idx = 0;
    int cnt = 0;
    while(true){
        if(org_str[idx] == 'a'){
            cnt++;
            idx++;
        }
        else
            break;
    }
    
    if(cnt == a_cnt)
        return true;
    
    
    idx = n-1;
    while(true){
        if(org_str[idx] == 'a'){
            cnt++;
            idx--;
        }
        else
            break;
    }
    if(cnt == a_cnt)
        return true;
    else
        return false;
}
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> org_str;
    n = (int) org_str.size();

    for(int i=0; i<n; i++){
        dq.push_back(org_str[i]);
    }
    
    for(int k=0; k<n; k++){
        org_str = "";
        for(int i=0; i<n; i++){
            org_str += dq[i];
        }
        // 0. a,b 글자 수 세기, b 문자 시작 인덱스, 마지막 인덱스 찾기
        a_cnt = 0;
        b_cnt = 0;
        for(int i=0; i<n; i++){
            if(org_str[i] == 'a')
                a_cnt++;
            else
                b_cnt++;
            if(b_cnt == 1 && org_str[i] == 'b')
                b_start = i;
            if(org_str[i] == 'b')
                b_end = i;
        }
        
        // 1. a 모두 연속인지
        bool flag = OK();
        if(flag){
            cout << 0;
            return 0;
        }
        
        // 2. 비교할 문자열 만들기
        for(int i=0; i<n; i++){
            if(i >= b_start && i <= b_end)
                new_str +='b';
            else
                new_str += 'a';
        }
        
        /* 3. 처음 b가 시작할 때부터 b가 끝날때까지 다 b로 채움
         그리고 origin 이랑 nstr 이랑 비교해서
         b의 개수 세고, 둘이 똑같이 bb 인 경우 제외하고,다른 경우 count 해줌 b 개수 될 때까지
         */
        
        ans1 = 0;
        int cnt = 0;
        for(int i=b_start; i<=b_end; i++){
            if(org_str[i] == 'b' && new_str[i] == 'b'){
                cnt++;
            }
            else{
                ans1++;
                cnt++;
            }
            if(cnt >= b_cnt)
                break;
        }
        
        ans2 = 0;
        cnt = 0;
        for(int i=b_end; i>=b_start; i--){
            if(org_str[i] == 'b' && new_str[i] == 'b'){
                cnt++;
            }
            else{
                ans2++;
                cnt++;
            }
            if(cnt >= b_cnt)
                break;
        }
        char c = dq.back();
        dq.pop_back();
        dq.push_front(c);
        //cout << org_str <<" " << ans1 <<" " << ans2 <<"\n";
        int tmp = min(ans1, ans2);
        ans = min(ans,tmp);
        
    }
    
    cout << ans;
    
    return 0;
}

/*
 반례
 aaabaaaaababaaa
 abaaaaabaaaaab <= 얘를 어케 처리하지... 글자 위치를 바꾸면 되는데... 훔...
 baaaaabaaaaaba
 aaaaabaaaaabab
 aaaabaaaaababa
 정답 1 나와야함.. ㅜ.ㅠ
 */

/*
 a와 b로만 이루어진 문자열이 주어질 때
 a를 모두 연속으로 만들기 위해 필요한 교환의 횟수를 최소로 하는 프로그램을 작성해라
 */

/*
aabbaaabaaba;
aabbbbbbbbba;

abab;
abbb;

abababababababa;
abbbbbbbbbbbbba;

처음 b가 시작할 때부터 b가 끝날때까지 다 b로 채움
그리고 origin 이랑 nstr 이랑 비교해서
 b의 개수 세고, 둘이 똑같이 bb 인 경우 제외하고,다른 경우 count 해줌 b 개수 될 때까지
 
 구현해야하는거
 1. 문제 조건에 맞는 문자열인지 (a 모두 연속인지) -> 그럼 0 출력하게
 2. 전체 문자열 길이, a,b, 개수 세기
 3. b 시작 위치 인덱스, b 끝 위치 인덱스
 4. 개수세기 ~
*/


