#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> alpha[128];

int main() {
	int T;
	cin >> T;
	string str;
	int length;

	//정확히 K개를 포함하고 가장 짧은 문자열의 길이
	//문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴
	// 연속 문자열의 길이

	for (int tc = 1; tc <= T; tc++) {
		
		int Min = 100000;
		int Max = 0;

		cin >> str>>length;
		for (int i = 0; i < 128; i++) {
			alpha[i].resize(0);
		}
		//각 알파벳 위치 넣기
		for (int i = 0; i < str.size(); i++) {
			alpha[str[i]].push_back(i);
		}

		//length개를 포함한 가장 짧은 문자열의 길이 구하기
		for (int i = 'a'; i <= 'z'; i++) {
			if (alpha[i].size() < length) continue; //K개보다 모자라면 pass

			int sum = alpha[i][length - 1] - alpha[i][0]+1;
			if (Min > sum) Min = sum;
			if (Max < sum) Max = sum;

			for (int j = length; j < alpha[i].size(); j++) {
				sum = alpha[i][j] - alpha[i][j-length+1]+1;
				if (Min > sum) Min = sum;
				if (Max < sum) Max = sum;

			}
		}

		if (Min == 100000 || Max == 0) cout << -1 << "\n";
		else cout << Min <<" "<< Max << "\n";
	}
}