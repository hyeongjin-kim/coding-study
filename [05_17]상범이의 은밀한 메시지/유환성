#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
	1. 암호화된 pw에 대해 key의 경우 구하기
	2.1 키의 경우가 반복되는 구조면 O
	2.2 키의 경우가 반복되지 않으면 X
	3. 구한 키의 1~N까지 rotate하며 original_pw 찾기 (see_pw가 포함 되어있나?)
*/

string encoded_pw;
string original_pw;
string see_pw;
string key_case;
string key;

void get_key_case(int idx) {
	//key의 case 구하기

	key_case = "";

	for (int i = 0; i < see_pw.size(); i++) {
		int t = ((encoded_pw[idx + i] - 'a') - (see_pw[i] - 'a'));
		if (t < 0) t += 26;

		key_case += t + 'a';
	}

}

bool check_key_repeat() {
	//반복되면 1, 아니면 0
	key = "";
	key += key_case[0];
	int idxcnt=0;
	while (key.size() <= key_case.size()/2) {
		
		  // t만큼 반복되는 지 확인, 반복되면 return 1;
		  // 반복되지 않으면 t에 추가, continue;
		bool flag = true;

		for (int i = 0; i < key_case.size(); i++) {
			if (key[i % key.size()] != key_case[i]) {
				flag = false;
			}
		}
		idxcnt++;
		if (flag) return true;
		else key += key_case[idxcnt];

	}
	return false;
}
bool decoding() {
	//오리지널 pw를 구하면 1, 아니면 0
	// key의 size가 3이면 0, 1, 2부터 시작해서 돌려보기
	string calc_result;
	for (int i = 0; i < key.size(); i++) {
		calc_result = "";

		for (int j = 0; j < encoded_pw.size(); j++) {
			calc_result += encoded_pw[j] - key[(i + j) % key.size()];
			if (calc_result[j] < 0) calc_result[j] += 26;

			calc_result[j] += 'a';
		}
		auto it = calc_result.find(see_pw);
		if (it != string::npos) {
			original_pw = calc_result;
			return true;
		}

	}
	return false;
}


void solution() {

	int pw_size = encoded_pw.size();
	int see_pw_size = see_pw.size();

	for (int i = 0; i <= pw_size - see_pw_size; i++) {
		get_key_case(i);
		if (!check_key_repeat())continue;
		if (!decoding())continue;

		return;
	}

}

int main() {

	cin >> encoded_pw;
	cin >> see_pw;

	solution();
	cout << original_pw;

	return 0;
}
