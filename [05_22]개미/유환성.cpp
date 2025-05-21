#include <iostream>
#include <climits>
using namespace std;


int length, ant_cnt;
int ant[100001];

int l_left;
int r_left;
int l_right;
int r_right;

int fast_ans;
int slow_ans;

void init() {
	l_left = length / 2;
	l_right = 0;
	r_left = length;
	r_right = length / 2;


}

int main() {

	int T;
	int pos;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		cin >> length >> ant_cnt;
		init();
		for (int i = 0; i < ant_cnt; i++) {
			
			cin >> pos;

			if (length / 2 < pos) {	//오른쪽 구역 개미
				if (pos < r_left) r_left = pos;
				if (r_right < pos) r_right = pos;
			}
			else {	//왼쪽 구역 개미
				if (pos < l_left)l_left = pos;
				if (l_right < pos) l_right = pos;
			}
		}


		if (l_left < (length - r_right)) slow_ans = length  - l_left;
		else slow_ans = r_right;

		if ((length / 2 - l_right) < (r_left - length / 2)) fast_ans = l_right;
		else fast_ans = length - r_left;

		cout << fast_ans << " " << slow_ans << "\n";

	}

	return 0;
}
