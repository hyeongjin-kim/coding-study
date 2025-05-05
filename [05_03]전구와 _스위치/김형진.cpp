#include <iostream>
#include <memory.h>
using namespace std;

bool current[100001];
bool temp[100001];
bool target[100001];

int N;
int tempans = 0;


// 앞에서부터 한칸씩 맞춰가는 과정
// i번째 스위치는 i-1번째를 결정함(왜냐? 더이상 i - 1번째에 영향을 줄 수 있는 스위치가 없기 때문)
// i - 1 전구가 목표와 다르면 이를 맞춰주기 위해 i번째 스위치를 누음
void test() {
	for (int i = 2; i < N; i++) {
		if (temp[i - 1] != target[i - 1]) {
			temp[i - 1] = !temp[i - 1];
			temp[i] = !temp[i];
			temp[i + 1] = !temp[i + 1];
			tempans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
    //현재 상태와 목표 상태를 string으로 받아와서 저장함
	string cur;
	string tar;
	cin >> cur;
	cin >> tar;
	for (int i = 1; i <= N; i++) current[i] = (cur[i - 1] == '1');
	memcpy(temp, current, sizeof(temp));
	for (int i = 1; i <= N; i++) target[i] = (tar[i - 1] == '1');

	int ans = N + 1;
	//현재 상태에서 맞춰봄
	test();
    //마지막 까지 왔을 때, N -1과 N번째 전구가 모두 맞거나, 모두 틀렸어야 함
	if (temp[N - 1] == target[N - 1] and temp[N] == target[N]) ans = min(tempans, ans);
	else if (temp[N - 1] != target[N - 1] and temp[N] != target[N]) ans = min(tempans + 1, ans);

    //다시 초기상태 복구
	memcpy(temp, current, sizeof(temp));
    //1번 스위치를 누름
	temp[1] = !temp[1];
	temp[2] = !temp[2];
	tempans = 1;

	test();
    //마지막 까지 왔을 때, N -1과 N번째 전구가 모두 맞거나, 모두 틀렸어야 함
	if (temp[N - 1] == target[N - 1] and temp[N] == target[N]) ans = min(tempans, ans);
	else if(temp[N - 1] != target[N - 1] and temp[N] != target[N]) ans = min(tempans + 1, ans);
	
	cout << (ans == N + 1? -1 : ans);

	return 0;
}