#include "iostream"
#include "algorithm"
using namespace std;

int N, M;

int forwardmap[6][6] = {}; //forward[i][j]: (i,j)로 직진해서 오는 경우, 즉 (i -1, j)에서 오는 경우
int rightmap[6][6] = {}; //right[i][j]: (i,j)로 오른쪽에서 오는 경우, 즉 (i - 1, j + 1)에서 오는 경우
int leftmap[6][6] = {}; //left[i][j]: (i,j)로 왼쪽에서 오는 경우, 즉 (i - 1, j + 1)에서 오는 경우

int map[6][6] = {};
int main() {
	
	cin >> N >> M;
//지도 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//초기 설정 첫줄은 아무렇게나 갈 수 있음
      if (i == 0) {
				forwardmap[i][j] = map[i][j];
				rightmap[i][j] = map[i][j];
				leftmap[i][j] = map[i][j];
			}
			
			else {
				//forwardmap: 이 타일로 직진으로 오는 경우 => 여기로 오려면 그 전에 왼쪽, 오른쪽에서 이동했어야 함
				if (j == 0) {
					forwardmap[i][j] = map[i][j] + rightmap[i - 1][j]; //전칸이 왼쪽에서 올 수 없음
				}
				else if (j == M -1){ 
					forwardmap[i][j] = map[i][j] + leftmap[i - 1][j]; //전칸이 오른쪽에서 올 수 없음
				}
				else {
					forwardmap[i][j] = map[i][j] + min(rightmap[i - 1][j], leftmap[i - 1][j]); //더 싼 쪽 고르기
				}
				//leftmap: 이 타일로 왼쪽에서 오는 경우 => 여기로 오려면 그 전에 직진, 오른쪽에서 와야함
				if (j == 0) {
					leftmap[i][j] = INT32_MAX; //왼쪽에서 올 수 없음
				}
				else {
					leftmap[i][j] = map[i][j] + min(rightmap[i - 1][j - 1], forwardmap[i - 1][j - 1]); //더싼쪽 고르기
				}
				//rightmap
				if (j == M - 1) {
					rightmap[i][j] = INT32_MAX; //오른쪽에서 올 수 없음
				}
				else {
					rightmap[i][j] = map[i][j] + min(forwardmap[i - 1][j + 1], leftmap[i - 1][j + 1]); //더 싼 쪽 고르기
				}

			}
		}
	}

	int result = INT32_MAX;
  //최소값 구하기
	for (int i = 0; i < M; i++) {
		if (forwardmap[N - 1][i] < result) result = forwardmap[N - 1][i];
		if (leftmap[N - 1][i] < result) result = leftmap[N - 1][i];
		if (rightmap[N - 1][i] < result) result = rightmap[N - 1][i];
	}
	cout << result;
	return 0;
}
