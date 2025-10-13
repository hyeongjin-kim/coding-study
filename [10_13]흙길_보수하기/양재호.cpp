#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int s;
	int e;
};

bool cmp(node a, node b) {
	if (a.s < b.s) return true;
	else return false;

	if (a.e < b.e) return true;
	else return false;
	return false;
}
vector<node> arr;

int main() {
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		arr.push_back({ s, e });
	}
	sort(arr.begin(), arr.end(), cmp);

	int cnt = 0;
	int start = 0;
	int idx = 0;

	while (true) {
		node now = arr[idx];
		if (now.s > start) {
			start = now.s + l;
			cnt++;
			if (start > now.e) {
				idx++;
			}
		}
		else if (start < now.e) {
			start += l;
			cnt++;
			if (start > now.e) {
				idx++;
			}
		}
		else if (start >= now.e) {
			idx++;
		}

		if (idx >= n) break;
	}

	cout << cnt;

	return 0;
}
