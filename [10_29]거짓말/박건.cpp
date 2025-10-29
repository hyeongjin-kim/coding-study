#include <iostream>
#include <deque>
#include <vector>

#define endl '\n'

using namespace std;

int n, m;
int knc;
vector<int> party[51];
vector<int> g[51];
bool iskn[51];
int kn[51];
int arr[51];
deque<int> dq;
int res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> knc;

	for (int i = 0; i < knc; i++) {
		int a;
		cin >> a;
		iskn[a] = true;
		kn[i] = a;
	}

	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> arr[j];
			party[i].push_back(arr[j]);
		}

		for (int j = 1; j < k; j++) {
			g[arr[0]].push_back(arr[j]);
			g[arr[j]].push_back(arr[0]);
		}

	}

	for (int i = 0; i < knc; i++) {
		dq.push_back(kn[i]);
	}

	while (!dq.empty()) {
		int cur = dq.front(); dq.pop_front();

		for (int next : g[cur]) {
			if (iskn[next]) continue;
			iskn[next] = true;
			dq.push_back(next);
		}
	}

	for (int i = 0; i < m; i++) {
		int flag = true;
		for (int j = 0; j < party[i].size(); j++) {
			if (iskn[party[i][j]]) {
				flag = false;
				break;
			}
		}
		if (flag) res++;
	}
	
	cout << res << endl;

	return 0;
}
