#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

bool primeCheck[1010001];

bool palCheck(int n) {
	string s = to_string(n);
	auto left = s.begin();
	auto right = s.end() - 1;
	bool flag = true;
	while (left < right) {
		if (*left != *right) {
			flag = false;
			break;
		}
		++left;
		--right;
	}
	return flag;
}

int main(void) {
	int N;
	cin >> N;
	fill(primeCheck, primeCheck + 1010001, true);
	set<int> prime;
	for (int i = 2;i < 1010001;++i) {
		if (!primeCheck[i]) continue;
		for (int j = i * 2;j < 1010001;j += i)
			primeCheck[j] = false;
		if (palCheck(i))
			prime.insert(i);
	}
	cout << *(prime.lower_bound(N));
	return 0;
}
