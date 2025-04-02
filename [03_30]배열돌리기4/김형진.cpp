#include "iostream"
#include "algorithm"
#include "vector"
#include "cstring"
using namespace std;

int N, M, K;
//d=원본배열
int arr[50][50] = {};
//회전한 과정을 저장하는 배열
int rotated[6][50][50]{};

//회전 방법을 저장하는 배열
int cmd[6][3] = {};

//가능한 모든 회전 방법을 시도하기 위해 순열을 만드는데 필요한 체크 배열
int visit[6] = {};

//순열을 저장하는 벡터
vector<int> s;

int result = INT32_MAX;

//배열을 돌리는 과정
void rotate(int r, int c, int s, int k) {
	//이전 배열을 가져옴
  memcpy(rotated[k], rotated[k - 1], sizeof(rotated[k]));
	//안쪽부터한칸씩 돌림 
  for (int i = 1; i <= s; i++) {
		int newr = r - i;
		int newc = c - i;
    //윗줄 돌리기
		for (int t = 0; t < 2 * i; t++) {
			rotated[k][newr][newc + 1] = rotated[k - 1][newr][newc];
			newc++;
		}
    //오른쪽 줄 돌리기
		for (int t = 0; t < 2 * i; t++) {
			rotated[k][newr + 1][newc] = rotated[k - 1][newr][newc];
			newr++;
		}
    //아랫줄 돌리기
		for (int t = 0; t < 2 * i; t++) {
			rotated[k][newr][newc - 1] = rotated[k - 1][newr][newc];
			newc--;
		}
    //왼쪽 줄 돌리기
		for (int t = 0; t < 2 * i; t++) {
			rotated[k][newr - 1][newc] = rotated[k - 1][newr][newc];
			newr--;
		}
	}
}
//최종 결과를 계산
int calc() {
	int sum = INT32_MAX;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < M; j++) {
			temp += rotated[K][i][j];
		}
		if (temp < sum) sum = temp;
	}
	return sum;
}
//필요한 순열을 만듬
void permu(int k) {
	//순열이 완성된 경우 그 순열에 맞춰 배열을 돌림
  if (k == K) {
		for (int i = 1; i <= k; i++) {
			int idx = s[i - 1];
			rotate(cmd[idx][0] - 1, cmd[idx][1] - 1, cmd[idx][2], i);
		}
		result = min(result, calc());
		return;
	}
  //단계적 순열 생성
	for (int i = 0; i < K; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			s.push_back(i);
			permu(k + 1);
			visit[i] = 0;
			s.pop_back();
		}
	}
}

int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cmd[i][j];
		}
	}
	memcpy(rotated[0], arr, sizeof(arr));
	permu(0);


	

	cout << result;

	return 0;
}
