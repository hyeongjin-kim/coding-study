#include <iostream>

using namespace std;

int main() {

	//N < 100
	// K < 2N
	// Ai < 1000	
	// 1. 벨트 회전
	// 2. 벨트 위의 로봇이 이동
	// 3. 올리는 위치의 칸의 내구도가 0이 아니면 로봇을 올림
	// 4. 종료조건 체크 내구도가 0인 칸이 K개 이상이면 종료
	
	int N, K, arr[201] = {}, broken = 0;
	int robots[201] = {}; //각 칸에 로봇의 유무 표시
	cin >> N >> K;
	
	for (int i = 1; i <= 2 * N; i++) {
		cin >> arr[i];
	}
	
	int offset = 0;// 진행 정도를 나타냄
	int step = 0;
	do { 
        // 1. 벨트 회전 
		robots[(3 * N - 1 - offset) % (2 * N) + 1] = 0; //벨트가 회전돼서 로봇이 내림림
		offset = (offset + 1) % (2 * N); //벨트 회전전
		step++; //단계 증가가
		
		
		int on = (2 * N - offset) % (2 * N) + 1; //올리는 칸 : (2n - offset)%(2n) + 1
		int off = (3 * N -  1 - offset) % (2 * N) + 1; //내리는 칸 : (3n - 1 - offset)%(2n) + 1
		//로봇은 먼저 올라간 로봇이 반드시 먼저 나감 앞질러 갈 수 없기 때문
		
		for (int i = 0; i < N; i++) {
			int idx = (3 * N - 1 - offset - i) % (2 * N) + 1; //내리는 칸부터 올리는 칸까지 쭉 봄봄
			if (idx == off) { //내리는 칸의 로봇은 내림림
				robots[idx] = 0; //로봇 내림
			}
            //지금 칸에 로봇이 있고, 다음 칸에 로봇이 없고, 다음 칸의 내구도가 남아있으면 이동동
			else if (robots[idx] == 1 and robots[idx%(2 * N) + 1] == 0 and arr[idx % (2 * N) + 1] > 0) { 
				robots[idx] = 0;
				robots[idx % (2 * N) + 1] = 1;
				arr[idx % (2 * N) + 1]--;
				if (arr[idx % (2 * N) + 1] == 0) broken++; //내구도 체크크
			}

		}

		//올리는 칸 확인해서 괜찮으면 로봇이 올라감
		if (arr[on] > 0 and robots[on] == 0) {
			robots[on] = 1;
			arr[on]--;
			if (arr[on] == 0) broken++;
		}

	} while (broken < K); //전체 내구도 확인
	
	cout << step;

	

	return 0;
}
