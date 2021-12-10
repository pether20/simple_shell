<h1 align="center" >
<br>
    <img src="https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg" height="50%" width="40%">
</h1>

<h2 align="center">


# Project 0x16. C - SIMPLE SHELL 📚

### Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General

* Who designed and implemented the original Unix operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language (the direct predecessor to the C programming language)
* Who is Ken Thompson
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?




### 📋 Requirements
***
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

### GitHub
There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

 ## Files Contained on this repository

| File | Description |
|--|--|
| **AUTHORS** | Contains the authors of the Simple Shell program. |
| **README.md** | Contains an overview of Simple Shell. Important things that you should know before executes our Simple Shell program. |
| **main.c** | simple shell program that 1) checks if in interactice/noninteractice mode 2) prints prompt and waits for user input 3) splits user input into an array 4) prints prompt again if in interactice mode.
| **man_1_simple_shell** | man page for our shell. |
| **shell.h** | header file containing function prototypes, struct definitions, macros, standard libraries |
| **shell.c** ||
    

Compilation
Your shell will be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Testing

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### List of comands you can use

| Commands | Description |
|--|--|
| `ls` | ls (from list), allows you to list the contents of a directory or file. |
| `pwd` | Pwd (from print working directory) is a convenient command that prints our path or location when executed, so we avoid getting lost if we are working with multiple directories and folders. |
| `touch` | touch creates an empty file, if the file exists it updates the modification time. |
| `rm` | rm (from remove) is the command needed to delete a file or directory. |
| `mkdir` | mkdir (from make directory) creates a new directory taking into account the current location. |
| `cp` | cp (from copy) copies a source file or directory to a target fileor directory. |
| `rmdir` | rmdir (from ReMove DIRectory) This command is used to delete empty directories or subdirectories. |
| `cd` | cd (from change directory) you will need this command to access a path other than the one you are in. basically it is for navigating from directory to directory. |
| `exit` | exits the current shell. 0 status value indicates successful execution, another value represents unsuccessful execution. |
| `cat` | cat (from concatenate), is a wonderful utility that allows us to visualize the content of a text file in the standard output, without the need of an editor. |

   <p align="center">
Pether Tejada -
<a href="https://github.com/pether20">
        <img src="https://img.shields.io/badge/Pether-mainPage-blue">
</a>
</p>



<p align="center">
Edgar Condo -
<a href="https://github.com/EdgaWill">
        <img src="https://img.shields.io/badge/Edgar-mainPage-blue">
</a>
</p>
