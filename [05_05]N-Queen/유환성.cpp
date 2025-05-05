#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> path;

int N;
int visited[16];
int ans;
bool CheckDiag(int row, int col) {
	//대각선 체크
	// 0 : path.size()까지 순회하며, 각각 대각선 겹치는게 있는지 확인 

	for (int i = 0; i < row; i++) {
		if (i - path[i] == row - col) return false;
		if (i + path[i] == row + col) return false;
	}

	return true;


}

void printA() {

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
	cout << "\n";
}

void solution(int level) {

	if (level >= N) {
		//printA();
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		if (!CheckDiag(level, i))continue;
		visited[i] = 1;
		path.push_back(i);
		solution(level + 1);
		path.pop_back();
		visited[i] = 0;

	}

}

int main() {

	cin >> N;

	solution(0);

	cout << ans;

	return 0;
}
