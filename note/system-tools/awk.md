---
layout: note
title: Awk
subtitle: 创建时间 2015-11-16 00:00:00, 最后更新 2019-03-17 23:52:52
---

    awk '/good/{print $1 " " $3}' inventory

**awk** read one line at a time, then compare each line with pattern, do some action if matched.

* Syntax
    `awk -f {awk program file} filename`
* awk Program:

        Pattern {
            action 1
            action 2
            action N
        }
* Metacharacters
    `.(Dot) | * | ^ | $ | \ | [] | {} | + | ? | | |`

    * {} Match range of instance
    * `|` Separate choices to match
* Predefined variable
    * $1 $2 etc assign any value found in field
    * $0 print entire record
* Program file
    * create awk file

            cat > prn_pen
            /Pen/{ print $3 }
    * execute command

            `awk -f prn_pen inven`
    * Others.
        `awk '$3 > 5 { print $0}'` compare the third of database with 5, if found, print the entire record.
* Predefined variable
    * FILENAME - name of current input file
    * RS - Input record separator character(Default is new line)
    * OFS - Output field separator string(Blank is default)
    * ORS - Output record separator string(Default is new line)
    * NF - Number of input record
    * NR - Number of field in input record
    * OFMT - Output format of number
    * FS - Field separator character(Blank & tab is default)
* Define user variable

        {
            total = $3 * $4
            recno = $1
            item  = $2
            print recno item " Rs. " total
        }
* BEGIN and END pattern - print position control

        BEGIN {
            action 1
            action 2
            action N
        }
        END {
            action 1
            action 2
            action N
        }
* Format output - printf
    * `%d | %x | %c | %S`
    * %10s - right justified  %-10s left justified
* if condition

        if ( condition )
        {
            statement 1
            statement 2
            statement N
            if condition is TRUE
        }
        else
        {
            statement 1
            statement 2
            statement N
            if condition is FALSE
        }
* For loop and while do loop is the same as c programming language
* Execute shell command -- `system(shellcmd)`
    * return 0 if execute successfully
    * return 1 if fail
* Input
    * from keyboard -- `getline na < "-"`
    * from file -- `getline < "filename"`
    * from pipe -- `"command" | getline`
