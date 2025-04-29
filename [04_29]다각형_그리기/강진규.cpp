#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int N;
	string original, original2 = "";
	vector<string> v;
	cin >> N;
	cin.ignore();
	getline(cin, original);
	for (int i = original.length() - 1;i >= 0;--i) {
		if (original[i] != ' ')
			original2 += (original[i] - '1' + 2) % 4 + '1';
		else
			original2 += " ";
	}
	original += " " + original;
	original2 += " " + original2;
	cin >> N;
	cin.ignore();
	for (int i = 0;i < N;++i) {
		string inp;
		getline(cin, inp);
		if (original.find(inp) != string::npos || original2.find(inp) != string::npos)
			v.push_back(inp);
	}
	cout << v.size() << "\n";
	for (int i = 0;i < v.size();++i)
		cout << v[i] << "\n";
	return 0;
}
