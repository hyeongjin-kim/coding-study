#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	string inp;
	cin >> inp;
	int totalLength = inp.length();
	char target = 'c';
	int minDiff = 1000;
	int aN = count(inp.begin(), inp.end(), 'a');
	int bN = count(inp.begin(), inp.end(), 'b');
	int searchLen = aN;
	inp = inp + inp;
	if (aN > bN) {
		target = 'a';
		searchLen = bN;
	}
	else if (aN < bN) {
		target = 'b';
		searchLen = aN;
	}
	if(target=='c')
		for (int i = 0;i <= totalLength;i++)
			minDiff = min(minDiff, (int)min(count(inp.begin() + i, inp.begin() + i + searchLen, 'a'), count(inp.begin() + i, inp.begin() + i + searchLen, 'b')));
	else
		for (int i = 0;i <= totalLength;i++)
			minDiff = min(minDiff, (int)count(inp.begin() + i, inp.begin() + i + searchLen, target));
	
	cout << minDiff;
	return 0;
}
