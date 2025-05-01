#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

bool arr[1050001]; //처음에는 넉넉하게 4백만으로 했지만 N = 1000000일때 답이 1003001이길래 줄임

int main() {

	int N;
	cin >> N;

	memset(arr, 1, sizeof(arr));
    //에라토스테네스의 채
	for (int i = 2; i < 1050001; i++) {
		if (arr[i] == false) continue; //소수가 아니면 넘어감
		
		if (i >= N) { //소수인 i가 N보다 크면 펠린드롭 테스트
			string num = to_string(i);
			auto s = num.begin(); //앞에서 오는 itr
			auto e = num.rbegin(); //뒤에서 오는 reverse itr
			bool equal = true;
			while (((s - num.begin()) <= num.size()/2) and equal) { //begin과의 거리가 전체 길이의 절반을 넘지 않을 때까지
				if (*s == *e) { //둘이 같으면 한칸씩 전진
					s++;
					e++;
				}
				else equal = false; //아니면 끝
			}
			if (equal) { //맞다면 출력하고 종료
				cout << i;
				break;
			}
		}
		for (int j = 2 * i; j < 1005001; j += i) { //i의 배수를 전부 지움
			arr[j] = false;
		}
	}

	

	return 0;
}