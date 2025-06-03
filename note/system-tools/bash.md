---
layout: note
title: Bash脚本
---

    #!/usr/bash

# Basic Usage
* Variable:
    * Assignment`=`: no spaces around
    * Case-sensitive
    * NULL
        * `vech=`
        * `vech=""`
    * expr op1 operator op2
        * must space between number and operator
        * sum: `expr $A + $B`
        * mutiply: `expr 10 \* 3`
* Redirector
    * `>`: overwritten or create new file
    * `>>`: add or create new file
    * `<`: input from file instead of key-board
    * file descriptor
        1. stdin-0
        2. stdout-1
        3. stderr-2
            * redirect stderr `rm bad_file_name111 2> er`
            * redirect stdout to stderr: `echo "hah" 1>&2`
* Pipe
    A temporar storage place for one command's output and passed as the input for second command

    * `c| command2`: `more`, `less`
    * Filter
        A command accepts its input from the standard input and produces its output on the standard output
* Debug
    `sh/bash option { shell script name }`

    1. -v: Print shell input lines as they are read
    2. -x: Display command and expanded value
* Others
    * Return value - `echo $?`
        * 0  successful
        * not zero: fail
    * `/dev/null`-send unwanted output from command/program
    * `export`-Define global variable
    * `command1 && command2 || command3`
        1. if command1 execute successfully then execute command2
        2. else execute command3
    * `trap` command: `trap { commands} {signal number list}`
        1. 0-shell exit
        2. hangup
        3. interrupt(CTRL+C)
        4. quit
        5. kill(cannot be caught)
    * `shift`-move positional parameters left
        `shift n`
    * `ENVIRON` is a array of predefined system variable
        1. ENVIRON["HOME"] -- home directory
        2. ENVIRON["USER"] -- login user
    * Include other shell script
        * `source FILE`
        * `. FILE` -- POSIX compliant
    * More comand on one command line: `date;who`
    * Run command background: `ls / -R | wc -l &`
        * `&` run in background

## Syntax
* if
    condition is a `test expression` OR `[ expression ]`

        if condition
        then
            #XXX
        elif condition1
        then
            #xxx
        else
            #xxx
        fi
* Loops
    1. for Loop:

            for { variable name } in { list }
            for (( expr1; expr2; expr3 ))
            do
                #xxx
            done
    2. while loop

            while [ condition ]
            do
                command1
                command2
                command3
            done
* Case statement

        case $variable-name in
            pattern1) command
                        ...
                        command;;
            pattern2) command
                        ...
                        command;;
            *)          command
                        ...
                        command;;
        esac
* Function
    1. syntax

            function-name()
            {
                command1
                command2
                commandN
                return
            }
    2. parameter: $* $1 $2 $@ $#

# Useful utility

## getopt command
`getopts {opstring} {variable}`

1. opstring-n:a:s:w:d , d don't have argument.
2. place next option in the variable.
3. for illegal option, place ? into variable

## test command
test works with:

1. Integer
2. File types
3. Character strings
4. Operation:
    1. Mathematical operator: `1. -eq/-ne/-lt/-le/-gt/-ge`
    2. String comparisions:
        1. string1 = string2
        2. string1 != string2
        3. string1 #string1 not NULL or not defined
        4. -n string1 #string1 not NULL and does exist
        5. -z string1 #string 1 is NULL and does exist
    3. For file and directory
        1. `-s file`-Non empty file
        2. `-f file`-Is file exist or normal file and not a directory
        3. `-d dir`-Is directory exist and not a file
        4. `-w file`-Is writeable file
        5. `-r file`-Is read-only file
        6. `-x file`-Is file is executable
    4. Logical Operators
        1. `!expression`-Logical NOT
        2. `expression1 -a expression2`-Logical AND
        3. `expression1 -o expression2`-Logical OR

## Others
* `cut` --utility-selecting portion of a file
    `cut -f2 sname` --show second column of the file `sname`
* `paste` --put line together
    `paste {file1} {file2}`
* `join` --join lines from separate files. Only works when there exist common column
    `join {file1} {file2}`
* `tr` --translate range of characters into other range of characters

        tr "h2" "3x"
        tr "[a-z]" "[A-Z]
        tr {pattern-1} {pattern-2}
* `awk` --manipulate data
    `awk '/good/{print $1 " " $3}' inventory`
* `sed` --edit on the given stream
    `sed '/tea/s//milk/g' teaormilk` replace tea with milk in the file teaormilk
    `sed {expression} {file}`
* `uniq` --removeing duplicate lines
    `uniq {file-name}`
* `grep` --find matching pattern
    `grep "word-to-find" {file-name}`
* compare:
    1. `grep` - search
    2. `sed`  - edit
    3. `awk`  - analysis & edit
* Process command
    * `killall` + process name
    * `pstree`
* tail/head: output the last part/first part(default 10 lines) of files
    * `head -n num`
* trap --trap signals
    * trap [action condition ...]
    * trap - condition: reset

# 正则表达式
* start `ex` editor
    * `ex {filename}`
* Basic operator
    * print: `1,5 p`
    * delete: `1,5 d`
    * copy: `1,4 co $` -- copy to the end of the file 4. search: `g/linux/ p` -- search linux golal scope
    * find and replace
        * `8 s/learn/learns/` substituting learn to learns in line 8
        * `g/Unix/ s/Unix/Linux` euqal to `g/Unix/ s//Linux`
        * `g/brother/ s/XYZ/also/g` global substituting
        * `g/Linux/ s//UNIX/gc` confirmation from user
        * `g/\<Linux\>/p` match whole word Linux
        * `g/^UNIX` at the begining of the line
        * `/^$` find empty line, `g/^$/d` delete all blank lines
        * `g/[^/^$]` view entire file without blank line, `[^]` not
    * `u` undo what you have done
    * `range of characters`
        * [0123456789] = [0-9]
        * [:alnum:]/[:alpha:]/[:cntrl:]/[:digit:]/[:graph:]/[:lower:]/[:print:]/[:punct:]/[:space:]/[:upper:]/[xdigit:]
    * `1,$ s/Linux/&-Unix/p` -- & mean the last pattern found, and will replace Linux to Linux-Unix
    * Coverting lowercase and uppercase
        * `1,$ s/[a-z]/\u &/g` --`\u` convert to uppercase
        * `1,$ s/[A-Z]/\l &/g` -- `\l` convert to lowercase
