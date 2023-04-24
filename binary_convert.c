#include "main.h"
/*** PRINT UNSIGNED NUMBER ***/
/**
* print_unt- Prints the unsigned number
* @set: List a of all arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed.
*/
int print_unt(va_list set, char buffer[],
int flags, int width, int precision, int size)
{
int i = 1024 - 2;
unsigned long int num = va_arg(set, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[1024 - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*** PRINT UNSIGNED NUMBER IN OCTAL ***/
/**
* print_oct - Prints an unsigned number in octal notation
* @set: Lista of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_oct(va_list set, char buffer[],
int flags, int width, int precision, int size)
{
int i = 1024 - 2;
unsigned long int num = va_arg(set, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[1024 - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*** PRINT UNSIGNED NUMBER IN HEXADECIMAL ***/
/**
* print_x - Prints an unsigned number in hexadecimal notation
* @set: Lists all of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_x(va_list set, char buffer[],
int flags, int width, int precision, int size)
{
return (print_xd(set, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/*** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
* print_xUpper - Prints an unsigned number in upper hexadecimal notation
* @set: Lists of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_xUpper(va_list set, char buffer[],
int flags, int width, int precision, int size)
{
return (print_xd(set, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/*** PRINT HEXX NUM IN LOWER OR UPPER ***/
/**
* print_xd - Prints a hexadecimal number in lower or upper
* @set: Lista of arguments
* @map_to: Array of values to map the number to
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @flag_ch: Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* @size: Size specification
* Return: Number of chars printed
*/
int print_xd(va_list set, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = 1024 - 2;
unsigned long int num = va_arg(set, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[1024 - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
} i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
