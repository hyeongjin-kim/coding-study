#include <iostream>
using namespace std;


int N;
int T, P;

struct dm {
	int day;
	int money;
};

dm map[1500005];
int result[1500005];
// 상담을 완료하는 기간 : T, 상담 시 받는 금액 : P
// 1. N+1일 째 되는 날 퇴사하기 위해, N일 동안 최대한 많은 상담
// 상담을 했을 때, 백준이가 얻을 수 있는 최대 수익은?

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		map[i] = { T,P };
	}

	for (int i = N; i >=1; i--) {

		// 퇴사 후에는 회사에 못 나오므로 안 받아들임
		if (N < i + map[i].day-1) {
			result[i] = result[i+1];
			continue;
		}
		//상담을 할 지, 안할 지 결정? : 이득이 되는지 판단
		result[i] = max(result[i + 1], result[i + map[i].day] + map[i].money);
		
	}
	
	cout << result[1];



	return 0;
}
