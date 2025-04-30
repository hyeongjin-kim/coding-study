#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<bool> prime_list(2000001, true);
vector<int> primes;

void is_prime(int N) {
	for (int idx = 2; idx < 1001; idx++) {
		if (prime_list[idx]) {
			for (int jdx = idx * idx; jdx < N + 1; jdx += idx) {
				prime_list[jdx] = false;
			}
		}
	}
}

bool is_palindrome(int N) {
	if (N < 0 || (N % 10 == 0 && N != 0)) return false;

	int reverse = 0;
	while (N > reverse) {
		reverse = reverse * 10 + N % 10;
		N /= 10;
	}

	return (N == reverse || N == reverse / 10);
}

int main() {
	int N; cin >> N;
	prime_list[0] = false;
	prime_list[1] = false;
	is_prime(2000000);

	while (true) {
		if (prime_list[N]) {
			if (is_palindrome(N)) {
				break;
			}
		}
		N++;
	}

	cout << N;
}
