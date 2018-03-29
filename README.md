# Holberton Shell 
The goal for this project was to build a UNIX command line interpreter that can :
- Display a prompt and wait for the user to type a command
- Display a prompt again each time a command has executed
- Handle command line with arguments
- Handle the PATH
- Handle the exit and env built-ins
## File Descriptions
| Filename | Description |
| ------------- |:-------------:|
| main.c | entry point source file |
| getenv.c | searches the environment for a given string |
| _strdup.c | creates a duplicate of a string |
| append.c | appends user input to path environment directory |
| built-in.c | chops newline and executes exit and env built-in functionality |
| fork_execute.c | fork a child and execute the command |
| is_exec.c | checks if file exists |
| print_dir.c | counts the number of directories |
| ret_array.c | counts the number of tokens |
| str_cmp.c | compares two strings |
| header.h | contains function prototypes |
| man_1_simple_shell | manual for the hsh shell |
 
## How to Install
``` git clone git@github.com:thirdcaptain/simple_shell.git ```
 
## How to Compile
``` gcc -Wall -Werror -Wextra -pedantic *.c -o hsh ```

### Built-ins
| Command | Description |
| ------------- |:-------------:|
| env | prints the environment |
| exit | exits with status 0 |
| ctrl-d | exits with status 0 |

### Examples
``` ./hsh  
$ ls -alt  
total 96  
drwxrwxr-x 2 vagrant vagrant  4096 Mar 28 07:18 .  
-rwxrwxr-x 1 vagrant vagrant 14053 Mar 28 00:19 hshs  
-rwxrwxr-x 1 vagrant vagrant 14053 Mar 28 00:18 hsh  
-rw-rw-r-- 1 vagrant vagrant   892 Mar 28 00:17 lishell_4.c  
-rw-rw-r-- 1 vagrant vagrant   638 Mar 27 21:56 header.h  
-rw-rw-r-- 1 vagrant vagrant   947 Mar 27 21:56 print_dir.c  
-rw-rw-r-- 1 vagrant vagrant  1804 Mar 27 21:40 man_1_simple_shell  
-rw-rw-r-- 1 vagrant vagrant   759 Mar 27 20:55 _getenv.c  
-rw-rw-r-- 1 vagrant vagrant     0 Mar 27 20:35 a.out  
-rw-rw-r-- 1 vagrant vagrant   741 Mar 27 20:35 append.c  
-rw-rw-r-- 1 vagrant vagrant   690 Mar 27 20:35 built-in.c  
-rw-rw-r-- 1 vagrant vagrant   588 Mar 27 20:35 fork_execute.c  
-rw-rw-r-- 1 vagrant vagrant   498 Mar 27 20:35 is_exec.c  
-rw-rw-r-- 1 vagrant vagrant   389 Mar 27 20:35 str_cmp.c  
-rw-rw-r-- 1 vagrant vagrant   107 Mar 26 20:57 AUTHORS  
-rw-rw-r-- 1 vagrant vagrant   874 Mar 26 20:29 ret_array.c  
-rw-rw-r-- 1 vagrant vagrant   507 Mar 26 20:27 _strdup.c  
drwxrwxr-x 7 vagrant vagrant  4096 Mar 26 20:23 ..  
-rw-rw-r-- 1 vagrant vagrant   225 Mar 26 20:23 .gitignore  
$ pwd  
/home/vagrant/simple_shell  
$ env  
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin  
TERM=xterm-256color  
SHELL=/bin/bash  
SSH_CLIENT=10.0.2.2 59569 22  
SSH_TTY=/dev/pts/0  
USER=vagrant  
MAIL=/var/mail/vagrant  
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin  
PWD=/home/vagrant/shell_prep/simple_shell/production  
LANG=en_US.UTF-8  
SHLVL=1  
HOME=/home/vagrant  
LOGNAME=vagrant  
SSH_CONNECTION=10.0.2.2 59569 10.0.2.15 22  
XDG_RUNTIME_DIR=/run/user/1000  
_=./hsh  
OLDPWD=/home/vagrant/shell_prep/simple_shell  
$ exit  
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$
```

#### Notes
Our hsh shell does not account for updates to the environment, conditional expressions, command expansion, arithmetic evaluation, functions, aliases, redirection, or parameters.

#### Authors
Isaac Wong, Lisa Olson
