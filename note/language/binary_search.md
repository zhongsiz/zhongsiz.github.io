---
layout: note
title: 二分查找
---

<script type="text/javascript" src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

下标计算(加减优先级大于移位运算)：$$mid=left+(right-left >> 1)$$

# STL算法

头文件: `<algorithm>`

1. `binary_search`: 查找目标元素

        ```cpp
        template<class ForwardIt, class T>
        bool binary_search(ForwardIt first, ForwardIt last, const T& value);
        ```
2. 查找边界
    1. `lower_bound`: 查找区间$$[first, last)$$中第一个不小于value的元素位置

        ```cpp
        template<class ForwardIt, class T>
        ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value);
        ```
    2. `upper_bound`: 查找区间$$[first, last)$$中第一个不大于value的元素位置

        ```cpp
        template<class ForwardIt, class T>
        ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value);
        ```

# 循环不变式
1. 初始化: 第一次循环前是正确的
2. 保持：每次循环后保持正确
3. 终止: 循环能终止并能得到预期结果

# 查找元素
保持开闭区间一致性

## 闭区间$$[left, right]$$
循环条件：$$left \le right$$

1. 如果$$arr[mid] = value$$, 返回下标
2. 如果$$arr[mid] < value$$, 继续搜索$$[mid+1, right]$$区间
3. 如果$$arr[mid] > value$$, 继续搜索$$[left, mid-1]$$区间

## 开区间$$[left, right)$$
循环条件：$$left < right$$

1. 如果$$arr[mid] = value$$, 返回下标
2. 如果$$arr[mid] < value$$, 继续搜索$$[mid+1, right)$$区间
3. 如果$$arr[mid] > value$$, 继续搜索$$[left, mid)$$区间

# 查找首次出现
循环条件：$$left < right$$

1. 如果$$arr[mid] < value$$, 继续搜索$$[mid+1, right]$$区间
2. 如果$$arr[mid] \ge value$$, 继续搜索$$[left, mid]$$区间

终止时$$left=right$$(不可能大于), 需要判断$$arr[left]=value$$

# 查找末次出现

## 死循环处理法
循环条件：$$left < right$$

1. 如果$$arr[mid] > value$$, 继续搜索$$[left, mid-1]$$区间
2. 如果$$arr[mid] = value$$
    1. 如果$$mid=left$$(可能出现死循环)
        1. 如果$$arr[right]=value$$, 返回right
        2. 否则返回$$left$$
    2. 否则继续搜索$$[mid, right]$$区间
3. 如果$$arr[mid] < value$$, 继续搜索$$[left, mid-1]$$区间

终止时$$left=right$$, 需要判断$$arr[right]=value$$即可

## 将死循环加入条件判断
终止条件：$$left < right-1$$, 即终止前循环都会使区间减少

1. 如果$$arr[mid] \le value$$, 继续搜索$$[mid, right]$$区间
2. 如果$$arr[mid] > value$$, 继续搜索$$[left, mid-1]$$区间

终止时$$left=right-1$$, 需要分别比较$$arr[right]$$, $$arr[left]$$和$$value$$即可

## 数组倒置，采用寻找首个元素的写法

# 查找刚好小于某个值的元素
循环条件：$$left < right-1$$, 即终止前循环都会使区间减少

1. 如果$$arr[mid] < value$$, 继续搜索$$[mid, right]$$区间
2. 如果$$arr[mid] \ge value$$, 继续搜索$$[left, mid-1]$$区间

循环结束分别判断$$arr[right]$$和$$arr[left]$$的值

# 查找刚好大于某个值的元素
循环条件：$$left < right$$, 即终止前循环都会使区间减少

1. 如果$$arr[mid] > value$$, 继续搜索$$[left, mid]$$区间
2. 如果$$arr[mid] \le value$$, 继续搜索$$[mid+1, right]$$区间

循环结束判断$$arr[right]$$的值

# 总结
循环条件和死循环关系

1. $$left=right$$：每次循环后的新区间必须不能包含$$mid$$
2. $$left<right$$：每次循环后的新区间必须不能有$$left=mid$$情况
3. $$left<right-1$$：不会发生死循环，结束时区间大小为2，必须检查两个值
