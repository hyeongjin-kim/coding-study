#include <iostream>
#include <string>

using namespace std;

bool vis[10];
char boo[9];
int k;
string max_string, min_string;

void rec(int depth, string cur) {
	if (depth == k) {
		if (max_string < cur)
			max_string = cur;
		if (min_string > cur)
			min_string = cur;
		return;
	}
	if (boo[depth] == '<') {
		for (char c = cur[cur.size() - 1];c <= '9';++c) {
			if (vis[c - '0'])continue;
			vis[c - '0'] = true;
			rec(depth + 1, cur + c);
			vis[c - '0'] = false;
		}
	}
	else {
		for (char c = cur[cur.size() - 1];c >= '0';--c) {
			if (vis[c - '0'])continue;
			vis[c - '0'] = true;
			rec(depth + 1, cur + c);
			vis[c - '0'] = false;
		}
	}

}

int main(void) {
	cin >> k;
	for (int i = 0;i < k;++i)
		cin >> boo[i];
	max_string = "0000000000";
	min_string = "9999999999";
	string tmp = "";
	for (char c = '0';c <= '9';++c) {
		vis[c - '0'] = true;
		rec(0, tmp + c);
		vis[c - '0'] = false;
	}
	cout << max_string << "\n" << min_string;
	return 0;
}
