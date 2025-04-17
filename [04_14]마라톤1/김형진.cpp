#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	//각각 첫번째, 두번째, 세번째 지점의 좌표
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2;

	//첫번째와 두번째 지점 사이의 거리, 두번째와 세번째 지점 사이의 거리
	int dist1 = abs(x1 - x2) + abs(y1 - y2), dist2;
	//합계
	int sum = dist1;
	
	//특정 지점을 건너뛰고 갔을 때 얻는 이득의 최대치
	int m = 0;
	for (int i = 2; i < N; i++) {
		cin >> x3 >> y3;
		//두번째와 세번째 지점 사이의 거리 계산
		dist2 = abs(x2 - x3) + abs(y2 - y3);
		
		//합계에 합산
		sum += dist2;
		//첫번째 지점에서 두번째 지점을 건너뛰고 세번째 지점으로 바로 갔을 때 얻는 이득은
		//각 지점 사이의 거리의 합에서 첫번째 지점과 세번째 지점 사이의 거리의 차
		m = max((dist1 + dist2) - (abs(x1 - x3) + abs(y1 - y3)), m);
		x1 = x2;
		x2 = x3;
		y1 = y2;
		y2 = y3;
		dist1 = dist2;
	}
	//전체 합에서 특정 지점을 건너뛰고 갔을 때 얻는 이득의 최대치를 뺀 것이 정답
	cout << sum - m;

	return 0;
}