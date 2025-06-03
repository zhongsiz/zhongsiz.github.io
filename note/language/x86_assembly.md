---
layout: note
title: x86汇编
---

# 参考
* CSAPP第3章

# AT&T语法和Intel语法
* `AT&T` -- GNU Assembly(GAS)
    * 助记符 src, dest
    * 后缀(操作数大小) -- "b", "s", "w", "l", "q", "t"
    * 前缀: 寄存器 -- `%`, 常量 -- `$`
    * 地址操作数

            segment:displacement(base register, offset register, scalar multiplier) # at&t
            segment:[base register + displacement + offset register * scalar multiplier] # intel
* Intel语法
    * 助记符 dest, src
    * 无前后缀

# 寄存器
* 常用寄存器: eax, ecx, edx, ebx, esi, edi, esp, ebp
    * 说明
        * 前六个可以称为通用寄存器
        * 前四个可取低16位，或低16位中的各8位: ax, ah, al
* 控制寄存器
    * CF(carry flag), ZF(zero flag), SF(sign flag), OF(overflow flag)

# 指令
* 操作数形式
    ![Operand Form](img/Operand.png)

    * 数据移动mov指令(操作数不能都是内存): movb, movsbl, movzbl
    * 算术操作符
        * `lea`: 获取有效地址
        * 移位，加减乘除等
    * 控制操作符
        * 测试，比较指令：test, cmp
        * 设置控制寄存器: sete, sets, setl, seta, setb
    * 跳转: jmp
        * 直接跳转
        * 间接跳转
    * condition mov指令(有利于cpu流水线): cmove, cmovs, cmovl, cmova, cmovb

# 基本组成部分

## 基本元素
* 汇编器伪指令: `.file .text`
* 指令

## 汇编文件组成
* Segments(段)
    * code
    * data
    * stack

## 生成汇编
* gcc: `gcc -S`
* 反汇编 `objdump -d`

# 基本结构汇编生成

## if-else

    if (test-expr)        |    t = test-expr;
        then-statement    |    if (!t)
    else                  |        goto false;
        else-statement    |    then-statement
                          |    goto done;
                          |  false:
                          |     else-statement
                          |  done:

## do-while

    do                    |  loop:
        body-statement    |     body-statement
    while (test-expr);    |     t = test-expr;
                          |     if (t)
                          |         goto loop;

## while循环
转换成do-while

    while (test-expr)     |    if (!test-expr)         |    t = test-expr;
        body-statement    |        goto done;          |    if (!t)
                          |    do                      |        goto done;
                          |        body-statement      |  loop:
                          |        while (test-expr);  |     body-statement
                          |    done:                   |     t = test-expr;
                                                       |     if (t)
                                                       |         goto loop
                                                       |  done:

## for循环
转换成while

    for (init-expr; test-expr; update-expr)    |    init-expr;
        body-statement                         |    while (test-expr) {
                                               |        body-statement
                                               |        update-expr;
                                               |    }

## condition move

    v = test-expr ? then-expr : else-expr;    |    vt = then-expr;
                                              |    v = else-expr;
                                              |    t = test-expr;
                                              |    if (t) v = vt;

## switch语句
根据case数目和范围选择jump table实现

* jump table在rodata中声明, 存放case指令入口
* 通过间接跳转进入case对应代码

## 数组
通过base, index, scalar返回元素

    int E[i]    |    # E <-- %edx, i <-- %ecx
                |    movl (%edx, %ecx, 4), %eax

* 多维数组看成一维数组计算地址
* 固定数组相乘一些优化

        int prod(mat A, mat B, int i, int k) {  |  int prod(mat A, mat B, int i, int k) {
            int j, result = 0;                  |      int Arow = &A[i][0];
            for (j = 0; j < N; ++j)             |      int Bptr = &B[0][k];
                result += A[i][j] * B[j][k]     |      int j, result = 0;
            return result;                      |      for (j = 0; j != N; ++j) {
        }                                       |          result += Arr[j] * *Bptr;
                                                |          Bptr += N;
                                                |      }
                                                |      return result;
                                                |  }
