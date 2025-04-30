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

bool is_palindrome_manacher(const string& s) {
	string t = "#";
	for (char c : s) {
		t += c;
		t += "#";
	}

	int n = t.size();
	vector<int> p(n, 0);
	int center = 0, right = 0;

	for (int i = 0; i < n; ++i) {
		int mirror = 2 * center - i;

		if (i < right)
			p[i] = min(right - i, p[mirror]);

		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
			p[i]++;

		if (i + p[i] > right) {
			center = i;
			right = i + p[i];
		}
	}

	int original_len = s.size();
	int center_index = t.size() / 2;
	return p[center_index] == original_len;
}

int main() {
	int N; cin >> N;
	prime_list[0] = false;
	prime_list[1] = false;
	is_prime(2000000);
	string N_string; // 마나커

	while (true) {
		N_string = to_string(N);
		if (prime_list[N]) {
			if (is_palindrome_manacher(N_string)) {
				break;
			}
		}
		N++;
	}

	cout << N;
}
