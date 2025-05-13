#include <iostream>
#include <set>
#include <queue>
#include <tuple>

#define MAX_N 101

using namespace std;

int board[MAX_N][MAX_N];
int section[MAX_N][MAX_N];
bool rain[MAX_N][MAX_N];
int n;
set<int> height;
int max_h = 0;
int ans = 1;
queue<pair<int,int> > q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << section[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			section[i][j] = 0;
			rain[i][j] = false;
		}
	}
}
void flood(int h) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] <= h)
				rain[i][j] = true;
		}
	}
}

bool InRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int x, int y) {
	if (InRange(x, y) == false)
		return false;
	if (rain[x][y] == true)
		return false;
	if (section[x][y] != 0)
		return false;
	return true;
}

void BFS(int x, int y, int idx) {
	section[x][y] = idx;
	q.push(make_pair(x, y));

	while (q.empty() == false) {
		int a, b;
		tie(a, b) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (CanGo(nx, ny) == true) {
				section[nx][ny] = idx;
				q.push(make_pair(nx, ny));
			}

		}
	}
	//Print();

}

int Solution() {
	// visited 배열 대신 영역을 표시하는 배열 만들기. => section
	//4. BFS 내부 - idx 파라미터로 받아서 영역표시하기 
	//4-1. 이동할 수 있는 모든 구간 이동하기. 
	//3-3 비 내린곳 & 영역 표시된 배열 은 bfs 시작 안함. 
	// 전체적으로 idx ans랑 비교해서 최댓값 ans에 저장하기. 
	int idx = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rain[i][j] == true || section[i][j] != 0)
				continue;
			BFS(i, j, idx);
			idx++;
		}
	}
	return idx;
}

int main() {

	//1. 입력받기 
	//2. 높이를 set에 넣어서 반복해서 영역 개수의 최댓값 찾기
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			height.insert(board[i][j]);
			max_h = max(max_h, board[i][j]);
		}
	}

	//3. for문 내부 (높이 종류 만큼 반복. (최댓값은 할 필요 없음..? 그럼 다 잠기니까. 
	// - init  함수 넣기 
	//3-1. 높이 이하인 것 다 비내리기 
	//3-2. 이중for문 돌려서 bfs 돌리기.- 영역 표시하는 배열 하나 더 만들기. 
	set<int>::iterator it;
	it = height.begin();
	for (it; it != height.end(); it++) {
		init();
		int h = *it;
		if (h == max_h)
			continue;
		flood(h); // 높이 이하인 것 다 비내리기.
		int tmp = Solution();
		tmp--;
		ans = max(ans, tmp);
	}
	
	cout << ans;


}