* 动态分配多维数组需要在运行时获得数组维数
    * Register spilling: 寄存器不足是需要将变量(只读)存放在内存中

## struct和union
通过offset访问变量

## 对齐
简化处理器和内存的接口：`.align 4`

## 浮点数
* x87
* sse

# 栈-Stack

## 参考
* [Wikipedia Call stack](https://en.wikipedia.org/wiki/Call_stack)
* CSAPP
* [GCC中栈和calling convention宏设置](https://gcc.gnu.org/onlinedocs/gccint/Stack-and-Calling.html#Stack-and-Calling)

![stack](img/linux_runtime_memory_image.jpg)

* 增长: 向下增长, 从高地址到低地址
* 寄存器
    * `rsp` -- stack pointer, 指向栈顶
    * `rbp` -- frame pointer, 指向栈底(前一个栈stack pointer存放位置)
* 操作(64位)
    * 入栈: `push %rbp`, 相当于 `subq $8, %rsp` 和 `movq %rbp, (%rsp)`
    * 出栈: `pop %rbp`, 相当于 `movq (%rsp), %rbp` 和 `addq $8, %rsp`

## 保护栈
函数调用前需要保护caller的帧栈，返回时恢复.

    pushq %rbp
    movq %rsp, %rbp # 新的frame pointer
    # 处理
    ...
    leave # 相当于 movq %rbp, %rsp 和 pop %rbp
    retq # 控制流移到栈顶的返回地址(由callq指令压入), %rip <- pop()

## 示例
* 代码: `fn1(arg) { fn2(p1, p2); }`
* 调用过程
    * 参数 p2 和 p1 压入栈(实际参数较少时会通过寄存器传递)
    * 调用fn2: `callq fn2`, 将返回地址入栈并跳到fn2的入口
    * 保存fn1栈: `pushq %rbp`
    * 更新frame pointer: `movq %rsp, %rbp`
    * 执行fn2
    * 恢复fn1栈: `leave`
    * 控制流回到caller fn1: `ret`
* 过程如下

        |-------------------------------|
        |     parameters for fn1        |
        |-------------------------------|
        |     return address            |
        +-------------------------------+   <---  Stack frame for fn1
        +     previous frame pointer    +
        +-------------------------------+
        +     locals of fn1             +
        +-------------------------------+
        +     parameters p2             +
        +-------------------------------+
        +     parameters p1             +
        +-------------------------------+
        +     return address            +
        |-------------------------------|   <---  Stack frame for fn2
        |     previous frame pointer    |
        |-------------------------------|   <---  Frame Pointer
        |     locals of fn2             |
        |-------------------------------|   <---  Stack Pointer
               top of stack

## 栈大小
* 进程最大栈空间(KB, 如8196KB=8MB)：`ulimit -s`
* 进程最大栈空间sys/resource.h(Byte): `getrlimit(RLIMIT_STACK, &rlim)`
* 线程：默认2MB, 最小是16KB(PTHREAD_STACK_MIN)

        On Linux/x86-32, the default stack size for a new thread is 2 megabytes. Under the NPTL threading implementation,
        if the RLIMIT_STACK soft resource limit at the time the program started has any value other than "unlimited",
        then it determines the default stack size of new threads.

# Calling Conversion(AMD64 ABI)

## 寄存器使用
* Callee Save寄存器: Callee在返回前必须恢复原值, RBX RBP R12-R15, 其他寄存器均可以任意使用.
* Caller Save寄存器: Callee可改变
    * 传参: 整形参数使用RDI RSI, RDX, RCX, R8, R9, 浮点型参数使用XMM0-7.
    * 程序返回值: 整形使用RAX, RDX, 浮点型使用XMM0, XMM1.
