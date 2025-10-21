#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct node {
	int x;
	int y;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		int n;
		bool flag = false;
		cin >> n;

		map<int, vector<int>> arr;
		

		for (int i = 0; i < n; i++) {
			int y, x;
			cin >> y >> x;
			arr[y].push_back(x);
		}
		map<int, vector<int>> ::iterator it;
		map<int, vector<int>> ::iterator its;
		
		for (it = arr.begin(); it != arr.end(); it++) {
			sort(it->second.begin(), it->second.end());
		}

		for (it = arr.begin(); it != arr.end(); it++) {
			if (flag) break;
			for (its = arr.begin(); its != arr.end(); its++) {
				if (it->first == its->first) continue;
				if (it->second != its->second) {
					flag = true;
					break;
				}
			}
		}

		if (flag) cout << "NOT BALANCED" << "\n";
		else cout << "BALANCED" << "\n";
	}
	return 0;
}
