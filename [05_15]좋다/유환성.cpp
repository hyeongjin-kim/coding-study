#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans;

struct Node {
	int num;
	int flag;
};

vector<Node> vect;

void input() {
	cin >> N;
	
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		vect.push_back({ num,0 });
	}
}

bool comp(Node a, Node b) {
	return a.num < b.num;
}

void solution() {

	int sp, ep, sum;
	
	sort(vect.begin(), vect.end(),comp);

	for (int i = 0; i < vect.size(); i++) {

		sp = 0;
		ep = vect.size() - 1;

		while (sp < ep) {

			if (sp == i) {
				sp++;
				continue;
			}
			if (ep == i) {
				ep--;
				continue;
			}

			sum = vect[sp].num + vect[ep].num;

			// sum이 vect[i]와 같으면 좋은 숫자
			if (sum == vect[i].num) {
				vect[i].flag = 1;
				break;
			}

			// sum이 vect[i] 보다 작으니 커져야함 : sp++
			else if (sum < vect[i].num)sp++;

			// sum이 vect[i] 보다 크니 작아져야함 : ep--
			else ep--;

		}

	}


	// 좋은 숫자 갯수 계산
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].flag) ans++;
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	cout << ans;

	return 0;
}
