#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans;

int map[21][21];
int Student[500][4];
vector<int> seq;
struct Node {
	int love;
	int empty;
	int x;
	int y;
	
	/*
	1. 비어있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리잡기
	2. 1을 만족하는 칸이 여러 개면 인접한 칸중 비어있는 칸이 가장 많은 곳 찾기
	3. 2을 만족하는 칸이 여러 개면 행의 번호가 가장 적은 칸으로,
	   그럼에도 여러 개이면 열의 번호가 가장 적은 칸으로
	*/

	bool operator<(const Node& right) const{
		if(love != right.love)
			return love < right.love;
		if(empty != right.empty)
			return empty < right.empty;
		if(x != right.x)
			return x > right.x;
		return y > right.y;
	}
};

bool inRange(int x, int y) {
	return 0 <= x && 0 <= y && x < N && y < N;
}

void input() {


	int StuNum, love;
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		
		cin >> StuNum;
		seq.push_back(StuNum);

		for (int j = 0; j < 4; j++) {
			cin >> love;
			Student[StuNum][j] = love;
		}

	}

}

void find_good_place(int cur) {

	//0.1. i가 x,y에 앉으면 주위에 내가 좋아하는 친구들이 있는지 세기,
	//0.2  셀 때 주변의 비어있는 칸도 세기, 배열에 저장
	//0.3 vector에 (0.1), (0.2), (i의 x, y) 데이터를 저장
	//0.4 vector를 조건에 맞게 정렬
	
	int nx, ny;
	int love, empty;

	priority_queue<Node> near_data;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {

			love = 0;
			empty = 0;

			// 현재 학생(cur)이 row, col에 앉을 때, 주변의 상태 저장

			//누군가 미리 앉아 있으면 continue;
			if (map[row][col] != 0) continue;

			for (int dir = 0; dir < 4; dir++) {
				
				nx = row + dx[dir];
				ny = col + dy[dir];

				if (!inRange(nx, ny))continue;

				if (map[nx][ny] == 0) empty++;

				for (int i = 0; i < 4; i++) {
					if (Student[cur][i] == map[nx][ny]) love++;
				}

			}
			near_data.push({ love,empty,row,col });
		}
	}

	auto gp = near_data.top();
	map[gp.x][gp.y] = cur;
}

void calc() {

	// 모든 학생이 다 앉고, 만족도를 계산하는 함수

	int nx, ny;
	int cnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			cnt = 0;

			for (int dir = 0; dir < 4;dir++) {
				nx = i + dx[dir];
				ny = j + dy[dir];

				if (!inRange(nx, ny))continue;

				for (int k = 0; k < 4;k++) {
					if (Student[map[i][j]][k] == map[nx][ny]) cnt++;
				}
			
			}

			switch (cnt)
			{
				case 0: ans += 0; break;
				case 1:	ans += 1; break;
				case 2:	ans += 10; break;
				case 3:	ans += 100; break;
				case 4:	ans += 1000; break;
			}

		}
	}

}

void solution() {

	for (int i = 0; i < N * N; i++) {

		// 순서대로 최적의 자리에 앉히기
		find_good_place(seq[i]);
	}

	calc();

}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	solution();

	cout << ans;

	return 0;
}
