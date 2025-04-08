#include <iostream>
using namespace std;

string str;

int pa, pb;
int ans = 21e8;
void calc() {
	pa = 0;
	pb = str.size() - 1;
	int temp_ans=0;
	while (pa < pb) {
		if (str[pa] == 'a' && str[pb] == 'b') {
			pa++;
			pb--;
			temp_ans++;
		}
		else if (str[pa] == 'a') {
			pb--;
		}
		else if (str[pb] == 'b') {
			pa++;
		}
		else {
			pa++;
			pb--;
		}

	}
	if (temp_ans < ans) ans = temp_ans;
}

int main() {
	cin >> str;
	int size = str.size();
	
	for (int i = 0; i < size; i++) {
		int t = *str.begin();
		str.erase(str.begin());
		str += t;

		calc();
	}
	cout << ans;
	return 0;
}
