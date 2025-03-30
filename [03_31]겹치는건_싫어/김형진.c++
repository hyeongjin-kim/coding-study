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
    //��� ���ڸ� �����ϱ� ���� �迭


    //�� ������ ��ġ�� �����ϱ� ���� queue�� map
    unordered_map<int, queue<int>> pos;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    //s: ������ �����ϴ� �������� ������ �������� ��: ������ �����ϴ� �������� ������ �ִ� ����
    int s = 0, l = 0;
    for (int i = 0; i < N; i++) {
        int num = arr[i];
        //���� �ٸ� ���ڿ� ���� ���������� �ٲ����, �׷��� �������� ������ num�� �ִٸ� ����
        while (!pos[num].empty() and pos[num].front() < s) pos[num].pop();

        //num�� ������ ���� �� �� �ִ� ������ ���� ����
        if (pos[num].size() < K) {
            pos[num].push(i);
        }

        //num�� ������ ���� �� �� �ִ� ������ ����
        else {
            //���ݱ����� �ִ� ���̸� ����
            l = max(l, i - s);
            //���� �տ� �ִ� num�� �ٷ� �ڸ� ���ο� ���� �������� ��
            s = pos[num].front() + 1;

            //���� �տ� �ִ� num�� �����ϰ� ���ο� num�� ����
            pos[num].pop();
            pos[num].push(i);
        }
    }
    //�迭�� ���������� ����ؼ� ������ �����ϴ� ������ ���̸� ��
    l = max(l, N - s);
    cout << l;
    return 0;

}
