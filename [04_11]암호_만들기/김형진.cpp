#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int lastmo = 0; //마지막 모음의 인덱스
int last2ja = 0; //마지막에서 두번째 자음의 인덱스
int lastja = 0; //마지막 자음의 인덱스
int L, C;

char c[15];

void recursive(int idx, int ja, int mo, string s) {
	if (idx > lastmo and mo  < 1) return; //마지막 모음을 넘어갔는데 모음이 없다면 리턴
	if (idx > last2ja and ja < 1) return; //마지막에서 두번째 자음을 넘어갔는데 자음이 없다면 리턴
	if (idx > lastja and ja < 2) return; //마지막 자음을 넘어갔는데 자음이 없다면 리턴
	if (s.length() == L) { //암호를 완성했을 때
		if (ja < 2 or mo < 1) return; //자음이나 모음의 개수가 부족하면 리턴
		cout << s << '\n';
		return;
	}
	if (idx == C) return; //끝까지 다 돌았으면 리턴
	if (c[idx] == 'a' or c[idx] == 'i' or c[idx] == 'o' or c[idx] == 'u' or c[idx] == 'e') { //모음인 경우
		recursive(idx + 1, ja, mo + 1, s + char(c[idx])); //모음 개수를 하나 늘리고 문자열에 추가해서 다시 재귀
	}
	else { //자음인 경우
		recursive(idx + 1, ja + 1, mo, s + char(c[idx])); //자음 개수를 하나 늘리고 문자열에 추가해서 다시 재귀
	}
	recursive(idx + 1, ja, mo, s); //안 넣은 경우도 재귀
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;

	


	for (int i = 0; i < C; i++) {
		cin >> c[i];
	}

	sort(c, c + C); //알파벳순으로 정렬

	for (int i = 14; i >= 0; i--) {
		if (c[i] == 'a' or c[i] == 'i' or c[i] == 'o' or c[i] == 'u' or c[i] == 'e'){ //뒤에서부터 오면서 모음을 발견하면 그 인덱스를 저장하고 break
			lastmo = i;
			break;
		}
	}

	for (int i = C - 1; i >= 0; i--) { //뒤에서부터 오면서 자음을 찾음
		if ( c[i] != 'a' and c[i] != 'i' and c[i] != 'o' and c[i] != 'u' and c[i] != 'e') {
			if (lastja == 0) { //처음 발견한 경우 마지막 자음 인덱스 저장
				lastja = i;
			}
			else { //두번째인 경우 마지막에서 두번째 자음 인덱스 저장하고 break
				last2ja = i;
				break;
			}
		}
		
	}
	recursive(0, 0, 0, ""); //재귀 시작

	return 0;
}
