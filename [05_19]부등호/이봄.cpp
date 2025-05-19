#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k;
vector<int> path;
bool visited[10];
vector<int> order;
string min_str = "999999999999999999";
string max_str;

void Print() {
	for (int i = 0; i < (int) path.size(); i++)
		cout << path[i];
	cout << "\n";
}

bool Check() {
	int idx = 0;
	for (int i = 0; i < (int)path.size()-1 ; i++) {
		int a = path[i];
		int b = path[i + 1];
		int c = order[idx++];
		if (c == 0) {
			if (a < b)
				continue;
			else
				return false;
		}
		else if (c == 1) {
			if (a > b)
				continue;
			else
				return false;
		}
	}
	return true;
}


void Backtracking(int cnt) {
	if (cnt == k+1) {
		if (Check()) {
			string str = "";
			for (int i = 0; i < (int)path.size(); i++) {
				str += to_string(path[i]);
			}
			min_str = min(min_str, str);
			max_str = max(max_str, str);
		}
		
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			path.push_back(i);
			Backtracking(cnt + 1);
			path.pop_back();
			visited[i] = false;
		}
	}

	return;
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> k;

	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == '<')
			order.push_back(0);
		else
			order.push_back(1);
	}

	Backtracking(0);

	cout << max_str << "\n" << min_str;
	return 0;
}

/*
부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 출력 
*/
