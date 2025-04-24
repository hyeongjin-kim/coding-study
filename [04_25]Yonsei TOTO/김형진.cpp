#include <iostream>
#include <queue>
using namespace std;

int sub[100]; //각 과목의 정원수
int cnt[100]; //각 과목의 수강신청 인원 수
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M, mile, point;
	
	cin >> N >> mile;

	int ans = 0;
    //<투자한 마일리지, 과목 번호>를 담는 pq
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<> > pq;

	for (int i = 0; i < N; i++) {
		cin >> cnt[i] >> sub[i];
		if (cnt[i] < sub[i] and mile > 0) { //애초에 수강신청 인원이 정원보다 적으면 이 과목을 1점만 투자해 신청
			sub[i] = -1; //더이상 보지 않도록 정원 수를 -1로 만듬
			mile--; //1점만 투자
			ans++; //수강한 과목 증가
		}
		for (int j = 0; j < cnt[i]; j++) {
			cin >> point;
			if(sub[i] != -1) pq.push({point, i});
		}
	}

	
	while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();
		int p = cur.first, s = cur.second;
        if(p > mile) break; //현재 과목의 마일리지가 남은 마일리지보다 크면 이 뒤로는 이보다 작은 마일리지가 없으므로 끝
		if(sub[s] == -1) continue; //이미 신청된 과목이면 넘어감
        else if (sub[s] < cnt[s]) cnt[s]--; //현재 신청한 수가 정원수보다 크면 이 마일리지로는 수강신청할 수 없음
		else if (sub[s] == cnt[s]) { //현재 신청한 수가 정원수와 같으면 이 마일리지로 이 과목을 수강할 수 있음(같은 점수면 내가 우선이므로)
			if (mile >= p) {
				mile -= p; //마일리지 투자
				sub[s] = -1; //더이상 보지 않도록 정원 수를 -1로 만듬
				ans++; //수강한 과목 증가
				if (mile == 0) break;
			}
		}
	}
	cout << ans;
	return 0;

}