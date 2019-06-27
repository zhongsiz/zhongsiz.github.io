---
layout: note
title: Zsh
subtitle: 创建时间 2015-10-26 00:00:00, 最后更新 2019-03-18 15:28:51
---
## 快捷键

### 历史命令
* 显示历史命令
  * 上下箭头滚动
  * 打出一个列表: `history`
  * 搜索历史命令: `Ctrl`+`R`
  * 上次命令参数：`!$`
* 执行历史命令
  * 根据某个id执行：`![cmdid]`
  * 执行上次命令: `!!`
  * 执行上次用到的某个命令(如cat)：`!cat`
    * 仅显示：`!cat:p`

### 移动
* 行开头和结尾: `Ctrl`+`A`，`Ctrl`+`E`
* 按一个单词移动
  * 默认：`Esc` + `f`, `Esc` + `b`
  * 可以更改键设置: `Option` + `f`, `Option` + `b`

### 展开
* 大括号
  * 多个文件名: `mv /path/to/file.{txt,xml}`
  * 缩写文件名: `cp /etc/rc.conf{,-old}` and `cp /etc/rc.conf{-old,}`

### 编辑
* 变化大小写
  * 当前位置到结尾变成大写：`Alt`+`u`
  * 当前位置到结尾变成小写：`Alt`+`l`
* 删除
  * 开始到当前位置：`Ctrl`+`u`
  * 当前位置到结尾：`Ctrl`+`k`
  * 前一个单词：`Ctrl`+`w`
  * 前后一个字符：`Ctrl`+`h`, `Ctrl`+`d`
  * 清除行
    * **Ctrl+C**: Cancel input command.
    * **Ctrl+A** and **Ctrl+K**: First jump then delete.

### 终止
* `Ctrl`+`C`: 发送`SIGINT`信号，可以被其他程序拦截
* `Ctrl`+`Z`: 发送`SIGSTOP`信号，无法被拦截，可以用`fg`, `bg`移到后台，前台

### 文件路径
* 自动补全
  * `Tab`
  * fzf： `ls **<Tab>`
* 当前路径，上层路径: `.`, `..`
* 上一次路径: `-`

## 参考资料
* [Become a Command Line Ninja With These Time-Saving Shortcuts](http://lifehacker.com/5743814/become-a-command-line-ninja-with-these-time-saving-shortcuts)
* [Bash Shortcuts For Maximum Productivity](http://www.skorks.com/2009/09/bash-shortcuts-for-maximum-productivity/)
