#include <iostream>

using namespace std;

int main() {

	int arr[11] = {};

	int n;
	cin >> n;
	int people[11] = {};
	//키가 i인 사람보다 앞에 있는 키가 큰 사람의 수
	for (int i = 1; i <= n; i++) cin >> people[i];
	//일단 제일 큰 사람을 세움
	arr[0] = n;

	
	int next = 1;

	for (int i = n - 1; i >= 1; i--) {
		//맨 뒤에 큰사람부터 하나씩 세움
		arr[next] = i;
		//이 사람이 기억하는 앞에 있는 키가 큰 사람의 수만큼 앞으로 보냄
		for (int j = 0; n - i > j + people[i]; j++) {
			swap(arr[next - j], arr[next - j - 1]);
		}
		next++;
	}

	for (int i = 0; i < n; i++) cout << arr[i] << ' ';

	return 0;
}
