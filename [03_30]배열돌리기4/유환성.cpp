#include  <iostream>
using namespace std;

int N, M, K;
int map[51][51];
int ans = 21e8;

struct cmd {
	int r;
	int c;
	int s;
};
cmd c[6];
int visited[6];

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> c[i].r >> c[i].c >> c[i].s;
	}
}

void rotate(int i) {
	auto cur = c[i];
	int sx = cur.r - cur.s - 1;
	int sy = cur.c - cur.s - 1;
	int ex = cur.r + cur.s - 1;
	int ey = cur.c + cur.s - 1;

	for (int j = 0; j < cur.s; j++) {

		int t = map[sx + j][sy + j];

		for (int i = sy + j; i < ey - j; i++) { //오른쪽으로
			//map[sx][i + 1] = map[sx][i];
			swap(map[sx + j][i + 1], t);
		}
		for (int i = sx + j; i < ex - j; i++) { //아래로
			//map[i + 1][ey] = map[i][ey];
			swap(map[i + 1][ey - j], t);
		}
		for (int i = ey - j; i > sy + j; i--) { //왼쪽으로
			//map[ex][i - 1] = map[ex][i];
			swap(map[ex - j][i - 1], t);
		}
		for (int i = ex - j; i > sx + j; i--) { //위로
			//map[i - 1][sy] = map[i][sy];
			swap(map[i - 1][sy + j], t);
		}

	}

}
void recur(int i) {

	auto cur = c[i];
	int sx = cur.r - cur.s - 1;
	int sy = cur.c - cur.s - 1;
	int ex = cur.r + cur.s - 1;
	int ey = cur.c + cur.s - 1;

	for (int j = 0; j < cur.s; j++) {

		int t = map[sx + j][sy + j];

		for (int i = sx + j; i < ex - j; i++) { //아래로
			//map[sx][i + 1] = map[sx][i];
			swap(map[i + 1][sy + j], t);
		}
		for (int i = sy + j; i < ey - j; i++) { //오른쪽으로
			//map[i + 1][ey] = map[i][ey];
			swap(map[ex - j][i + 1], t);
		}
		for (int i = ex - j; i > sx + j; i--) { //위로
			//map[ex][i - 1] = map[ex][i];
			swap(map[i - 1][ey - j], t);
		}
		for (int i = ey - j; i > sy + j; i--) { //왼쪽으로
			//map[i - 1][sy] = map[i][sy];
			swap(map[sx + j][i - 1], t);
		}

	}
}
void printAll() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void calc() {
	int sum;
	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = 0; j < M; j++) {
			sum += map[i][j];
		}
		if (sum < ans) ans = sum;
	}
}
void solution(int level) {
	//중복 없는 순열
	if (level == K) {
		calc(); //최소값 찾기
		return;
	}

	for (int i = 0; i < K; i++) {
		if (visited[i] == 1)continue;
		visited[i] = 1;
		rotate(i);//돌기
		solution(level + 1);
		//printAll();
		recur(i);//원복
		visited[i] = 0;
	}

}

int main() {
	input();
	solution(0);
	cout << ans;
}