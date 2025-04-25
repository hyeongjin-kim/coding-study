#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

bool prime[4000001];
vector<int> primes;
int N;

int main() {

	
	cin >> N;
	
	memset(prime, true, sizeof(prime));
	
	//소수 걸러내기
	for (int i = 2; i <= N; i++) {
		//이미 소수가 아니라고 했으면 건너 뜀
		if (prime[i] == false) continue;
		//소수이므로 백터에 추가
		primes.push_back(i);
		//이 수의 배수는 모두 소수가 아니라고 표시
		for (int j = i * 2; j <= N; j += i) {
			prime[j] = false;
		}
	}
	
	int ans = 0;
	int sum = 0;

	auto start = primes.begin();
	auto end = primes.begin();
	//합이 N이하의 가장 수가 되도록 처음부터 쭉 더함
	while (sum < N and end != primes.end()) sum += *(end++);

	while (1) {
		//N이면 경우의 수 추가
		if (sum == N) ans++;
		//N이하라서 새로운 수를 추가해야 하는데 더 추가할 수가 없다면 끝
		if (sum < N and end == primes.end()) break;
		//N이상이면 가장 앞의 수를 뺌
		else if (sum >= N) sum -= *(start++);
		//N이하면 그 다음 수를 더함
		else sum += *(end++);
	}
	cout << ans;
	return 0;
}