#include <iostream>
#include <algorithm>
using namespace std;

string S;
int ans;

void solution(string T) {

	string temp = T;
	if (temp.empty()) return;
	if (temp == S) {
		ans = 1;
		return;
	}

	if (temp.back() == 'A') {
		temp.erase(temp.end() - 1);
		solution(temp);
		temp += 'A';
	}
	if (temp.front() == 'B') {
		reverse(temp.begin(), temp.end());
		temp.erase(temp.end()-1);
		solution(temp);
		temp += 'B';
		reverse(temp.begin(), temp.end());

	}

}


int main() {
	string T;
	cin >> S >> T;

	solution(T);
	cout << ans;
	return 0;
}
