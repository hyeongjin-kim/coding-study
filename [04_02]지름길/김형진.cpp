#include <iostream>
#include<queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    
    int N, D;
    cin >> N >> D;
    //모든 지름길을 저장할 배열 {출발지점, 도착지점, 거리}
    int path[12][3];
    //지금까지 간 거리, 현재 위치를 저장할 pq
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>  > q;
    memset(path, 0, sizeof(path));
    //시작 지점 삽입
    q.push({ 0,0});

    //지름길 받기
    for (int i = 0; i < N; i++) {
        cin >> path[i][0] >> path[i][1] >> path[i][2];
    }

    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        int time = cur.first,  pos = cur.second;
        //정확히 도로의 끝에 도착했으면 끝
        if (pos == D) {
            cout << time;
            break;
        }
        //도로를 넘어가면 역주행은 안되니까 제외
        else if (pos > D) continue;


        //현재 위치에서 지름길의 위치가 더 앞에 있는 경우 지름길을 탄 세계선 추가
        //그때 거리는 현재 거리 + 지름길까지 가는 거리 + 지름길 거리
        for (int i = 0; i < N; i++) {
            if (path[i][0] >= pos) {
                q.push({ time + path[i][2] + path[i][0] - pos ,path[i][1]});
            }
        }
        //지름길을 안타고 그대로 나간 경우
        q.push({ time + D - pos , D});
    }

    return 0;

}
