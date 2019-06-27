---
layout: note
title: C++模板
subtitle: 创建时间 2016-05-21 00:00:00, 最后更新 2019-03-30 23:00:23
---

## 一些用法

### .template构造
调用依赖于模板参数对象的模板成员时（显示指定模板参数列表）,需要使用.template构造。

    template <int N>
    void printBitset(std::bitset<N> const& bs) {
        std::cout << bs.template to_string<char, std::char_traits<char>,
                                           std::allocator<char>>();
    }

### 模板的模板参数
* 参数类型只能用class关键字(c++17允许typename)
* 完全匹配
* 没用用到的名字可以省略

    template <typename T,
              template <typename ELEM, typename = std::allocator<ELEM>>
              class CONT = std::deque>
    class Stack;

### policy类
实例：累加一个序列

* 返回值类型选择
* 初始值选择
* 累加的含义(policy)

#### fixed trait

```cpp
template<typename T> class accum_traits;
template<>
class accum_traits<char> {
public:
    using ret_type = int;
    static ret_type zero { return 0; }
};
template<>
class accum_traits<float> {
public:
    using ret_type = double;
    static ret_type zero { return 0.0; }
};
```

#### 参数化trait
* 类模板添加具有缺省值的模板参数(trait)

```cpp
template <typename T,
          typename AT = accum_traits<T>>
class accum {
    // ...
};
```

#### policy类
注重行为

```cpp
template <typename T,
          typename Policy = SumPolicy,
          typename AT = accum_traits<T>>
class accum {
    // ...
};
```

使用模板的模板参数

```cpp
template <typename T,
          template<typename, typename> class Policy = SumPolicy,
          typename AT = accum_traits<T>>
class accum {
    // ...
    Policy<ret_type, T>::accumulate()
};
```
