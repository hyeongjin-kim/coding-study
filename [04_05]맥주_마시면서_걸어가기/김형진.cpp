#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

struct conbi {
	int x;
	int y;
	bool operator==(const conbi b) {
		return (x == b.x and y == b.y);
	}
};

conbi arr[102]; // 시작 지점, 편의점, 축제 장소를 저장하는 struct 배열
bool visit[102]; //방문 여부를 저장하는 배열열


//초기화화
void init() {
	memset(arr, 0, sizeof(arr));
	memset(visit, 0, sizeof(visit));
}


int main() {

	//맥주는 총 20개 50미터마다 반드시 마셔야 함
	//더 구매해야 할 수도 있다.
	//살 때 빈 병은 버리고 새 맥주병을 산다
	//사고 나서도 50미터를 가기 전에 마셔야 함
	// 사고 나면 그 전에 마신 만큼은 초기화 된다는 듯?
	int T;
	cin >> T;


	for (int t = 1; t <= T; t++) {
		int N; //편의점 개수
		cin >> N;
		init();
		//arr[0]은 집, arr[N + 1]은 축제 장소, 나머지는 편의점
		for (int i = 0; i <= N + 1; i++) {
			cin >> arr[i].x >> arr[i].y;
		}

		queue<conbi> q;

		q.push(arr[0]);
		visit[0] = 1;
        //축제 장소에 방문하거나, 갈 수 있는 곳이 없으면 종료료
		while (visit[N + 1] == 0 and !q.empty()) {

			auto cur = q.front();
			q.pop();

			for (int i = 1; i <= N + 1; i++) {
				//거리가 1000이내인 방문하지 않은 곳이 있으면 방문
                if (visit[i] == 0 and (abs(arr[i].x - cur.x) + abs(arr[i].y - cur.y)) <= 1000) {
					q.push(arr[i]);
					visit[i] = 1;
				}
			}
		}
        //축제 장소에 도착
		if (visit[N + 1] == 1) cout << "happy\n";
		//실패패
        else cout << "sad\n";
	}

	return 0;
}
