#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string W;
		map<char, vector<int>> m;
		int K;
		int firstCase = -1, secondCase = -1;
		cin >> W >> K;
		for (int i = 0; i < W.length(); i++)
			m[W[i]].push_back(i);
		for (auto it = m.begin(); it != m.end(); it++) {
			vector<int> cur = it->second;
			for (int i = 0; i < (int)cur.size() - K + 1; i++) {
				if (firstCase == -1)
					firstCase = cur[i + K - 1] - cur[i] + 1;
				else
					firstCase = min(firstCase, cur[i + K - 1] - cur[i] + 1);
				if(secondCase == -1)
					secondCase = cur[i + K - 1] - cur[i] + 1;
				else
					secondCase = max(secondCase, cur[i + K - 1] - cur[i] + 1);
			}
		}

		if (firstCase == -1 || secondCase == -1)
			cout << -1 << '\n';
		else
			cout << firstCase << ' ' << secondCase << '\n';


	}
	return 0;
}
