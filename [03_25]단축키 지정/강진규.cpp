#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	cin.ignore();
	vector<pair<string, int>> inp; // input, shorcut_offset
	bool alphaIdx[26];
	for (int i = 0; i < 26; i++)
		alphaIdx[i] = false;
	for (int i = 0; i < N; i++) {
		string curInp = "";
		pair<bool, pair<int, char>> candidate = { false,{-1,0} }; // 첫머리 여부, offset, value
		string inpString;
		getline(cin, inpString);
		int idx = 0;
		for(int idx = 0; idx<inpString.length();idx++){
			char c = inpString[idx];
			if (c != ' ') {
				if (!alphaIdx[tolower(c) - 'a']) {
					if (candidate.second.first == -1)
						candidate = { (curInp == "" || curInp.back() == ' '), {curInp.size(), c} };
					else if(!candidate.first && (curInp == "" || curInp.back() == ' '))
						candidate = { true, {curInp.size(), c} };
				}
			}
			curInp += c;
		}
		int shortOffset = candidate.second.first;
		if (shortOffset != -1)
			alphaIdx[tolower(curInp[shortOffset]) - 'a'] = true;
		inp.push_back({ curInp, shortOffset });
	}
	for (int i = 0; i < N; i++) {
		string curInp = inp[i].first;
		for (int j = 0; j < curInp.size(); j++) {
			if (j == inp[i].second) {
				cout << '[' << curInp[j] << ']';
			}
			else
				cout << curInp[j];
		}
		cout << '\n';
	}
	return 0;
}

