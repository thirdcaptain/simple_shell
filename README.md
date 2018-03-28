# _printf
The _printf function is a custom implementation of the C programming function printf. It returns the number of characters printed and writes the output to stdout. It includes the conversion specifiers :  c, s, %, d, and i.

## Example
```c
#include "holberton.h"
_printf("The %s jumped %d times! -%c", "dog", 7, 'C');
```
output : The dog jumped 7 times! -C

## Project Requirements
- All files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- Your code should use the Betty style
- You are not allowed to use global variables
- Authorized functions and macros:
  - write (man 2 write)
  - malloc (man 3 malloc)
  - free (man 3 free)
  - va_start (man 3 va_start)
  - va_end (man 3 va_end)
  - va_copy (man 3 va_copy)
  - va_arg (man 3 va_arg)

## File Descriptions
- _printf.c - Returns the number of characters printed and writes output to stdout
- holberton.h - Contains all function prototypes and struct print_list
- _putchar.c - Writes character to stdout
- spec_get.c - Returns the character in the conversion specifier
- print_int.c - Writes the integer given from list, then returns the length of the integer
- printchar.c - Writes the character given from list and returns length of the character
- printstring.c - Iterates through string and writes each character, then returns length of string
- man_3_printf - Manual for custom _printf

### Notes
Our program does not handle buffer handling, flag characters, field width, precision, or length modifiers.

### Authors
Andrew Suh
Lisa Olson
