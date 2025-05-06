#include <iostream>
#include <queue>
using namespace std;
int N;
string ori;
string temp;
string tar;
int ans = 21e8;
int cnt;
void toggle(int idx) {
	ori[idx] = ('1' - ori[idx]) + '0';
}

void PushSwitch(int idx) {

	if (idx == 0) {
		toggle(idx);
		toggle(idx + 1);
	}
	else if (idx == N-1) {
		toggle(idx - 1);
		toggle(idx);
	}
	else {
		toggle(idx - 1);
		toggle(idx);
		toggle(idx + 1);
	}
	cnt++;

}
void init() {
	cnt = 0;
	ori = temp;
}
void solution(int zeroS) {

	if (zeroS == 1) {PushSwitch(0);}
	
	for (int idx = 1; idx < N; idx++) {
		if (ori[idx - 1] == tar[idx - 1]) continue;
		PushSwitch(idx);
	}

	if (ori == tar) {
		if(ans > cnt) ans = cnt;
	}

}

int main() {
	cin >> N;
	cin >> temp >> tar;

	init();
	solution(0);	//0번 스위치를 안 눌렀을 때
	init();
	solution(1);	//0번 스위치를 눌렀을 때 

	if (ans == 21e8) cout << -1;
	else cout << ans;

	return 0;
}
