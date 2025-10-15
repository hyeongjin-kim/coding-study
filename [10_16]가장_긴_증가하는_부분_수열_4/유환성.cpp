#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1005];
int dp[1005];
vector<vector<int>> vect(1005);

int main() {
	//dp에는 지금까지 수열의 길이 저장
	//vect에는 지금까지 수열 요소의 인덱스 저장

	cin >> N;
	for (int i=0; i < N; i++) {
		cin >> arr[i];
	}

	for (int cur = 0; cur < N; cur++) {
		int max_idx = 0;	//가장 긴 수열의 인덱스
		int max = 0;		//가장 긴 수열의 길이
		for (int prev = 0; prev < cur; prev++) {
			//본인보다 크면 pass
			if (arr[prev] >= arr[cur]) continue;

			//가장 긴 수열의 인덱스, 길이 구하기 
			if (max < dp[prev]) {
				max = dp[prev];
				max_idx = prev;
			}
		}

		dp[cur] = max + 1;
		if (max) vect[cur] = vect[max_idx];

		vect[cur].push_back(cur);
	}
	
	int m = dp[0];
	int max=0;
	int max_idx = 0;
	for (int i = 0; i < N; i++) {
		if (dp[i] > max) {
			max_idx = i;
			max = dp[i];
		}
	}

	cout << max << "\n";
	for (auto i : vect[max_idx]) {
		cout << arr[i]<<" ";
	}

	return 0;
}
