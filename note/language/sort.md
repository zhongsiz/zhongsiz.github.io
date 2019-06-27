---
layout: note
title: 排序算法
subtitle: 创建时间 2014-12-20 00:00:00, 最后更新 2019-03-30 09:57:27
---

## 一、基本性质总结

### 1.1 稳定性
选择排序、快速排序、希尔排序、堆排序 是**不稳定排序**。

冒泡排序、插入排序、归并排序、基数排序 是**稳定排序**。

### 1.2 时间/空间复杂度
![sort algorithm](img/sort.jpg)

## 二、各个排序总结

[完整源码在这里](sourcecode/sort/basicsort.cpp)

### 2.1 冒泡排序（BubbleSort）

**思想**：交换相邻元素，将最大元素移到后面。

**代码**

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

### 2.2 选择排序（SelectSort）

**思想**：选择排序是给每个位置选择当前元素最小/最大的元素。

**代码**

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

### 2.3 插入排序（InsertSort）

**思想**：在有序序列中插入新的序列。

**代码**

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

### 2.4 归并排序（MergeSort）

**思想**：分治法，处理子数组，合并两个排好序的子数组

**代码**

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

### 2.5 基数排序（RadixSort）

**思想**：依次按个位/十位/百位...排序。

**代码**

    int radixSort(int *arr, int len) {
        const int BASE = 10;
        int maxVal = 0x80000000;
        for (int i = 0; i < len; ++i) {
            if (maxVal < arr[i]) maxVal= arr[i];
        }
        list&lt;int> bucket[BASE];
        for (int n = 1; maxVal >= n; n *= BASE) {
            for (int i = 0; i < len; ++i) {
                bucket[(arr[i] / n) % BASE].push_back(arr[i]);
            }
            for (int k = 0, i = 0; i < BASE; bucket[i++].clear()) {
                for (list&lt;int>::iterator j = bucket[i].begin(); j != bucket[i].end();
                            arr[k++] = *(j++));
            }
        }
        return 0;
    }

### 2.6 希尔排序（ShellSort）

**思想**：不同增量的插入排序，最后一个增量为1。

**代码**

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

### 2.7 堆排序（HeapSort）

**思想**：建堆，每次将根元素和尾元素交换，堆大小减少一，然后调整堆。

**代码**

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

### 2.8 快速排序（QuickSort）

快速排序是不稳定排序平均时间复杂度为\\(O(nlgn)\\)。

#### 思想

1. 数组A[s...e]划分为A[s...q-1]和A[q+1...e],使得A[s...q-1]都小于等于A[q]并且A[q+1...e]都大于等于A[q]。下标q也在划分中确定。
2. 递归调用，对字数组A[s...q-1]和A[q+1...e]进行排序。

#### 实现
主程序如下：

    void qsort(int* A, int s, int e) {
        if (s < e) {
            int q = partition(A, s, e);
            qsort(A, s, q - 1);
            qsort(A, q + 1, e);
        }
    }

划分可能有多种方法。

#### 统计小于key值的划分
选取最后一个元素为key值。遍历数组，用i标记当前位置小于key值的最大下标。对于遍历到的每个小于key的值，让它和i+1(首个大于key的元素)交换，代码如下：

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

#### 双指针移动方法
选取首元素为key值， low，hig分别指向数组头尾。

1. 从hig开始寻找首个小于key的值，填充到low位置
2. 从low开始寻找首个大于key的值，填充到hig位置

交换过程如下：

```cpp
A[low] = A[hig1]
A[hig1] = A[low1];
A[low1] = A[hig2];
...
A[low_n] = A[hig_n] = key;
```

代码如下：

```cpp
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
```

测试：[HDOJ1157](http://acm.hdu.edu.cn/showproblem.php?pid=1157), [源代码](sourcecode/sort/qsort_hdoj1157.cpp)
