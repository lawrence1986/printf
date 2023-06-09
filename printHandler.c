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
int i = 0, unknow_len = 0, output_chars = -1;
fmt_t fmt_set[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unt}, {'o', print_oct}, {'x', print_x},
{'X', print_xUpper}, {'p', print_ptr}, {'S', print_legible},
{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
};

while (fmt_set[i].fmt != '\0')
{
if (fmt[*ind] == fmt_set[i].fmt)
	return (fmt_set[i].fn(file, buffer, flags, width, precision, size));
i++;
}
if (fmt_set[i].fmt == '\0')
{
if (fmt[*ind] == '\0')
	return (-1);
unknow_len += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
	unknow_len += write(1, " ", 1);
else if (width)
{
--(*ind);
for (; fmt[*ind] != ' ' && fmt[*ind] != '%'; --(*ind))
	;
if (fmt[*ind] == ' ')
	--(*ind);
return (1);
}
unknow_len += write(1, &fmt[*ind], 1);
return (unknow_len);
}
return (output_chars);
}
