#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

// QuickSort
int partition(int* A, int s, int e) {
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
int partition_2(int* A, int s, int e) {
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
void qsort(int* A, int s, int e) {
    if (s < e) {
        int q = partition(A, s, e);
        qsort(A, s, q - 1);
        qsort(A, q + 1, e);
    }
}
// insertion sort
int insertSort(int *arr, int len) {
	int temp, i, j;
	for (i = 0; i < len; ++i) {
		temp = arr[i];
		for (j = i; j >= 0 && arr[j] > temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j] = temp;
	}
	return 0;
}
// BubbleSort
int bubbleSort(int *arr, int len) {
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j < len - i; ++j) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	return 0;
}
// SelectSort
int selectSort(int *arr, int len) {
	for (int i = 0; i < len - 1; ++i) {
		int idx = i;
		for (int j = i + 1; j < len; ++j) {
			if (arr[idx] > arr[j]) {
				idx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
	return 0;
}
// MergeSort
int mergeSort(int *arr, int s, int e) {
	if (s < e) {
		int m = (s + e) >> 1;
		mergeSort(arr, s, m);
		mergeSort(arr, m + 1, e);
		// merge two sorted array
		int len1 = m - s + 1;
		int len2 = e - m;
		int *lArr = (int*) malloc(len1 * sizeof (int));
		int *rArr = (int*) malloc(len2 * sizeof (int));
		for (int i = 0; i < len1; ++i) lArr[i] = arr[s + i];
		for (int j = 0; j < len2; ++j) rArr[j] = arr[m + j + 1];
		for (int i = 0, j = 0, k = s; k <= e; ++k) {
			if (i == len1) {
				while (j < len2) arr[k++] = rArr[j++];
			} else if (j == len2) {
				while (i < len1) arr[k++] = lArr[i++];
			} else if (lArr[i] < rArr[j]) {
				arr[k] = lArr[i++];
			} else if (lArr[i] > rArr[j]) {
				arr[k] = rArr[j++];
			}
		}
	}
	return 0;
}

// HeapSort
void maxHeap(int *arr, int root, int heapSize) {
	while (root < heapSize) {
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int idx = root;
		if (left < heapSize && arr[idx] < arr[left]) { idx = left; }
		if (right < heapSize && arr[idx] < arr[right]) { idx = right; }
		if (idx != root) {
			swap(arr[root], arr[idx]);
			root = idx;
		} else {
			break;
		}
	}
}
void buildMaxHeap(int *arr, int heapSize) {
	for (int i = heapSize / 2; i >= 0; --i) {
		maxHeap(arr, i, heapSize);
	}
}
int heapSort(int *arr, int len) {
	buildMaxHeap(arr, len);
	for (int i = len - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		maxHeap(arr, 0, i - 1);
	}
	return 0;
}
// ShellSort
int shellSort(int *arr, int len) {
	// using Marcin Ciura's gap;
	int gaps[8] = { 701, 301, 132, 57, 23, 10, 4, 1 };
	for (int i = 0; i < 8; ++i) {
		int gap = gaps[i];
		for (int j = gap; j < len; ++j) {
			int temp = arr[j], k;
			for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
				arr[k] = arr[k - gap];
			}
			arr[k] = temp;
		}
	}
	return 0;
}
// RadixSort
int radixSort(int *arr, int len) {
	const int BASE = 10;
	int maxVal = 0x80000000;
	for (int i = 0; i < len; ++i) {
		if (maxVal < arr[i]) maxVal= arr[i];
	}
	list<int> bucket[BASE];
	for (int n = 1; maxVal >= n; n *= BASE) {
		for (int i = 0; i < len; ++i) {
			bucket[(arr[i] / n) % BASE].push_back(arr[i]);
		}
		for (int k = 0, i = 0; i < BASE; bucket[i++].clear()) {
			for (list<int>::iterator j = bucket[i].begin(); j != bucket[i].end();
						arr[k++] = *(j++));
		}
	}
	return 0;
}

int main() {
	// test MergeSort
	int arr_merge[] = {5, 9, 8, 6, 7, 1, 4, 3};
	mergeSort(arr_merge, 0, 7);
	for (int i = 0; i < 8; ++i)
		cout << arr_merge[i] << " ";
	cout << endl;

	// test insertSort
	cout << "InsertSort: ";
	int arr_insert[] = {5, 9, 8, 6, 7, 1, 4, 3};
	mergeSort(arr_insert, 0, 7);
	for (int i = 0; i < 8; ++i)
		cout << arr_insert[i] << " ";
	cout << endl;

	// test ShellSort
	cout << "ShellSort: ";
	int arr_shell[] = {5, 9, 8, 6, 7, 1, 4, 3};
	shellSort(arr_shell, 8);
	for (int i = 0; i < 7; ++i)
		cout << arr_shell[i] << " ";
	cout << endl;

	// test HeapSort
	int arr[] = {5, 9, 8, 6, 7, 1, 4, 3};
	heapSort(arr, 8);
	int arr1[] = {5, 9, 8, 6, 7, 1, 4};
	heapSort(arr1, 7);
	for (int i = 0; i < 8; ++i)
		cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < 7; ++i)
		cout << arr1[i] << " ";
	cout << endl;
	// test RadixSort
	cout << "RadixSort: ";
	int arr_radix[] = {5, 9, 8, 6, 7, 1, 4, 3};
	shellSort(arr_radix, 8);
	for (int i = 0; i < 7; ++i)
		cout << arr_radix[i] << " ";
	cout << endl;

}
