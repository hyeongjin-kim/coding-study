#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, C;

    cin >> N >> C;
    //set의 특성 사용 중복 x, 정렬된 상태 유지
    set<int> s;
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        s.insert(a);
    }

    //가장 마지막 요소
    int dist = *(s.rbegin());
    //최소는 1
    int mindist = 1;
    
    
    while (mindist != dist) {
        // curdist = 가능한지 알아보고 싶은 거리 
        int curdist = dist -  (dist - mindist) / 2;
        //가장 앞의 집에 일단 하나 설치(여기에 설치하지 않을 이유가 없음)
        //이유: 이 뒷집부터 설치한다고 했을 때,
        // 1. 첫 집과 거리가 curdist보다 작은 집은 안됨
        // 2. 거리가 curdist 이상이라면, 1번 집에 설치가 가능함!
        int start1 = *(s.begin());
        int cnt = 1;
        for (int i = 0; i < C; i++) {
            //lowerbound : 인자로 넘겨준 값 이상이 나오는 첫번째 지점
            //즉 start보다 curdist 이상 떨어진 가장 첫번째 집의 itr 반환
            auto cur1 = s.lower_bound(start1 + curdist);
            //end인 경우, 그런 집이 없음
            if (cur1 == s.end()) {
                break;
            }
            start1 = *cur1;
            cnt++;
        }
        //C개를 설치할 수 없는 경우, 거리를 더 좁게 해야함
        if (cnt < C) {
            dist = curdist - 1;
            
        }
        //가능한 경우, 최소치 갱신
        else {
            mindist = curdist;
        }


    }
    //결과는 dist또는 mindist에 담겨있음
    cout << dist;

    return 0;

}
