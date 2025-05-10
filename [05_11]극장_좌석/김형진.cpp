#include <iostream>

using namespace std;

//i번째 사람과 i-1번째 사람이 자리를 바꾼 경우
int swap_seat[41] = {0};
//i번째 사람과 i-1번째 사람이 자리를 바꾸지 않은 경우
int no_swap_seat[41] = {0, 1};

//vip정보
bool vip[41];
int N, M;


int main() {

	cin >> N >> M;
	int ans = 0;

	int p;
	for (int i = 0; i < M; i++) {
		cin >> p;
		vip[p] = true;
	}
	

	for (int i = 2; i <= N; i++) {
        //앞사람이 vip이거나 지금 사람이 vip면 앞사람과 바꿀 수 없음
		if (vip[i - 1] or vip[i]) {
			swap_seat[i] = 0;
            //이 앞에서는 swap이 있었든, 없었든 상관 없음
            //앞사람이 vip이고 지금 사람도 vip인 경우에도 swap_seat[i -1] = 0이므로 상관 없음
			no_swap_seat[i] = no_swap_seat[i - 1] + swap_seat[i - 1];
		}
		else {
            //지금 자리를 바꾸려면 앞에서는 자리를 바꿨으면 안됨
			swap_seat[i] = no_swap_seat[i - 1];
            //지금 자리를 바꾸지 않는다면 앞에서는 swap이 있었든, 없었든 상관 없음
			no_swap_seat[i] = no_swap_seat[i - 1] + swap_seat[i - 1];
		}
	}
    //최종 결과 합산
	cout << no_swap_seat[N] + swap_seat[N];

	return 0;
}