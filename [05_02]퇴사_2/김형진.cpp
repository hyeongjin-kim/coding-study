#include <iostream>
#include <algorithm>
using namespace std;


int ans[1500002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, today, days, pay;

	cin >> N;
  //ans[i] : i번째 날 아침에 얻을 수 있는 최대 수익
	for (int i = 1; i <= N; i++) {
		cin >> days >> pay;
    //i번째 일 전까지의 최대 수익은 전날 아침의 최대 수익과 비교해서 큰 쪽
		ans[i] = max(ans[i - 1], ans[i]);
    //이날 상담이 퇴사일을 초과하면 계산 안함
		if ((i + days - 1) > N) continue;
		//이날 시작하는 상담을 할지 말지 결정
    ans[i + days] = max(ans[i] + pay, ans[i + days]);
	}
	//퇴사일 전까지의 최대 수익은 전날 아침의 최대 수익과 비교해서 큰 쪽
	cout << max(ans[N + 1], ans[N]);

	return 0;
}
