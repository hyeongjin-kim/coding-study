#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char inequal[9];

bool visit[10];

int N;

int prev_num;

long long mini = 1e11;
string mini_as_string = "";

long long maxi = 0;
string maxi_as_string = "";

void back_tracking(int index, string s) {
    //다 돌면 최대 최소 갱신
	if (index == N) {
		if (mini > stoll(s)) {
			mini = stoll(s);
			mini_as_string = s;
		}
		if (maxi < stoll(s)) {
			maxi = stoll(s);
			maxi_as_string = s;
		}
		
		return;
	}
    //사용 안 한 수 중에서 현재 인덱스에 해당하는 부등호를 만족하면 진행
	for (int i = 0; i < 10; i++) {
		if (visit[i] == true) continue;
		if (inequal[index] == '<') {
			if (prev_num < i) {
				int temp = prev_num;
				prev_num = i;
				visit[i] = true;
				back_tracking(index + 1, s + (char('0' + i)));
				visit[i] = false;
				prev_num = temp;
			}
		}
		else {
			if (prev_num > i) {
				int temp = prev_num;
				prev_num = i;
				visit[i] = true;
				back_tracking(index + 1, s + (char('0' + i)));
				visit[i] = false;
				prev_num = temp;
			}
		}
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> inequal[i];
	}

    //i를 맨 앞에다 두고 백트래킹 시작
	for (int i = 0; i < 10; i++) {
		prev_num = i;
		visit[i] = true;
		back_tracking(0, to_string(i));
		visit[i] = false;
	}

	cout << maxi_as_string << '\n' << mini_as_string;

	return 0;
}