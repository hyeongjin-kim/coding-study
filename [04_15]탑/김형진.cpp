#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    
	cin >> N;
	int t;
    //stack에는 반드시 오름차순으로 들어가 있어야 함
    //왜냐? i번째에 높이 h인 탑이 세워지면 h보다 낮은 탑이 쏘는 신호는 모드 이 i번째 탑이 받을 거니까
    //이보다 앞에 있는 탑중 h보다 낮은 탑은 더이상 신호를 받을 수 없음
	stack<pair<int, int>> s;
    
	for (int i = 0; i < N; i++) {
		cin >> t;
        //i번째 탑보다 낮은 탑은 모두 제거
		while (!s.empty()) {
			if (s.top().first > t) break;
			s.pop();
		}
		if (!s.empty()) cout << s.top().second + 1 << ' '; //i번째 탑보다 높은 탑이 있다면 그 탑이 신호를 받음
		else cout << '0' << ' '; //아니라면 스텍이 비어있게 됨 0출력
        s.push({ t, i }); //새로운 탑을 스텍에 삽입
				
	}
	return 0;
}