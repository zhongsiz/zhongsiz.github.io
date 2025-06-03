---
layout: note
title: GNU Sed
---

~~~
# replace name with steve in the file intro.md
sed 's/name/steve/g' intro.md
~~~

# Useful Resource
* [sed Introduction and Tutorial](http://www.grymoire.com/Unix/Sed.html#uh-40)
* [sed Home Page](https://www.gnu.org/software/sed/manual/sed.html)
* [sed Regular Expression](https://www.gnu.org/software/sed/manual/sed.html#Regular-Expressions)

# Basic Syntax
* Syntax:

        sed -option 'general expression' [data-file]
        sed -option sed-script-file [data-file]

    Option

    * -e : read sed command from command line
        * Used to run multiple commands

                sed --expression='s/a/A/' --expression='s/b/B/'
    * -f : from sed script file
        * A sample script file

                s/a/A/g
                s/b/B/g
                s/c/C/g
    * -n : suppress the ouput of sed command, must use **p** command print flag
    * -i(--in-place) : in place edit, save result to the file

    Block -- {...}

        sed -n /begin/,/end/ { sed command }
* Command
    * Substitution -- **s/.../.../**
    * Delete -- **d**
        * `sed '1,/^$/ d` -- delete until the first no blank line
    * Change -- **c \\**
        * `sed '/WORD/ c\Replace text'` -- change line contains WORD
    * Append -- **a \\**
* Regular expression
    * Pattern flag
        * **/g** -- global
        * **/I** -- ignore case
        * **/p** -- print
        * **/w** -- write filename
    * Match times
        * \* -- zero or more
        * \+ -- one or more time
        * \{n\} -- search pattern n times
        * \{n,\} -- equal to or more than n times
        * \{n,m\} -- match any number of occurrence between n and m

                # find line between `***` and `***` and delete all those lines
                sed -e '/^\*\{3\}$/, /^\*\{3\}$/d' demofile2 > /tmp/fi.$$
    * Pattern
        * . -- any character include newline
        * \(regexp\) -- much as a whole
        * \[list\] \[^list\] -- any single character (not) in the list
    * Position
        * ^ -- begin
        * $ -- end
    * Matched string -- `&`

            # substitution alphabet with parenthess surround
            sed 's/[a-z]*/(&)/'
