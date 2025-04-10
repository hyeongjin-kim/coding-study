#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> vect;
vector<char> path;
vector<char> vower;

int C, L;
int visited[16];

void printAll() {
	for (int i = 0; i < path.size(); i++) {
		cout << path[i];
	}
	cout << "\n";
}
bool check() {
	int c=0;
	int v=0;
	for (int i = 0; i < path.size(); i++) {
		switch (path[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': v++; break;
		default: c++;
		}
	}
	if (v >= 1 && c >= 2) return true;
	else return false;

}
void solution(int level, int k) {

	if (level == L) {
		if(check()) printAll();
		return;
	}

	for (int i = k; i < vect.size(); i++) {
		if (visited[i])continue;
		visited[i] = 1;
		path.push_back(vect[i]);
		solution(level + 1, i);
		path.pop_back();
		visited[i] = 0;
	}


}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;

		vect.push_back(c);
	}

	sort(vect.begin(), vect.end());

	solution(0,0);

	return 0;
}
