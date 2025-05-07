
#include <iostream>
#include <string>

using namespace std;

int n;
string str0;
string str1;
string str2;
int cnt = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> str0 >> str2;

	str1 = str0;
	// 1번째 칸 안 켜주는 경우 

	for (int i = 1; i < n; i++) {
		if (str1[i - 1] != str2[i - 1]) {
			cnt++;
			str1[i-1] = (str1[i-1] == '0') ? '1' : '0';
			str1[i] = (str1[i] == '0') ? '1' : '0';
			if(i+1 < n)
				str1[i+1] = (str1[i+1] == '0') ? '1' : '0';
		}
	}

	if (str1 == str2) {
		cout << cnt;
		return 0;
	}
	
	str1 = str0;
	cnt = 1;
	// 1번째 칸 켜주는 경우
	str1[0] = (str1[0] == '0') ? '1' : '0';
	str1[1] = (str1[1] == '0') ? '1' : '0';
	
	for (int i = 1; i < n; i++) {
		if (str1[i - 1] != str2[i - 1]) {
			cnt++;
			str1[i - 1] = (str1[i - 1] == '0') ? '1' : '0';
			str1[i] = (str1[i] == '0') ? '1' : '0';
			if (i + 1 < n)
				str1[i + 1] = (str1[i + 1] == '0') ? '1' : '0';
		}
	}

	if (str1 == str2) {
		cout << cnt;
		return 0;
	}
	else
		cout << -1;

	return 0;
}
