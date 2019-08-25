---
layout: note
title: 编译优化
subtitle: 创建时间 2015-10-20 00:00:00, 最后更新 2019-03-30 21:52:47
---

高效的程序：

* 合适的算法和数据结构
* 编写编译器能有效优化的代码
* 并行程序

## 编译器优化的能力和限制

* 优化安全性
    * memory aliasing-指向相同的指针
    * 函数调用的副作用(side effect)
        * 可以inline(-finline, -O2)

## 程序性能表示

* CPE(cycles per element)
    * cycles: 时钟周期数，element: 规模
    * CPE: 以cycles为纵轴，element为横轴, 最小二乘法拟合出的直线斜率

## 常见优化手法

### 机器无关优化

* code motion
    * 消除循环条件判断计算
* 减少程序调用
* 减少不必要的内存访问
    * 查看汇编
        * 循环中数组访问可以用临时变量替代
        
### 机器相关优化
指令并行执行

* latency bound: 数据依赖
* throughput bound
