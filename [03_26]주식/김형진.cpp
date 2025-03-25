#include <iostream>
#include <queue>
using namespace std;

int main() {

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        int num;
        priority_queue<pair<int, int>> q; //max heap을 이용한 pq
        for (int i = 0; i < n; i++) {
            cin >> num;
            q.push({ num, i }); //그날의 주가, 날짜를 넣음
        }
        int last = -1; //주식을 매도한 날
        long long answer = 0;
        while (!q.empty()) { 
            auto cur = q.top(); //가장 주가가 비싼 날부터, 가장 먼 날부터 나옴
            q.pop();
            if (cur.second > last + 1) { //직전에 매도한 날이 아니라면, 팔 주식이 있음 주식을 팜
                answer += long(cur.first) * (long)(cur.second - last - 1);
                last = cur.second; //매도일 기록
            }
            else if (cur.second < last) { //매도일 이전이면 이 날에는 주식을 사야함
                answer -= cur.first;
            }
            else {//매도일 직후라면 팔 주식이 없음 이 뒤로는 이보다 더 비싼 날이 없으므로 넘어감
                last = cur.second; 
            }
        }
        cout << answer << '\n';
    }


    return 0;
}