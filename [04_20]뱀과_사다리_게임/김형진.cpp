#include <iostream>
#include <queue>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;

	cin >> N >> M;

	int ladder[101] = {};
	int snake[101] = {};
	int spot;

	for (int i = 0; i < N; i++) {
		cin >> spot;
		cin >> ladder[spot];
	}
	for (int i = 0; i < M; i++) {
		cin >> spot;
		cin >> snake[spot];
	}

	int visit[101] = {};
	queue<int> q;
	q.push(1);
	//턴의 개념을 적용하기 위한 두번째 큐
	//i번째 턴에 갈 수 있는 곳이 q에 있다면,
	//i + 1번째 턴에 갈 수 있는 곳이 temp에 담김
	queue<int> temp;
	int turn = 0;

	while (visit[100] == 0) {
		turn++;
		//지금 턴에 도착할 수 있는 곳들에서 갈 수 있는 곳을 모두 체크
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			//100을 찾으면 끝
			if (cur == 100) break;

			//한턴에 최대 6칸 까지 갈 수 있음
			for (int i = 1; i <= 6; i++) {
				
				int target = cur + i;
				//이동한 칸이 100을 넘기면 더 볼 필요 없음
				if (target > 100) break;

				//사다리가 있고, 사다리를 탄 위치에 도착한적이 없다면 사다리를 탐
				//이미 사다리를 탄 곳에 도착했다면, 이미 큐에 이곳을 지나간 
				//루트가 담겨 있기에 최단 루트가 될 수 없음
				if (ladder[target] != 0) {
					if (visit[ladder[target]] == 0) {
						temp.push(ladder[target]);
						visit[ladder[target]] = 1;
					}
				}
				//뱀이 있고, 뱀을 탄 위치에 도착한적이 없다면 뱀을 탐
				//이미 뱀을 탄 곳에 도착했다면, 이미 큐에 이곳을 지나간 
				//루트가 담겨 있기에 최단 루트가 될 수 없음
				else if (snake[target] != 0 ) {
					if (visit[snake[target]] == 0) {
						temp.push(snake[target]);
						visit[snake[target]] = 1;
					}
				}
				//사다리와 뱀이 모두 없고, 이 칸을 온 적이 없다면 이 칸으로 감
				else if (visit[target] == 0) {
					temp.push(target);
					visit[target] = 1;
				} 

			}

		}
		//현재 턴에서 체크할 곳을 모두 체크했으면 다음 턴에 도착할 수 있는 곳을
		//모두 큐에 담음
		while (!temp.empty()) {
			q.push(temp.front());
			temp.pop();
		}
	}
	cout << turn;

	return 0;

}