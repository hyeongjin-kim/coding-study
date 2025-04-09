#include <iostream>

using namespace std;

int main() {
	//구간이 1000밖에 안되므로 그냥 전부 배열을 만듬
	//풀이: 이 문제는 세 구간으로 나눌 수 있음
    //1. 점점 높아지는 왼쪽 부분
    //2. 가장 높은 중간 부분
    //3. 점점 낮아지는 오른쪽 부분
    //세 구간으로 나누어 넓이를 구한 뒤, 합산함

    int arr[1001] = {};
	int n;
	cin >> n;
	int idx;
	int high = 0;
	//입력을 받으면서 전체 최대 높이도 구함
    for (int i = 0; i < n; i++) {
		cin >> idx;
		cin >> arr[idx];

		if (high < arr[idx]) high = arr[idx];

	}
    //cur: 탐색을 하면서 본 최대 높이
    //l 탐색을 하면서 본 최대 높이의 위치
	int cur = 0, l = 0, ans = 0;
    //왼쪽부터 쭉 탐색하며 넓이를 더해나감
	for (int i = 1; i < 1000; i++) {
		if (arr[i] == 0) continue; //기둥이 없는 경우이므로 스킵
		if (arr[i] > cur) { //기둥이 지금까지 봤던 최대 높이보다 큰 경우에 지금까지 있던 넓이 합산
			ans += (i - l) * cur; //넓이 = 지금까지의 최대 높이 * (현재 위치 - 이전 최대 높이의 위치)
			//전체 최대 높이와 그 위치 갱신
            l = i; 
			cur = arr[i];
		}
        //만약 최대 높이를 만났다면 왼쪽 부분은 계산 끝!
		if (arr[i] == high) break;
	}
    //오른쪽의 경우, 오른쪽 끝에서부터 보면서 오면 왼쪽에서 구하는 방식이 같음
	//지금까지의 최대 높이와 그 위치 초기화
    cur = 0;
	int r = 1000;
    //오른쪽에서부터 탐색하며 넓이를 더해나감
	for (int i = 1000; i > 0; i--) {
		if (arr[i] == 0) continue; //기둥이 없는 경우이므로 스킵
		if (arr[i] > cur) { //기둥이 지금까지 봤던 최대 높이보다 큰 경우에 지금까지 있던 넓이 합산
			ans += (r - i) * cur; //넓이 = 지금까지의 최대 높이 * (이전 최대 높이의 위치 - 현재 위치)
			//지금까지의 최대 높이와 그 위치 갱신
            r = i;
			cur = arr[i];
		}
        //전체 최대 높이를 만났다면 오른쪽 부분 끝!
		if (arr[i] == high) break;
	}

    //마지막으로 가운데 부분 계산
	ans += (r - l + 1) * high;

	cout << ans;
	return 0;
}