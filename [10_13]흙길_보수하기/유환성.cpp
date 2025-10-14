#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;

/*
	1. 정렬
	2. 앞에서부터 웅덩이를 널빤지로 감싸고, 남는 부분은 변수에 저장
	3. 다음 웅덩이보다 남은 부분의 값(길이)가 크면 사용
	4. 다음 웅덩이보다 남은 부분의 값이 작으면 버리기
*/
int ans;
vector<pair<int, int>> hole;
void input() {
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		hole.push_back({ s,e });
	}

	sort(hole.begin(), hole.end());
}
void solution() {
	int end_of_panel=0;
	for (auto cur : hole) {
		int s = cur.first+1 > end_of_panel? cur.first+1 : end_of_panel;
		int e = cur.second;

		while (s <= e) {
			s += L;
			ans++;
		}
		end_of_panel = s;

	}
}

int main() {

	input();
	solution();
	cout << ans;

	return 0;
}
