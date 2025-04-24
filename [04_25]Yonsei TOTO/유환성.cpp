#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	1. PQ를 이용해서 해당 과목을 수강할 수 있는 최소한의 마일리지 구하기
	2. 해당 값을 Vector에 push
	3. Vector를 오름차순 정렬하여 현재 마일리지로 들을 수 있는 최대 과목의 개수 구하기
*/

int class_cnt; 
int mileage_mine;
int ans;
vector<int> vect;

int main() {
	cin >> class_cnt >> mileage_mine;


	for(int i=0; i<class_cnt;i++){
		int want_people, seat, mileage_others;
		cin >> want_people >> seat;

		priority_queue<int> PQ;

		for (int j = 0; j < want_people; j++) {
			cin >> mileage_others;
			PQ.push(mileage_others);
		}

		for (int j = 0; j < seat-1; j++) {	// n번째 마일리지로 먹으려면 n-1번째의 값을 보면 됨
			// 만약 신청인원이 인원제한 수 보다 적으면 그만
			if (PQ.empty()) break;
			else PQ.pop();
		}

		if (PQ.empty()) vect.push_back(1);
		else vect.push_back(PQ.top());
	}

	sort(vect.begin(), vect.end(), greater<>());

	// vector가 차 있고 마일리지 신청이 가능할 때만
	while (!vect.empty() && mileage_mine >= 0) {
		int cur = vect.back();
		vect.pop_back();
		mileage_mine -= cur;
		ans++;
	}


	if (mileage_mine < 0) ans--;

	cout << ans;

	return 0;
}
