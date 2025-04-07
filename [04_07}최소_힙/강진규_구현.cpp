#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int heap[100001];
	int end = 0;
	memset(heap, 0, 100001 * sizeof(int));
	int N;
	cin >> N;
	while (N--) {
		int inp;
		cin >> inp;
		if (inp) {
			heap[++end] = inp;
			for (int i = end;i >= 2;i /= 2) {
				if (heap[i] < heap[i / 2]) {
					swap(heap[i], heap[i / 2]);
				}
				else
					break;
			}
		}
		else {
			cout << heap[1] << '\n';
			heap[1] = heap[end];
			heap[end] = 0;
			if (end > 0)
				--end;
			for (int i = 1;i * 2 <= end;) {
				if (i * 2 + 1 <= end) {
					if (heap[i] <= heap[i * 2]) {
						if (heap[i] <= heap[i * 2 + 1]) {
							break;
						}
						swap(heap[i], heap[i * 2 + 1]);
						i = i * 2 + 1;
					}
					else {
						if (heap[i * 2] < heap[i * 2 + 1]) {
							swap(heap[i], heap[i * 2]);
							i *= 2;
						}
						else {
							swap(heap[i], heap[i * 2 + 1]);
							i = i * 2 + 1;
						}

					}
				}
				else {
					if (heap[i] > heap[i * 2])
						swap(heap[i], heap[i * 2]);
					break;
				}
			}
		}
	}
	return 0;
}
