#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int original[50] = {};
	int ccw[50] = {};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> original[i];
	//반대방향으로 돌았을 경우의 이동 순서 배열 반대방향으로 가야하므로 순서도 뒤집혀야함
	for (int i = 0; i < N; i++) ccw[i] = (original[i] + 1)%4 + 1;
	reverse(ccw, ccw + N);
	vector<vector<int>> answer;

	int M;
	cin >> M;

	int target[50];
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> target[j];
		}
		
		for (int k = 0; k < N; k++) {
			int s = k, l = 0, cnt = 0;
			while (1) {
				
				if (cnt == N) break;
				//원본이나 반대방향 배열과 일치하면 다음 것을 봄
				if (original[s] == target[l] or ccw[s] == target[l]) {
					s = (s + 1) % N;
					l = (l + 1) % N;
					cnt++;
				}
				else break;
			}
			//N개 모두 일치하면 정답
			if (cnt == N) {
				answer.push_back(vector<int>(target, target + N));
				break;
			}
			
		}
		
	}
	cout << answer.size() << '\n';
	for (auto ans : answer) {
		for (int j = 0; j < N; j++) {
			cout << ans[j] << ' ';
		}
		cout << '\n';
	}
	
	
	return 0;
}
