#include <iostream>
using namespace std;

int N, K;
int DAT[100001];
int map[200001];
int s, e;
int length = 1, Mlength = 1;
int main() {

	cin >> N >> K;

	for (int i = 0; i < N;i++) {
		cin >> map[i];
	}
	DAT[map[s]]++;
	while (s != N - 1) {	// 시작 포인트가 배열의 끝까지 이동할 때까지
		s++;
		DAT[map[s]]++;
		if (DAT[map[s]] <= K) {	//같은 원소가 K개 이하로 들어있으면
			length++;
		}
		else {	//같은 원소가 K개 초과로 들어있으면

			while (map[e] != map[s]) {
				DAT[map[e]]--;
				e++;
			}
			DAT[map[e]]--;
			e++;
			length = s - e + 1;
		}
		if (Mlength < length) Mlength = length;

	}

	cout << Mlength << "\n";

	return 0;
}