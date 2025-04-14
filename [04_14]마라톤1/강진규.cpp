#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int curMaxDiff = 0;
	int firstDist, secondDist = 0;
	pair<int, int> first, second;
	cin >> first.first >> first.second >> second.first >> second.second;
	firstDist = abs(first.first - second.first) + abs(first.second - second.second);
	long long totalDist = 0;
	for (int i = 2; i < N; i++) {
		totalDist += firstDist;
		int curx, cury;
		cin >> curx >> cury;
		secondDist = abs(curx - second.first) + abs(cury - second.second);
		int crossDist = abs(curx - first.first) + abs(cury - first.second);
		if (curMaxDiff < firstDist + secondDist - crossDist) {
			curMaxDiff = firstDist + secondDist - crossDist;
		}
		swap(first, second);
		second = { curx, cury };
		firstDist = secondDist;
	}
	totalDist += secondDist;

	cout << totalDist - curMaxDiff;
	return 0;

}
