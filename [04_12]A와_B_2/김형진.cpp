#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//cur: 지금 만들어진 문자열
//S: 원본 문자열
//T: 만들고 싶은 문자열
string cur, S, T;

//문자열이 만들어졌는가?
bool found = false;;

//원본 -> 결과로 가면 A를 추가하는 방법이나 B를 추가하는 방법을 모두 시도해야 한다.
//따라서 2^(T.size() - S.size())만큼 필요하다.
//반대로, 결과 -> 원본으로 가면, 결과에서 시도할 수 있는 방법이 한정적이다.
//따라서 찾아볼 수 있는 경우의 수가 훨씬 적어지고, T를 만드는 것이 불가능한 경우도 빨리 찾을 수 있다.
void recur() {
	//이미 찾았으면 리턴
	if (found) return;
	//찾으면 찾았다는 플레그를 세우고 리턴
	if (cur == S) {
		found = true;
		return;
	}
	//현재 문자열과 원본의 길이가 같다면 방법을 더이상 시도할 방법이 없음
	if (cur.size() == S.size()) return;

	//옵션 1 [A를 뒤에 넣는다]를 거꾸로 해서 뒤에서 A를 뺌
	//맨 뒤에 A가 있어야만 가능
	if (*cur.rbegin() == 'A') { //맨 뒤를 빨리 찾기 위한 rbegin()
		cur.pop_back(); //맨 뒤의 A를 제거
		recur(); //바꾼 문자열로 다시 검사
		if (found) return; //재귀속에서 답을 찾았으면 리턴
		cur.push_back('A'); //시도해본 방법 복구
	}
	//옵션 2 [B를 뒤에 넣고 문자열을 뒤집는다.]를 거꾸로 해서 문자열을 뒤집고 앞에서 B를 뺌
	if (*cur.begin() == 'B') {
		reverse(cur.begin(), cur.end()); //문자열 뒤집기
		cur.pop_back(); //맨 뒤의 B 제거
		recur(); //바꾼 문자열로 다시 검사
		if (found) return; //재귀속에서 답을 찾았으면 리턴
		//시도해본 방법 복구
		cur.push_back('B');
		reverse(cur.begin(), cur.end());
	}

}

int main() {

	cin >> S >> T;
	cur = T;
	recur();
	cout << found;
	return 0;
}