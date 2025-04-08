#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string s;

	cin >> s;
	int a = 0;
	//a의 개수 세기
    for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a')a++;
	}

	int ans = 1000;
    
	for (int i = 0; i < s.length(); i++) {
		int tmp = 0;
        //문자열을 돌면서 a의 개수개 만큼씩 확인 (문자열의 마지막에서는 반대로 순환해야 함)
		for (int j = i; j < i + a; j++) {
            //a가 아닌 것 => 바꿔야 하는 것 즉 이 구간을 모두 a로 만들려면 tmp번의 교체가 필요함
			if (s[j%s.length()] != 'a') tmp++;
		}
        //그중 최소값을 찾음
		if (ans > tmp) ans = tmp;
	}

	cout << ans;

	return 0;
}