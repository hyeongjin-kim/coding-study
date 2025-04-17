#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		long long* inp = new long long[N];
		long long accN = 0;
		long long curSell;
		long long accBuy = 0;
		long long accProfit = 0;
		for (int i = 0; i < N; i++) {
			cin >> inp[i];
		}
		curSell = inp[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			if (curSell < inp[i]) {
				accProfit += curSell * accN - accBuy;
				curSell = inp[i];
				accN = 0;
				accBuy = 0;
			}
			else {
				accN++;
				accBuy += inp[i];
			}


		}
		if (accN) {
			accProfit += curSell * accN - accBuy;
		}
		cout << accProfit << "\n";


		delete[] inp;
	}
	return 0;
}