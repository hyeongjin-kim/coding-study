#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, K;
int arr[100001]; //해당 인덱스 위치에 도달하기 위한 최소 시간 표시시

int main() {

    cin >> N >> K;
    //수가 작아지는 방법은 1씩 빼는 것밖에 없음 따라서 작은 수라면 동생과의 거리만큼 시간이 걸림
    if (K <= N) {
        cout << N - K;
        return 0;
    }
    fill(arr, arr + 100001, 100000); //최대치로 초기화
    arr[N] = 0; //출발지점 표시
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //최소 힙 사용 -> 시간이 덜 걸리는 순으로, 출발지점에서 가까운 순으로 시작해야하기 때문
    q.push({ 0, N });
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int time = cur.first;
        int idx = cur.second;
        if (arr[idx] >= time) { //지금 보고 있는 노드가 최소에 해당한다면
            
            if ((idx - 1) >= 0 and time + 1 < arr[idx - 1]) { // 한칸 앞으로 가는 것이 지금까지 기록된 것보다 빠르면
                arr[idx - 1] = time + 1;
                q.push({ time + 1, idx - 1 });
            }
            if ((idx + 1) <= 100000 and time + 1 < arr[idx + 1]) { // 한칸 뒤뒤로 가는 것이 지금까지 기록된 것보다 빠르면
                arr[idx + 1] = time + 1;
                q.push({ time + 1, idx + 1 });
            }
            if ((idx * 2) <= 100000 and time < arr[idx * 2]) { // 두배 순간이동하는 것이 지금까지 기록된 것보다 빠르면
                arr[idx * 2] = time;
                q.push({ time, idx * 2 });
            }
        }

    }
    cout << arr[K]; //최종 결과 출력
    return 0;
}
