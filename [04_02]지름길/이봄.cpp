#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

// 백준 1446 지름길
// 어떻게 풀어야할지.. 모르겠어서 알고리즘 분류를 참고했습니닷..ㅎ핳

using namespace std;

#define MAX_D 10005

int n,d;
int road[MAX_D]; // index - 위치, value - cost;
vector<tuple<int,int,int> > vec;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> d;

    for(int i=0; i<=d; i++){
        road[i] = i; // dp 할 배열 초기화
    }
    
    for(int i=0; i<n; i++){
        int s,e,cost;
        cin >> s >> e >> cost;
        vec.push_back({s,e,cost});
    }
    sort(vec.begin(), vec.end()); // dp 하기 위해 정렬. 0에서 가까운 순으로 업데이트 하기 위함.
    
    for(int i=0; i<n; i++){
        int s,e,cost;
        tie(s,e,cost) = vec[i];
        
        for(int j=s; j<=e; j++){
            if(j == 0)
                road[j] = 0;
            else
                road[j] = min(road[j], road[j-1] + (cost / (e-s))+1); // 이 값은 정확한 거리를 저장하진 않지만 단순 비교용으로 넣음
        }
        road[e] = min(road[e] , road[s]+cost); // 그래도 끝값은 정확해야 나중에 거리 계산을 정확히 할 수 있기 때문에.
        
        for(int j=e+1; j<=d; j++){
            road[j] = min(road[j], road[j-1] + 1); // 뒷부분도 최솟값으로 업데이트
        }
    }

    cout << road[d];
    
    return 0;
}
