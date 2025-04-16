#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char sevenSeg[10] = { 0b1110111, 0b10010, 0b1011101, 0b1011011, 0b111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011 };
char mask = 0b1;

int N, K, P;
int X[6];
int res;

void rec(int depth, int diff, int acc) {
	if (diff > P) return;
	if (depth == K) {
		if (diff <= P && acc <= N && diff > 0 && acc > 0)
			++res;
		return;
	}
	for (int i = 0;i < 10;++i) {
		char tmp = sevenSeg[X[depth]] ^ sevenSeg[i];
		int curDiff = 0;
		for (int i = 0;i < 7;++i) {
			curDiff += tmp & mask;
			tmp >>= 1;
		}
		rec(depth + 1, diff + curDiff, acc * 10 + i);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	cin >> N >> K >> P >> tmp;
	string s = to_string(tmp);
	int idx = 0;
	for (int i = K - s.length();i < K;++i)
		X[i] = s[idx++] - '0';
	rec(0, 0, 0);
	cout << res;
	return 0;
}
