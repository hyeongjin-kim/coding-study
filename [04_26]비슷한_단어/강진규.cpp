#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dat[26];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	string original;
	cin >> original;
	for (int i = 0;i < original.length();++i)
		++dat[original[i] - 'A'];
	int res = 0;
	for (int i = 0;i < N - 1;++i) {
		string inp;
		cin >> inp;
		int m[26] = { 0 };
		for (int idx = 0;idx < inp.length();++idx)
			++m[inp[idx] - 'A'];
		int diff = 0;
		for (int i = 0;i < 26;++i)
			diff += abs(dat[i] - m[i]);
		if (original.length() == inp.length()) {
			if (diff < 3)
				++res;
		}
		else if (diff < 2)
			++res;
	}
	cout << res;
	return 0;
}
