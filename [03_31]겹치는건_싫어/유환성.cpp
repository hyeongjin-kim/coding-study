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
	while (s != N - 1) {	// ���� ����Ʈ�� �迭�� ������ �̵��� ������
		s++;
		DAT[map[s]]++;
		if (DAT[map[s]] <= K) {	//���� ���Ұ� K�� ���Ϸ� ���������
			length++;
		}
		else {	//���� ���Ұ� K�� �ʰ��� ���������

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