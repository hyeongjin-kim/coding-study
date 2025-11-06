#include <iostream>
#include <queue>

using namespace std;

int n, w, l;
int arr[1010];
struct node {
	int time, value;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> w >> l;

	for (int i = 0; i < n; i++) cin >> arr[i];

    queue<node> bridge;
    int time = 0;
    int sum = 0;
    int i = 0;

    while (i < n || !bridge.empty()) {
        time++;

        while (!bridge.empty() && bridge.front().time == time) {
            sum -= bridge.front().value;
            bridge.pop();
        }

        if (i < n && sum + arr[i] <= l) {
            sum += arr[i];
            node nd;
            nd.time = time + w;
            nd.value = arr[i];
            bridge.push(nd);
            i++;
        }
    }

	cout << time;

	return 0;
}
