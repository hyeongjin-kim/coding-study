#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;
	int dur[200];
	bool isRobot[200];
	for (int i = 0; i < 2 * N; i++) {
		cin >> dur[i];
		isRobot[i] = false;
	}
	int startPoint = 0, step = 0, endPoint = N - 1;
	int zeros = 0;
	while (1) {
		++step;
		startPoint = (startPoint + 2 * N - 1) % (2 * N);
		endPoint = (endPoint + 2 * N - 1) % (2 * N);
		isRobot[endPoint] = false;
		for (int cur = endPoint; cur != startPoint; cur = (cur + 2 * N - 1) % (2 * N)) {
			int next = (cur + 2 * N - 1) % (2 * N);
			if (dur[cur] && isRobot[next] && !isRobot[cur]) {
				isRobot[next] = false;
				if (--dur[cur] == 0)
					++zeros;
				if (cur != endPoint)
					isRobot[cur] = true;
			}
		}
		if (dur[startPoint]) {
			if (--dur[startPoint] == 0)
				++zeros;
			isRobot[startPoint] = true;
		}
		if (zeros >= K)
			break;
	}
	cout << step;

	return 0;
}
