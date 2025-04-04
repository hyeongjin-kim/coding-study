#include <iostream>
#include <vector>
using namespace std;

//모든 결과를 저장하는 백터(결과를 하나의 수로 저장하는 것이 아니라 자리수마다 따로 분리해서 하나의 벡터로 저장함)
vector<vector<int>> memo(251, vector<int>());

//두 벡터를 더하는 함수

vector<int> sum_vector(vector<int> a, vector<int> b) {
	vector<int> result; 
	int carry = 0;
	for (int i = 0; i < b.size(); i++) {
		//점화식이 S(n) = S(n - 1) +  2 * S(n -2)이므로 이렇게 더함
    int tmp = carry + a[i] + 2 * b[i];
		result.push_back(tmp % 10); //1의 자리만 push
		carry = tmp / 10; //10의자리는 윗자리로 넘겨올림
	}
  //b를 하고 나서 남은 a를 추가
	for (int i = b.size(); i < a.size(); i++) { 
		int tmp = carry + a[i];
		result.push_back(tmp % 10);
		carry = tmp / 10;
	}
	if (carry != 0) result.push_back(carry); //a를 다 계산하고 남은 받아올림이 있다면 추가
	return result; //결과 반환
}

void calc(int k) {
	if (memo[k].size() == 0) {
		calc(k - 2); //S(n-2) 계산
		calc(k - 1); //S(n-1) 계산
		memo[k] = sum_vector(memo[k - 1], memo[k - 2]); //둘을 합산해 S(n) 계산
	}
}



int main() {
  //쉽게 계산할 수 있는 부분들
	memo[0].push_back(1); //이건 왜 1일까?
	memo[1].push_back(1);
	memo[2].push_back(3);
	int n;
	vector<int> result;
  //입력이 있을 때까지 받아옴
	while (cin >> n) {
    //계산이 안되어 있으면 계산
		if (memo[n].size() == 0) {
			calc(n);
			
		}
    //memo[n]의 0번은 0의자리, 제일 높은 자리는 가장 마지막에 있다. little endian
    //사람이 보기 위해서는 반대로 출력
		for (auto itr = memo[n].rbegin(); itr != memo[n].rend(); itr++) {
			cout << *itr;
		}
		cout << '\n';
		
	}

	return 0;
}
