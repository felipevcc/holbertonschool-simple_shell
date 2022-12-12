<div align="center">
  <h1>Simple Shell</h1>
</div>

## Description

Simple Shell is a command line interpreter developed in C language that emulates the most basic functionality of `sh`.

## Man page

The man page is a file wich explains in detail how Simple Shell works. If you want see a full explanation of this function you can run our man page this way:
```
$ man ./man_1_simple_shell
```

## Flowchart

<img height=300 src="https://img.freepik.com/premium-vector/progress-bar-doodle-sketch-style-loading-icon-image-hand-drawn-vector-illustration_356415-1238.jpg?w=2000" alt="flowchart">

## Compilation

To compile the program this command has to be executed:
```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
To run the shell is like this:
```
$ ./hsh
```

## Command list

| Command  | Description |
| -------- |:------------|
| ls       | Will list all files and directories in current working directory |
| cd       | Move between directories |
| pwd      | writes to standard output the full path name of the current directory |
| env      | Displays the current environment |
| exit     | Causes the shell to terminate |

## Usage

The shell can be used in interactive or non-interactive mode.
The interactive mode is how the shell is normally used, the executable file is run and we can write commands, here is an example:

video...

In the non-interactive mode you pass the command to the executable file with a pipe operator, as shown in the following example:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2

$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
```
Here is a video using the non-interactive mode

video...

## Authors

* Charline Mosquera <a href="https://github.com/CharCoder" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
* Felipe Villamizar <a href="https://github.com/felipevcc" rel="nofollow"><img align="center" alt="github" src="https://www.vectorlogo.zone/logos/github/github-tile.svg" height="24" /></a>
