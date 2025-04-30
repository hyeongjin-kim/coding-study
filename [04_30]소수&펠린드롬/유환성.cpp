#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int N;


// 1. N 보다 이상인 소수 찾기
// 2. 해당 소수가 펠린드롬인지 확인하기
// 3. 1,2번 조건이 맞으면 출력
// 6번 틀렸습니다


bool check_decimal(int v) {
	if (v == 1) return false;
	else if (v == 2) return true;
	else {
		for (int i = 2; i <= sqrt(v); i++) {
			if (v % i == 0) return false;
		}
	}

	return true;
}

bool palindrome(int v) {

	string str = to_string(v);

	int size = str.size();
	
	for (int i = 0; i < size / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) return false;
	}

	return true;
}

int main() {

	cin >> N;


	for (int i = N; i <= 21e8; i++) {
		if (check_decimal(i)&& palindrome(i)) {	//소수이면서 pal
			cout << i;
			return 0;
		}
	}

}
