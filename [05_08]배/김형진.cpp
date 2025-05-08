#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int crain[50];
//박스의 무게마다 개수를 저장하는 배열
int multi[1000001];

int main() {

	int N;
	cin >> N;
  //제일 무거운 크레인이 제일 무거운 것을 들도록 오름차순 정렬
	for (int i = 0; i < N; i++) cin >> crain[i];
	sort(crain, crain + N, greater<>());

	int M;
	cin >> M;

	int box;

	set<int> s;
  //SET을 쓴 이유
  //1. 정렬된 상태로 유지됨
  //2. 특정 인자보다 큰 첫번째 인자를 log(N)에 찾을 수 있음
	for (int i = 0; i < M; i++) {
		cin >> box;
		s.insert(box);
		multi[box]++; //개수 새기
	}
  //제일 큰 박스가 제일 큰 크레인의 한계보다 크면 못함
	if (*s.rbegin() > crain[0]) {
		cout << -1;
		return 0;
	}

	int ans = 0;
	while (!s.empty()) {
		for (int i = 0; i < N; i++) {
      //중간에 비었으면 종료
			if (s.empty()) break;
      //이 크레인보다 무거운 첫번째 박스보다 하나 앞의 박스를 찾음
			auto itr = s.upper_bound(crain[i]);
			itr--;
      
      //itr == end라는건 이보다 가벼운 박스가 없다는 것
			if (itr == s.end() or *itr > crain[i]) break;
			multi[*itr]--;
      //더 이상 이 무게의 박스가 남지 않았으면 제거
			if(multi[*itr] == 0) s.erase(itr);
		}
    //크레인을 다 돌면 하루가 지남
		ans++;
	}

	cout << ans;

	return 0;
}
