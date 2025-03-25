#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int T;
    cin >> T;

    //각 알파벳에 단축키가 할당되었는지 확인하기 위한 배열
    int arr[26] = {};
    string s;
    vector<string> answer;
  
    getchar(); //줄바꿈을 버퍼에서 제거
    for (int i = 0; i < T; i++) {

        getline(cin, s); //명령어 받아오기

        //첫글자에 단축키 지정이 안 되어있다면
        if (arr[tolower(s[0]) - 'a'] == 0) {
            arr[tolower(s[0]) - 'a'] = 1; //해당 글자에 단축키 지정
            answer.push_back(s.substr(0, 0) + '[' + s[0] + ']' + s.substr(0 + 1)); //대괄호를 넣어 정답에 넣기
        }

        else { //이후 단어의 공백을 찾아야 함
            auto tar = s.begin(); //찾기 시작할 위치
            while (1) {
                auto idx = find(tar, s.end(), ' '); //공백 찾기
                if (idx == s.end()) { //없다면 처음부터 할당되지 않은 알파벳을 찾음
                    for (int j = 0; j < s.length(); j++) {
                        if (s[j] == ' ') continue;

                        if (arr[tolower(s[j]) - 'a'] == 0) { //할당 가능한 알파벳 발견하면 해당 알파벳에 단축키 지정
                            arr[tolower(s[j]) - 'a'] = 1;
                            answer.push_back(s.substr(0, j) + '[' + s[j] + ']' + s.substr(j + 1));
                            break;
                        }
                        if (j == s.length() - 1) answer.push_back(s); //아예 못찾으면 명령어를 그대로 정답에 넣음

                    }
                    break;
                }
                if (arr[tolower(*(idx + 1)) - 'a'] == 0) { //공백의 뒤에 있는 알파벳에 단축기 지정이 안되어있는 경우 해당 알파벳에 단축키 지정
                    arr[tolower(*(idx + 1)) - 'a'] = 1;
                    answer.push_back(s.substr(0, idx - s.begin() + 1) + '[' + s[idx - s.begin() + 1] + ']' + s.substr(idx - s.begin() + 2));
                    break;
                }
                tar = ++idx; //아니라면 그 뒤에서부터 다시 탐색함
            }
            
            
        }

        
        
    }
    for (string a : answer) cout << a << '\n'; //모든 정답 출력
    return 0;
}
