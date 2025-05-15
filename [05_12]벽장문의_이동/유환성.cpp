#include <iostream>
#include <vector>
using namespace std;


int N;
vector<int> seq;
int cnt;
int o1, o2;
int ans = 21e8;
void input() {
	
	int num;
	int n1, n2;
	cin >> N;
	cin >> n1 >> n2;

	if (n1 < n2) {
		o1 = n1;
		o2 = n2;
	}
	else {
		o1 = n2;
		o2 = n1;
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		seq.push_back(num);
	}


}

void solution(int mov, int depth, int sp, int ep) {

	if (depth == cnt) {

		if (ans > mov) ans = mov;
		return;
	}

	//move의 횟수 바꾸기
	// 목표가 왼쪽에 있을 때
	if (sp > seq[depth]) {
		solution(mov +(sp - seq[depth]), depth + 1, seq[depth], ep);
	}
	// 목표가 오른쪽에 있을 때
	else if (ep < seq[depth]) {
		solution(mov + (seq[depth] - ep), depth + 1, sp, seq[depth]);
	}
	// 목표가 중간에 있을 때
	else {
		//왼쪽 문에서 이동해보기
		solution(mov + (seq[depth] - sp), depth + 1, seq[depth], ep);
		//오른쪽 문에서 이동해보기
		solution(mov + (ep - seq[depth]), depth + 1, sp, seq[depth]);
	}
}

int main() {
	
	input();
	solution(0, 0, o1, o2);

	cout << ans;
	return 0;
}
