#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool flag;

string S;

void rec(string cur) {
	if (cur.length() == S.length()) {
		if (cur == S)
			flag = true;
		return;
	}
	if (cur.back() == 'A')
		rec(cur.substr(0, cur.length() - 1));
	if (flag) return;
	if (cur.front() == 'B') {
		reverse(cur.begin(), cur.end());
		rec(cur.substr(0, cur.length() - 1));
	}
}

int main(void) {
	string T;
	cin >> S >> T;

	rec(T);

	cout << flag;
	return 0;
}
