#include <iostream>
#include <string>
#include <deque>

using namespace std;

int n; // 문자열의 길이
int m; // 입력할 명령어의 개수
string str; // 편집기에 입력되어 있는 문자열
deque<char> str1;
deque<char> str2;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> str;
    
    for(int i=0; i<(int)str.size(); i++){
        str1.push_back(str[i]);
    }
    
    cin >> m;
    
    for(int i=0; i<m; i++){
        char c;
        cin >> c;
        
        if(c == 'L' && str1.empty() == false){
            char tmp = str1.back();
            str1.pop_back();
            str2.push_front(tmp);
        }
        else if(c== 'D' && str2.empty() == false){
            char tmp = str2.front();
            str2.pop_front();
            str1.push_back(tmp);
        }
        else if(c == 'B' && str1.empty() == false){
            str1.pop_back();
        }
        else if (c == 'P'){
            char tmp;
            cin >> tmp;
            str1.push_back(tmp);
        }
    }
    
    for(int i=0; i<str1.size(); i++)
        cout << str1[i];
    for(int i=0; i<str2.size(); i++)
        cout << str2[i];
    
    return 0;
}

// 시간초과
/*
int main(){
    
    cin >> str;
    cin >> m;
    int cursor = (int) str.size();
    
    for(int i=0; i<m; i++){
        char c;
        cin >> c;
        if(c == 'L'){
            cursor = max(cursor-1,0);
        }
        else if (c == 'D'){
            cursor = min(cursor+1, (int) str.size());
        }
        else if(c == 'B' && cursor > 0){
            string tmp1 = str.substr(0,cursor-1);
            string tmp2 = str.substr(cursor);
            str = tmp1+tmp2;
            cursor = max(cursor-1,0);
        }
        else if( c == 'P'){
            char tmp0;
            cin >> tmp0;
            string tmp1 = str.substr(0,cursor);
            string tmp2 = str.substr(cursor);
            str = tmp1+tmp0+tmp2;
            cursor = min(cursor+1, (int) str.size());
        }
       //cout << "\nstring : " << str << "   cursor : " << cursor <<"\n";
    }
    cout << str;
    return 0;
}
*/

/*
L : 커서를 왼쪽으로 한 칸 옮김
D : 커서를 오른쪽으로 한 칸 옮김
B : 커서 왼쪽에 있는 문자를 삭제함
P $ : $ 라는 문자를 커서 왼쪽에 추가함
 */
