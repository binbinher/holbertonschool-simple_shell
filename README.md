# Simple shell

## Description

This project is a recreation of an UNIX command line interpreter. It was made for Holberton School.
It is able ton handle command given with absolute pathname and also able to handle the PATH variable with arguments and redirections.


## Compilation

It was compiled with the following command:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Requirements

- Ubuntu 20
- GCC 11.4
- Git 2.34.1

## Examples

```
$ ./hsh
(HBTN shell)$ /bin/ls
AUTHORS  README.md  _strcmp.c  exec_cmd.c  find_command_in_path.c  handle_input.c  hsh  main.c  man_1_simple_shell  print_env.c  print_prompt.c  read_command.c  shell.h  tokenize_command.c
(HBTN shell)$ ls -l
total 72
-rw-r--r-- 1 scourge scourge    86 Aug 23 09:31 AUTHORS
-rw-r--r-- 1 scourge scourge   157 Aug 21 14:20 README.md
-rw-r--r-- 1 scourge scourge   414 Aug 23 09:31 _strcmp.c
-rw-r--r-- 1 scourge scourge   579 Aug 23 09:31 exec_cmd.c
-rw-r--r-- 1 scourge scourge   987 Aug 23 09:31 find_command_in_path.c
-rw-r--r-- 1 scourge scourge   638 Aug 23 09:31 handle_input.c
-rwxr-xr-x 1 scourge scourge 17616 Aug 23 12:41 hsh
-rw-r--r-- 1 scourge scourge   868 Aug 23 09:31 main.c
-rw-r--r-- 1 scourge scourge  1881 Aug 23 09:31 man_1_simple_shell
-rw-r--r-- 1 scourge scourge   216 Aug 23 09:31 print_env.c
-rw-r--r-- 1 scourge scourge   197 Aug 23 09:31 print_prompt.c
-rw-r--r-- 1 scourge scourge   545 Aug 23 09:31 read_command.c
-rw-r--r-- 1 scourge scourge   662 Aug 23 09:31 shell.h
-rw-r--r-- 1 scourge scourge   526 Aug 23 09:31 tokenize_command.c
(HBTN shell)$
$ echo "/bin/ls" | ./hsh
AUTHORS  README.md  _strcmp.c  exec_cmd.c  find_command_in_path.c  handle_input.c  hsh  main.c  man_1_simple_shell.1  print_env.c  print_prompt.c  read_command.c  shell.h  tokenize_command.c
$
```

## Man page

You can access the man page using the following command:
```bash
man ./man_1_simple_shell.1
```

## Testing

We tested the program using `valgrind` with the following command:
```bash
valgrind ./hsh
```

## Flowchart

<img title="flowchart" alt="Simple Shell Flowchart" src="/assets/simple_shell_flowchart.svg">

## Authors

#### [Binbin HE](https://github.com/binbinher)
#### [Benoit MARIN](https://github.com/SadScourge)