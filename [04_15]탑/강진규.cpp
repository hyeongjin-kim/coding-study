#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	stack<pair<int,int>> s;
	int N;
	cin >> N;
	for (int i = 0;i < N;++i) {
		int inp;
		cin >> inp;
		while(!s.empty()) {
			if (s.top().second >= inp)
				break;
			s.pop();
		}
		if (s.empty()) {
			cout << "0 ";
		}
		else {
			cout << s.top().first << " ";
		}
		s.push({ i + 1,inp });
	}
	return 0;
}
