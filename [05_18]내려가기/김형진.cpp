#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	
    //왼쪽 숫자, 가운데 숫자, 오른쪽 숫자
	int a, b, c;

    //각칸으로 올 수 있는 최대, 최소
	int left_max = 0, left_min = 0, mid_max = 0, mid_min = 0, right_max = 0, right_min = 0;

	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
        //다음 줄의 입력을 받고 최대 최소 업데이트
		int lmax = max(left_max, mid_max) + a;
		int lmin = min(left_min, mid_min) + a;

		int mmax = max(max(left_max, mid_max), right_max) + b;
		int mmin = min(min(left_min, mid_min), right_min) + b;

		int rmax = max(mid_max, right_max) + c;
		int rmin = min(mid_min, right_min) + c;

		left_max = lmax, left_min = lmin, mid_max = mmax, mid_min = mmin, right_max = rmax, right_min = rmin;
	}

	cout << max(max(left_max, mid_max), right_max) << ' ' << min(min(left_min, mid_min), right_min);

	return 0;
}