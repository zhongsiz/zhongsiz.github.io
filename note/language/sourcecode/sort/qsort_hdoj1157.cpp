#include <iostream>

using namespace std;

int partition(int* A, int s, int e) {
	int key = A[e], i = s - 1;
	for (int j = s; j < e; ++j) {
		if (A[j] < key) {
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[e]);
	return i + 1;
}

int partition2(int* A, int s, int e) {
	int low = s, hig = e;
	int key = A[low];
	while (low < hig) {
		while (low < hig && key < A[hig]) --hig;
		if (low < hig) {
			A[low++] = A[hig];
		}
		while (low < hig && A[low] < key) ++low;
		if (low < hig) {
			A[hig--] = A[low];
		}
	}
	A[low] = key;
	return low;
}

void qsort(int* A, int s, int e) {
	if (s < e) {
		int q = partition2(A, s, e);
		qsort(A, s, q - 1);
		qsort(A, q + 1, e);
	}
}

int N, milk[10001];
int main() {
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			cin >> milk[i];
		}
		qsort(milk, 0, N - 1);
		cout << milk[N / 2] << endl;
	}
	return 0;
}