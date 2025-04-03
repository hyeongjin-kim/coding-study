#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
int n;
using namespace std;

string dp[251];

string calc(int k) {
	int carry = 0;
	int p1 = dp[k - 1].length() - 1;
	int p2 = dp[k - 2].length() - 1;
	string str="";
	while ((p1 >= 0 && p2 >= 0) || carry > 0) {
		int res=0;
		if (p1 >= 0) res += (dp[k - 1][p1--] - '0');
		if (p2 >= 0) res += (dp[k - 2][p2--] - '0')*2;
		if (carry > 0) res += carry;

		str += res % 10 + '0';
		carry = res / 10;

	}
	reverse(str.begin(), str.end());
	return str;

}

int main() {

//ㅇㅈ 왜 못채우는데 채우는 경우의 수가 1임?!
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";


	for (int i = 3; i < 251; i++) {
		string str =calc(i);
		dp[i] = str;
	}


	while (cin >> n) {
		cout << dp[n]<<"\n";
	}
	return 0;
}
