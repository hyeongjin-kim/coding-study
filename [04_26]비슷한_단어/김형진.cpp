#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	string origin, target;
	cin >> origin;

	int alphabet_origin[26] = {};
	//원본의 모든 알파벳 개수를 셈
	for (int i = 0; i < origin.size(); i++) alphabet_origin[origin[i] - 'A']++;
		
	int answer = 0;
	for (int i = 1; i < N; i++) {
		cin >> target;
		//길이가 1이상 차이나면 애초에 만들 수 없음
		if (abs((int)target.length() - (int)origin.size()) > 1) continue;
		int alphabet_target[26] = {};
		//검증할 단어의 모든 알파벳 개수를 셈
		for (int j = 0; j < target.size(); j++) alphabet_target[target[j] - 'A']++;

		int similar = 0;
		
		//검증할 단어와 원본의 알파벳 개수차이를 모두 더함
		for (int k = 0; k < 26; k++) {
			similar += abs(alphabet_origin[k] - alphabet_target[k]);
		}
		//2개 이하로 차이나면 만들 수 있음
		if (similar <= 2) {
			answer++;
		}

	}
	cout << answer;
	return 0;
}