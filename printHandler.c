#include "main.h"
/**
* printHandler - Prints an argument based on its type
* @fmt: Formatted string in which to print the arguments.
* @file: List of arguments to be printed.
* @ind: ind.
* @buffer: Buffer array to handle print.
* @flags: Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: 1 or 2;
*/
int printHandler(const char *fmt, int *ind, va_list file, char buffer[],
int flags, int width, int precision, int size)
{
int k, unknow_len = 0, output_chars = -1;
fmt_t fmt_set[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'k', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unt}, {'o', print_oct}, {'x', print_x},
{'X', print_xUpper}, {'p', print_ptr}, {'S', print_legible},
{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
};
for (k = 0; fmt_set[k].fmt != '\0'; k++)
if (fmt[*ind] == fmt_set[k].fmt)
return (fmt_set[k].fn(file, buffer, flags, width, precision, size));
if (fmt_set[k].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}
return (output_chars);
}
