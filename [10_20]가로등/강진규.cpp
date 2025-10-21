#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		unordered_map<int, int> rowCnt;
		unordered_map<int, int> colCnt;
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int r, c;
			cin >> r >> c;
			++rowCnt[r];
			++colCnt[c];
		}

		bool ans = true;

		int rowVal = colCnt.size();
		int colVal = rowCnt.size(); 

		if (ans)
			for (auto curRowVal : rowCnt) {
				if (curRowVal.second != rowVal) {
					ans = false;
					break;
				}
			}
		if (ans)
			for (auto curColVal : colCnt) {
				if (curColVal.second != colVal) {
					ans = false;
					break;
				}
			}

		cout << (ans ? "" : "NOT ") << "BALANCED\n";

	}
	return 0;
}
