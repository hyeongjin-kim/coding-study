#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

string path;
string arr[20];
int R, C, maxDepth;
int xpos[] = { 0,0,-1,1 };
int ypos[] = { -1,1,0,0 };

void rec(int depth, int x, int y) {
	maxDepth = max(maxDepth, depth);
	for (int d = 0; d < 4; d++) {
		int nx = x + xpos[d];
		int ny = y + ypos[d];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		if (path.find(arr[nx][ny]) != string::npos) continue;
		path += arr[nx][ny];
		rec(depth + 1, nx, ny);
		path.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> arr[i];
	path += arr[0][0];
	rec(1, 0, 0);
	cout << maxDepth;
	return 0;
}
