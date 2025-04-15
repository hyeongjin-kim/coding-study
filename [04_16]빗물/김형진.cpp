#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int total_water = 0;

	int R, C;
	cin >> R >> C;

	int blocks;

	queue<int> q;
	int left_side = 0;

	for (int i = 0; i < C; i++) {
		cin >> blocks;
		//이전에 들어왔던 열에 지금 보다 낮은 곳이 있다면
		//그곳을 기준으로 빗물이 고임
		if (left_side <= blocks) {
			while (!q.empty()) {
				total_water += (left_side - q.front());
				q.pop();
			}
			//지금 들어온 열이 새로운 기준이 됨
			left_side = blocks;
		} 
		else q.push(blocks);

	}
	int right_side = 0;
	queue<int> from_right;
	stack<int> right_part;
	//q가 아직 비지 않았다면, 기준보다 높은 곳이 들어오지 않았다는 뜻
	//반대로 오른쪽에서부터 이동하며 위와 같은 방식으로 계산함
	if (!q.empty()) right_part.push(left_side); //왼쪽 칸막이를 추가함
	while (!q.empty()) { //q의 순서를 뒤집기 위해 stack에 집어넣음
		right_part.push(q.front());
		q.pop();
	}
	while (!right_part.empty()) {
		//위와 같은 식으로 계산함 stack이 cin과 같은 역할을 한다고 보면 됨
		blocks = right_part.top();
		right_part.pop();
		//이전에 들어왔던 열에 지금 보다 낮은 곳이 있다면
		//그곳을 기준으로 빗물이 고임
		if (right_side <= blocks) {
			while (!from_right.empty()) {
				total_water += (right_side - from_right.front());
				from_right.pop();
			}
			//지금 들어온 열이 새로운 기준이 됨
			right_side = blocks;
		}
		else from_right.push(blocks);
	}

	cout << total_water;

	return 0;
}