#include <iostream>

using namespace std;

int arr[100001]; //인덱스는 1 ~ 10만까지 사용함 그래야 배열로 힙을 유지할 수 있음
int cnt = 1; //다음에 들어온 원소가 들어올 인덱스



int main() {
	//입출력 버퍼의 연결을 해제해 최적화 이거 없으면 안풀리더라,,
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int cmd;
	
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		//pop
		if (cmd == 0) {
			//빈 경우
			if (cnt == 1) {
				cout << "0\n";
				
			}
			else {
				//top의 원소 출력
				cout << arr[1] << '\n';
				//top의 자리에 가장 마지막 위치의 원소를 가져와 제자리를 찾게 함
				arr[1] = arr[cnt - 1];
				
				int idx = 1;
				//하위 원소가 있을 때 까지
				while (idx * 2 < cnt - 1) {
					//왼쪽 하위 원소
					int child = idx * 2;
					//오른쪽 하위 원소가 더 작은 경우 이것과 비교
					if (child  + 1 < cnt - 1 and arr[child + 1] < arr[child]) child++;
					//현재 원소가 하위 원소보다 큰 경우 바꿈
					if (arr[idx] > arr[child] ) {
						int tmp = arr[idx];
						arr[idx] = arr[child];
						arr[child] = tmp;
						idx = child;
					}
					
					else break;
				}
				cnt--;
			}
			
		}

		else {
			//새 원소를 가장 마지막 위치에 넣고 제 자리를 찾으며 올라옴
			arr[cnt] = cmd;
			int idx = cnt;
			while (idx > 1) {
				//부모 원소보다 작은 경우 바꿈
				if (arr[idx] < arr[idx / 2]) {
					int tmp = arr[idx];
					arr[idx] = arr[idx/2];
					arr[idx /2] = tmp;
					idx = idx / 2;
				}
				else break;
			}
			cnt++;
		}
	}

	return 0;
}
