#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];

// 3*2를 돌기 위한 방향 배열
int dr32[6] = { 2,2,1,1,0,0 };
int dc32[6] = { 1,0,1,0,1,0 };

//2*3을 돌기 위한 방향 배열
int dr23[6] = { 1,1,1,0,0,0 };
int dc23[6] = { 2,1,0,2,1,0 };


//2*2를 돌기 위한 방향 배열
int drsq[4] = {0,0,1,1};
int dcsq[4] = { 0,1,0,1 };

//3*2에 들어가는 테트로미노의 위치를 표시하는 이진수  
//  0 1
//  2 3
//  4 5
char tet32[8] = {
	0b110101, 0b101011, 0b010111, 0b111010, 0b101101, 0b011110, 0b011101, 0b101110
};


//2*3에 들어가는 테트로미노의 위치를 표시하는 이진수
// 0 1 2
// 3 4 5

char tet23[8] = {
	0b001111, 0b100111, 0b111100, 0b111001, 0b011110, 0b110011, 0b010111, 0b111010
};

int main() {
	int ans = 0;

	int N, M;
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

  //3 * 2를 돌기
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			int now[8] = {}; //3*2에 들어가는 8개의 테트로미노마다 합을 저장하기 위한 배열

			for (int k = 5; k  >= 0; k--) { //3 *2를 돔
				int newr = i + dr32[k], newc = j + dc32[k]; //방향 배열로 위치 조정

				for (int l = 0; l < 8; l++) { 
					if ((tet32[l] >> k) & 0b1) { //이진수에서 해당하는 자리를 0번비트로 내린 뒤 1인지 확인해서 맞으면 더함
						now[l] += arr[newr][newc];
					}
				}
			}

			for (int k = 0; k < 8; k++) {
				ans = max(ans, now[k]); //결과 계산
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int now[8] = {}; //2*3에 들어가는 8개의 테트로미노마다 합을 저장하기 위한 배열

			for (int k = 5; k >= 0; k--) {
				int newr = i + dr23[k], newc = j + dc23[k]; //방향 배열로 위치 조정

				for (int l = 0; l < 8; l++) {
					if ((tet23[l] >> k) & 0b1) { //이진수에서 해당하는 자리를 0번비트로 내린 뒤 1인지 확인해서 맞으면 더함
						now[l] += arr[newr][newc]; 
					}
				}
			}

			for (int k = 0; k < 8; k++) {
				ans = max(ans, now[k]); //결과 계산
			}
		}
	}

	for (int i = 0; i < N; i++) { //가로로 4칸짜리를 계산
		for (int j = 0; j < M - 3; j++) {
			int now = 0;
			for (int k = 0; k < 4; k++) now += arr[i][j + k];
			ans = max(ans, now);
		}
	}

	for (int i = 0; i < N - 3; i++) { //세로로 4칸짜리를 계산
		for (int j = 0; j < M; j++) {
			int now = 0;
			for (int k = 0; k < 4; k++) now += arr[i + k][j];
			ans = max(ans, now);
		}
	}

	for (int i = 0; i < N - 1; i++) { //2*2를 계산
		for (int j = 0; j < M - 1; j++) {
			int now = 0;
			for (int k = 0; k < 4; k++) now += arr[i + drsq[k]][j + dcsq[k]];
			ans = max(ans, now);
		}
	}

	cout << ans;

	return 0;
}
