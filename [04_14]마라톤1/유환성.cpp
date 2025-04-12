#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;
struct point {
	int x;
	int y;
};
vector<point> vect;
int Maxidx;
int Max;
int ans;

//i에서 i+1까지 가는 데 걸리는 값 계산
int calc(int i) {
	
	int res = 0;
	res += abs(vect[i + 1].x - vect[i].x) + abs(vect[i + 1].y - vect[i].y);
	return res;
}
//i-1에서 i+1까지 가는 데 걸리는 값 계산
int calc2(int i) {

	int res = 0;
	res += abs(vect[i + 1].x - vect[i-1].x) + abs(vect[i + 1].y - vect[i-1].y);

	return res;
}

int main() {
	cin >> N;
	vect.resize(N + 1);

	for (int i = 0; i < N; i++) {
		cin >> vect[i].x >> vect[i].y;
	}

	for (int i = 1; i < N-1; i++) {
		// B를 제외하면서 생긴 이득값은 A->B->C 에서 A->C를 뺀 값
		int a2b = calc(i-1);
		int b2c = calc(i);

		int a2c = calc2(i);

		int res = a2b + b2c - a2c;

		if (Max < res) {
			Max = res;
			Maxidx = i;
		}

	}

	vect.erase(vect.begin() + Maxidx);
	vect.pop_back();

	for (int i = 0; i < vect.size()-1; i++) {
		ans += calc(i);
	}

	cout << ans;

	
	return 0;
}
