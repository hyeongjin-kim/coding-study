#include <iostream>

using namespace std;

bool cols[15];
bool cross1[30];
bool cross2[30];
int N;
int ans = 0;

void queens(int n) {
    //N개의 퀸을 다 놓으면 정답 하나 증가
	if (n == N) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
        //i 열에 없고, 왼쪽 대각선, 오른쪽 대각선에 없으면 여기에 놓고 다음 줄 테스트
		if (cols[i] == false and cross1[i + n] == false and cross2[i - n + N - 1] == false) {
			cols[i] = cross1[i + n] = cross2[i - n + N - 1] =true;
			
			queens(n + 1);
			cols[i] = cross1[i + n] = cross2[i - n + N - 1] = false;
			
		}
	}
}
 
int main() {

	
	cin >> N;

	queens(0);

	cout << ans;

	return 0;
}