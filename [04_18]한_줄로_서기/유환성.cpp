#include <iostream>
using namespace std;

int cntPeople[10];
int line[10];
int N;

void setline(int s) {
	int cnt = 0;
	int targetCnt = cntPeople[s - 1];

	//앞에서부터 빈 칸 찾기
	for (int i = 0; i <N; i++) {
		
		//빈칸인데 내가 들어갈 자리면
		if (targetCnt == cnt && line[i]==0) {
			line[i] = s;
			return;
		}
		//빈칸인데 내가 들어갈 자리가 아니면
		else if (line[i] == 0 ) {
			cnt++;
		}

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {

		cin >> cntPeople[i];
	}

	for (int i = 1; i <= N; i++) {
		setline(i);
	}

	for (int i = 0; i < N; i++) {
		cout<<line[i]<<" ";
	}

	return 0;
}
