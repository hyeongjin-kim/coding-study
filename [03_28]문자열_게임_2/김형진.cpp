#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int alphabetcount[26] = {}; //각 알파벳의 개수를 기록
int arr[26][10000] = {}; //각 알파벳이 등장한 인덱스를 기록하기 위한 배열

void init() {
	memset(alphabetcount, 0, sizeof(alphabetcount));
	memset(arr, 0, sizeof(arr));
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		getchar(); //숫자 입력 후 엔터를 버퍼에서 지워줌
		init(); //초기화
		string s;
		cin >> s;
		int K, shortword = 100001, longword = 0; //최소길이, 최대 길이 초기화
		cin >> K;
		for (int i = 0; i < s.length(); i++) {
			arr[(s[i] - 'a')][alphabetcount[(s[i] - 'a')]++] = i;
		}

		for (int i = 0; i < 26; i++) {
			//애초에 이 알파벳이 K보다 적으면 계산 안함
			if (alphabetcount[i] < K) continue;
			for (int j = 0; j < alphabetcount[i]; j++) {
				// arr[i][j]: i번째 알파벳의 j + 1번째 인덱스
				int k = j + K - 1; // j번째부터 K개를 셋을 때 위치
				if (k < alphabetcount[i]) { //j번째부터 k개가 존재 한다면
					shortword = min(shortword, arr[i][k] - arr[i][j] + 1); //두 인덱스의 간격이 가장 작은 것은 3번
					longword = max(longword, arr[i][k] - arr[i][j] + 1); //두 인덱스의 간격이 가장 긴 것은 4번 
				}
				else break; //j 뒤로 이 알파벳은 k개보다 적음 볼 필요 없음
			}
		}
		if(shortword != 100001 ) cout << shortword << ' ' << longword << '\n';
		else cout << -1 << '\n';//없으면 -1
	}


	return 0;
}
