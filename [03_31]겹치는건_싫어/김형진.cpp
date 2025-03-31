#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
int arr[200000] = {};

int main() {

    int N, K;
    cin >> N >> K;
    //모든 숫자를 저장하기 위한 배열


    //각 숫자의 위치를 저장하기 위한 queue의 map
    unordered_map<int, queue<int>> pos;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    //s: 조건을 만족하는 연속적인 수열의 시작지점 ㅣ: 조건을 만족하는 연속적인 수열의 최대 길이
    int s = 0, l = 0;
    for (int i = 0; i < N; i++) {
        int num = arr[i];
        //만약 다른 숫자에 의해 시작지점이 바뀌었고, 그래서 수열에서 배제된 num이 있다면 제거
        while (!pos[num].empty() and pos[num].front() < s) pos[num].pop();

        //num이 수열에 포함 될 수 있는 개수를 넘지 않음
        if (pos[num].size() < K) {
            pos[num].push(i);
        }

        //num이 수열에 포함 될 수 있는 개수를 넘음
        else {
            //지금까지의 최대 길이를 저장
            l = max(l, i - s);
            //가장 앞에 있는 num의 바로 뒤를 새로운 시작 지점으로 둠
            s = pos[num].front() + 1;

            //가장 앞에 있는 num을 제거하고 새로운 num을 넣음
            pos[num].pop();
            pos[num].push(i);
        }
    }
    //배열의 끝에서부터 출발해서 조건을 만족하는 수열의 길이를 셈
    l = max(l, N - s);
    cout << l;
    return 0;

}
