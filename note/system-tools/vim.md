---
layout: note
title: Vim
subtitle: 创建时间 2016-03-14 00:00:00, 最后更新 2019-08-17 21:54:42
---

## 参考
* [Practice Vim](https://book.douban.com/subject/10599776/)

## vim 命令行

### 打开多个文件
+ 竖直分割。`-On`
+ 水平分割。`-on`

## 移动
* 上下左右。 `k`, `j`, `h`, `l`, 行内(wrap)`gk`, `gj`
* 行内。首尾：`0`, `$`, 非空首尾：`^`, `g_`
* 单词。word: `w`, `e`, `b`
* 页内。视野内上中下：`H`, `M`, `L`, 首尾行：`gg`, `G`, 居中：`zz`
* 翻页。前后半页：`<C-u>`, `<C-d>`, 前后页： `<C-b>`, `<C-f>`。
* 匹配。
    * `%`。 匹配`{}`

## 编辑

### 插入

#### 行首非空。`I`
#### 行尾非空。`A`

### 格式化
+ `=`: indent

## 窗口
* 分割。`sp`, `vs`
* 跳转。映射`<C-w>h/j/k/l`到`<C-h/j/k/l>`
* 最大化/恢复。映射`<C-w>m`到`<C-w>_<C-w>|` ，恢复`<C-w>=`

## Insert模式
### 删除内容
* `<C-h>` -- 一个字符
* `<C-w>` -- 一个单词
* `<C-u>` -- 删除到开始

### Insert模式到Normal模式
* `Esc`
* `C-[`
* `C-o` -- Insert mode to Insert Normal mode

### Insert Normal模式
* insert mode -> normal mode(run only one command) -> insert mode

## 其他设置
### 编码
* 显示中文：`set fileencodings=utf-8,gb2312`

## 寄存器
#### Tip60 Vim寄存器
* 查看寄存器内容：`:reg "x`
* 插入模式使用寄存器：`<C-r>x`
* 寄存器种类
    * 匿名寄存器：`""`
    * Yank(复制)寄存器: `"0`
    * a-zA-Z寄存器
        * 小写的覆盖内容，大写的则是追加内容
    * 黑洞寄存器：`"_`
    * 剪切板寄存器和最近选择的文本寄存器：`"+`和`"*`(win和mac此寄存器功能和`"+`相同)
    * 表达式寄存器：`"=`，读取该寄存器将在命令行模式下等待用户输入语句并返回结果
    * 其他寄存器
        * 当前文件名：`"%`
        * alternate文件名：`"#`
        * 最后插入的文本：`".`
        * 最后的命令：`":`
        * 最后的搜索：`"/`

## Tip61 Visual模式下寄存器行为
* 可视模式下`p`会读取和**改变**寄存器
* 设置和跳转mark: `mx`, `\`x`

## Tip63 和系统剪切板交互
* 剪切板寄存器
* paste 选项
    * `:set paste!`
    * `:set pastetoggle=<f5>`
