#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string inp;
	cin >> inp;

	list<char> l;
	for (int i = 0;i < inp.length();++i)
		l.push_back(inp[i]);
	int M;
	cin >> M;
	auto cursor = l.end();
	for (int i = 0;i < M;++i) {
		char c;
		cin >> c;
		switch (c) {
		case 'L':
			if (cursor != l.begin())
				--cursor;
			break;
		case 'D':
			if (cursor != l.end())
				++cursor;
			break;
		case 'B':
			if (cursor != l.begin()) {
				cursor = l.erase(--cursor);
			}
			break;
		case 'P':
			char tmp;
			cin >> tmp;
			l.insert(cursor, tmp);
		}
	}
	inp = "";
	for (auto it = l.begin();it != l.end();++it)
		inp += *it;

	cout << inp;
	return 0;
}
