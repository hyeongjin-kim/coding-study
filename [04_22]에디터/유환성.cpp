#include <iostream>
#include <list>
using namespace std;

string s;
list<char> str;
int N;
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> N;

	int size = s.size();

	for (char c : s) {
		str.push_back(c);
	}

	char cmd;
	char c;
	auto cursor = str.end();
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		
		switch (cmd)
		{
		case 'L': 
			if (cursor == str.begin()) continue;
			cursor--;
			break;
		case 'D': 
			if (cursor == str.end())continue;
			cursor++;
			break;
			
		case 'B':
			if (cursor == str.begin()) continue;
			cursor--;
			cursor = str.erase(cursor);
			break;
		case 'P':
			cin >> c;
			cursor = str.insert(cursor, c);
			cursor++;
			break;
		default:
			break;
		}

	}

	for (auto c : str) {
		cout << c;
	}




}
