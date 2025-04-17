#include <iostream>

using namespace std;

int main() {
// 0~ 9까지의 숫자를 7bit의 2진수로 표현
//   0
// 1   2
//   3
// 4   5  
//   6

	char num[10] = { 0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
		0b1101011 , 0b1101111 , 0b1010010 , 0b1111111 , 0b1111011 };
	//arr[i][j]는 숫자 i가 토글하여 j가 되기 위해 필요한 토글의 개수
	char arr[10][10] = {};

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
      //temp는 숫자 i와 j가 다른 부분만 1로 표현함
      char temp = num[i] ^ num[j];
			
      //temp에서 1인 bit의 개수만큼 토글이 필요함
			for (int k = 0; k < 7; k++) {
				if (temp & 1) arr[i][j]++;
				temp >>= 1;
			}
		}
	}

	int N, K, P, X;
	
	cin >> N >> K >> P >> X;

//지금 층을 자리수마다 나누어 저장
	int* cur = new int[K];

	for (int k = 0; k < K; k++) {
		cur[k] =  X % 10;
		X /= 10;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
    //지금 보고 있는 층을 자리수마다 나누어 저장		
		int *temp = new int[K];
		int num = i;
		int cnt = 0;
		for (int k = 0; k < K; k++) {
			temp[k] = num % 10;
			num /= 10;
      //이 자리수를 만들기 위해서 필요한 토글 수를 추가
			cnt += arr[temp[k]][cur[k]];
		}
		if (cnt != 0 and cnt <= P) ans++; //p보다 작다면 정답!
		free(temp);
	}
	free(cur);
	cout << ans;

	return 0;
}
