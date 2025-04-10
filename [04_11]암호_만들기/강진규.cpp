#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char acc[16];
int L, C;
char inp[16];

void rec(int depth, int N, int cN, int vN) {
	if (depth == L) {
		cout << acc << "\n";
		return;
	}
	for (int i = N;i < C;i++) {
		if (L - depth > C - i)
			return;
		int newCN = cN;
		int newVN = vN;
		if (inp[i] == 'a' || inp[i] == 'e' || inp[i] == 'i' || inp[i] == 'o' || inp[i] == 'u')
			++newVN;
		else
			++newCN;
		if (L - depth + newCN < 3 || L - depth + newVN < 2)
			continue;
		acc[depth] = inp[i];
		rec(depth + 1, i + 1, newCN, newVN);
		acc[depth] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	cin >> L >> C;
	for (int i = 0;i < C;i++) {
		cin >> inp[i];
	}
	sort(inp, inp + C);
	rec(0, 0, 0, 0);
	return 0;
}
